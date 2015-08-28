#include <nn.hpp>
#include <nanomsg/pubsub.h>
#include <nanomsg/pair.h>

#include "../common/nanomsg_cancellation_token.h"
#include "../common/system_info.h"

#include <thread>
#include <chrono>
#include <sole.hpp>
#include <string>
#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
    auto token = std::make_shared<nanomsg_cancellation_token>();

    token->wait_on_new_thread();

    auto uuid_string = sole::uuid0().base62();
    auto host_name = hostname();

    // configure the publisher socket
    nn::socket s1(AF_SP, NN_PUB);

    if (argc == 1) {
        std::cout << uuid_string << " " << host_name << " (worker) -> " << "tcp://*:7777" << std::endl;
        s1.bind("tcp://*:7777");
    }
    else {
        std::cout << uuid_string << " " << host_name << " (worker) -> " << argv[1] << std::endl;
        s1.bind(argv[1]);
    }

    // publish heartbeats
    int i = 0;
    try {
        while (!token->cancelled()) {
            std::string message(uuid_string);
            message += " " + host_name + ": " + std::to_string(i++);
            s1.send(message.c_str(), message.size() + 1, 0);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    catch (std::exception& e) {
        std::cout << host_name << " aborted: " << e.what() << std::endl;
    }

    std::cout << uuid_string << " " << host_name << " (worker) -> stopped via kill socket" << std::endl;
}
