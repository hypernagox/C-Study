#define _HAS_STD_BYTE 0
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string_view>
#include <sstream>
#pragma comment(lib, "ws2_32.lib")

bool isIPv4(std::string_view address)
{
    std::istringstream iss(static_cast<std::string>(address));
    std::string segment;
    int segmentsCount = 0;

    while (std::getline(iss, segment, '.'))
    {
        ++segmentsCount;

        if (segmentsCount > 4) 
        {
            return false;
        }

        try
        {
            int value = std::stoi(segment);

            if (value < 0 || value > 255)
            {
                return false;
            }

            if (segment.length() > 1 && segment[0] == '0')
            {
                return false;
            }
        }
        catch (const std::exception&)
        {
            return false;
        }
    }

    return segmentsCount == 4 && iss.eof();
}

std::string convertIPv4toIPv6(std::string_view ipv4)
{
    return std::string{ "::ffff:" } + ipv4.data();
}

std::string getLocalIP()
{
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));

    ADDRINFO hints, * result;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;  
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int iResult = getaddrinfo(hostname, NULL, &hints, &result);
    if (iResult != 0)
    {
        return "Error!";
    }

    char ipstringbuffer[46]; 
    DWORD ipbufferlength = sizeof(ipstringbuffer);
    for (ADDRINFO* ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        if (ptr->ai_family == AF_INET)
        {
            sockaddr_in* sockaddr_ipv4 = (sockaddr_in*)ptr->ai_addr;
            InetNtopA(AF_INET, &sockaddr_ipv4->sin_addr, ipstringbuffer, ipbufferlength);
            freeaddrinfo(result);
            return ipstringbuffer;
        }
        else if (ptr->ai_family == AF_INET6)
        {
            sockaddr_in6* sockaddr_ipv6 = (sockaddr_in6*)ptr->ai_addr;
            InetNtopA(AF_INET6, &sockaddr_ipv6->sin6_addr, ipstringbuffer, ipbufferlength);
            freeaddrinfo(result);
            return ipstringbuffer;
        }
    }

    freeaddrinfo(result);
    return "Error!";
}

bool Send_Code(std::wstring_view strSourceCode_,std::wstring_view strName_,std::string address_ = "")
{
    WSADATA wsaData;
    SOCKET s;
    sockaddr_in6 server; 
    const int server_port = 65432;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "Failed to initialize socket. Error: " << WSAGetLastError() << std::endl;
        return false;
    }

    s = socket(AF_INET6, SOCK_STREAM, 0); 

    if (s == INVALID_SOCKET)
    {
        std::cerr << "Failed to create socket. Error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }
    
    if (address_.empty())
    {
        address_ = getLocalIP();
    }

    const std::string server_ip = isIPv4(address_) ? convertIPv4toIPv6(address_) : address_.data();
    ZeroMemory(&server, sizeof(server));
    server.sin6_family = AF_INET6;
    inet_pton(AF_INET6, server_ip.data(), &(server.sin6_addr));
    server.sin6_port = htons(server_port);

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

    if (send(s, reinterpret_cast<const char*>(strName_.data()), (int)(strName_.size() * sizeof(wchar_t)), 0) < 0)
    {
        std::cerr << "Send failed." << std::endl;
        closesocket(s);
        WSACleanup();
        return false;
    }

    const std::wstring fileContent{ (std::istreambuf_iterator<wchar_t>(in)), std::istreambuf_iterator<wchar_t>() };
   
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


