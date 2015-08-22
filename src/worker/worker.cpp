#include <nn.hpp>
#include <nanomsg/pubsub.h>
#include <nanomsg/pair.h>

#include <thread>
#include <chrono>
#include <sole.hpp>
#include <string>

int main() {
    bool running = true;
    nn::socket s1(AF_SP, NN_PUB);
    s1.bind("tcp://*:7777");
    auto uuid = sole::uuid0();
    auto uuid_string = uuid.base62();
    int i = 0;
    while (running) {
        std::string message(uuid_string);
        message += ": " + std::to_string(i++);
        s1.send(message.c_str(), message.size() + 1, 0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
