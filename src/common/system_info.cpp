#include "system_info.h"

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
