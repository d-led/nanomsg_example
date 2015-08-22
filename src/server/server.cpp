#include <nn.hpp>
#include <nanomsg/pubsub.h>
#include <nanomsg/pair.h>

#include <iostream>
#include <sole.hpp>
#include <string>

int main() {
    bool running = true;
    nn::socket s2(AF_SP, NN_SUB);
    s2.connect("tcp://localhost:7777");
    s2.setsockopt(NN_SUB, NN_SUB_SUBSCRIBE, "", 0);
    char buf[128];
    auto uuid = sole::uuid0();
    auto uuid_string = uuid.base62();

    while (running) {
        if (s2.recv(buf, sizeof(buf), 0) >= 0) {
            std::cout << uuid_string << " <- " << buf << std::endl;
        }
    }
}
