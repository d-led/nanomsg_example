#include <nn.hpp>
#include <nanomsg/pubsub.h>
#include <nanomsg/pair.h>

#include "../common/nanomsg_cancellation_token.h"

#include <thread>
#include <chrono>
#include <sole.hpp>
#include <string>
#include <iostream>

namespace {

// somewhat simplistic
#ifdef _MSC_VER
// https://msdn.microsoft.com/en-us/library/windows/desktop/ms738527(v=vs.85).aspx
#pragma comment(lib, "Ws2_32.lib")
#include<Winsock2.h>
    std::string hostname() {
        char path[128] = "";
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);
        gethostname(path, sizeof(path));
        printf("%s", path);
        WSACleanup();
        return std::string(path);
    }
#else
#include <unistd.h>
// http://man7.org/linux/man-pages/man2/gethostname.2.html
    std::string hostname() {
        char path[128] = "";
        gethostname(path, sizeof(path));
        return std::string(path);
    }
#endif
}

int main(int argc, char* argv[]) {
    nanomsg_cancellation_token token;
    nn::socket s1(AF_SP, NN_PUB);

    std::thread([&token]{ token.wait(); }).detach();

    auto uuid = sole::uuid0();
    auto uuid_string = uuid.base62();
    auto host_name = hostname();

    if (argc == 1) {
        std::cout << uuid_string << " " << host_name << " (worker) -> " << "tcp://*:7777" << std::endl;
        s1.bind("tcp://*:7777");
    }
    else {
        std::cout << uuid_string << " " << host_name << " (worker) -> " << argv[1] << std::endl;
        s1.bind(argv[1]);
    }

    int i = 0;
    while (!token.cancelled()) {
        std::string message(uuid_string);
        message += " " + uuid_string + ": " + std::to_string(i++);
        s1.send(message.c_str(), message.size() + 1, 0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << uuid_string << " " << host_name << " (worker) -> stopped via kill socket" << std::endl;
}
