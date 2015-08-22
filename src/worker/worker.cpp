#include <nn.hpp>
#include <nanomsg/pubsub.h>
#include <nanomsg/pair.h>

#include <thread>
#include <chrono>
#include <sole.hpp>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    bool running = true;
    nn::socket s1(AF_SP, NN_PUB);

    auto uuid = sole::uuid0();
    auto uuid_string = uuid.base62();

    if (argc == 1) {
        std::cout << uuid_string << " (worker) -> " << "tcp://*:7777" << std::endl;
        s1.bind("tcp://*:7777");
    }
    else {
        std::cout << uuid_string << " (worker) -> " << argv[1] << std::endl;
        s1.bind(argv[1]);
    }

    int i = 0;
    while (running) {
        std::string message(uuid_string);
        message += ": " + std::to_string(i++);
        s1.send(message.c_str(), message.size() + 1, 0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
