#include <nn.hpp>
#include <nanomsg/pubsub.h>
#include <nanomsg/pair.h>

#include "../common/nanomsg_cancellation_token.h"

#include <iostream>
#include <sole.hpp>
#include <string>



int main(int argc, char* argv[]) {
    auto token = std::make_shared<nanomsg_cancellation_token>();
    token->wait_on_new_thread();

    auto uuid_string = sole::uuid0().base62();

    // configure the subscriber socket
    nn::socket s2(AF_SP, NN_SUB);

    if (argc == 1) {
        std::cout << uuid_string << " (server): connecting to: " << "tcp://localhost:7777" << std::endl;
        s2.connect("tcp://localhost:7777");
    }
    else {
        for (int i = 1; i < argc; i++) {
            std::cout << uuid_string << " (server): connecting to: " << argv[i] << std::endl;
            s2.connect(argv[i]);
        }
    }

    s2.setsockopt(NN_SUB, NN_SUB_SUBSCRIBE, "", 0);

    // receive heartbeats from all peers
    char buf[128];
    try {
        while (!token->cancelled()) {
            if (s2.recv(buf, sizeof(buf), 0) >= 0) {
                std::cout << uuid_string << " <- " << buf << std::endl;
            }
        }
    } catch (std::exception& e) {
        std::cout << uuid_string << " aborted: " << e.what() <<std::endl;
    }
}
