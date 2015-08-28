#include <nn.hpp>
#include <nanomsg/pubsub.h>

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "stop_all: stopping everybody" << std::endl;

    nn::socket kill_pub(AF_SP, NN_PUB);
    kill_pub.bind("tcp://*:5556");

    for (auto i = 0; i < 2; i++) {
        kill_pub.send("", 0, 0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
