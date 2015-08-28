#pragma once

#include "cancellation_token.h"

#include <nn.hpp>
#include <nanomsg/pubsub.h>
#include <nanomsg/nn.h>
#include <memory>
#include <thread>

class nanomsg_cancellation_token : public std::enable_shared_from_this<nanomsg_cancellation_token> {
    std::thread waiter;
    cancellation_token token;
    nn::socket sub;

    inline void connect() {
        sub.connect("tcp://localhost:5556");
        sub.setsockopt(NN_SUB, NN_SUB_SUBSCRIBE, "", 0);
    }

    // should be thread safe based on nanomsg sockets
    inline void wait() {
        char buf[2];
        while (!token.cancelled()) {
            if (sub.recv(buf, sizeof(buf), 0) >= 0) {
                token.cancel();
                nn_term(); // would produce error or all recv
            }
        }
    }

public:
    inline nanomsg_cancellation_token() :
        sub(AF_SP, NN_SUB)
    {
        connect();
    }

public:
    void wait_on_new_thread() {
        auto capture = shared_from_this();
        std::thread([capture] {
            capture->wait();
        }).detach();
    }

    inline bool cancelled() const {
        return token.cancelled();
    }
};
