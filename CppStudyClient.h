#define _HAS_STD_BYTE 0
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <winsock2.h>
#include <string_view>
#pragma comment(lib, "ws2_32.lib")


bool Send_Code(std::string_view address_,std::wstring_view strSourceCode_,std::wstring_view strName_)
{
    WSADATA wsaData;
    SOCKET s;
    sockaddr_in server;
    const std::string server_ip = address_.data();
    const int server_port = 65432;             

    
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "Failed to initialize socket. Error: " << WSAGetLastError() << std::endl;
        return false;
    }

   
    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s == INVALID_SOCKET)
    {
        std::cerr << "Failed to create socket. Error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip.c_str());
    server.sin_port = htons(server_port);

   
    if (connect(s, (sockaddr*)&server, sizeof(server)) < 0)
    {
        std::cerr << "Connection error." << std::endl;
        closesocket(s);
        WSACleanup();
        return false;
    }

    std::wifstream in{ strSourceCode_.data() };

    if (!in.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
        closesocket(s);
        WSACleanup();
        return false;
    }

    std::wstring fileContent{ (std::istreambuf_iterator<wchar_t>(in)), std::istreambuf_iterator<wchar_t>() };
    fileContent += L"\n//" + std::wstring{ strName_ };

    if (send(s, reinterpret_cast<const char*>(fileContent.data()), (int)(fileContent.size() * sizeof(wchar_t)), 0) < 0)
    {
        std::cerr << "Send failed." << std::endl;
        closesocket(s);
        WSACleanup();
        return false;
    }

    closesocket(s);
    WSACleanup();

    return true;
}


