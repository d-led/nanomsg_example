#pragma once

#include "cancellation_token.h"

#include <nn.hpp>
#include <nanomsg/pubsub.h>

class nanomsg_cancellation_token {
    cancellation_token token;
    nn::socket sub;

    inline void connect() {
        sub.connect("tcp://localhost:5556");
        sub.setsockopt(NN_SUB, NN_SUB_SUBSCRIBE, "", 0);
    }

public:
    inline nanomsg_cancellation_token() :
        sub(AF_SP, NN_SUB)
    {
        connect();
    }

public:
    // should be thread safe based on nanomsg sockets
    inline void wait() {
        char buf[2];
        while (!token.cancelled()) {
            if (sub.recv(buf, sizeof(buf), 0) >= 0) {
                token.cancel();
            }
        }
    }

    inline bool cancelled() const {
        return token.cancelled();
    }
};
