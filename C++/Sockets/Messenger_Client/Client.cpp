#include "Client.h"

Client::Client() : iResult(NULL), client_socket(INVALID_SOCKET),
                    result(NULL), ptr(NULL)
{
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
}

void Client::BuildClient()
{
    iResult = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (iResult != 0)
        throw std::exception("WSAStartup failed\n");

    std::string port;
    std::string addres;
    
    std::cout << "enter IP: ";
    std::cin >> addres;
    std::cout << std::endl;
    std::cout << "enter port: ";
    std::cin >> port;
    std::cout << std::endl;

    iResult = getaddrinfo(addres.c_str(), port.c_str(), &hints, &result);
    if (iResult != 0)
    {
        WSACleanup();
        throw std::exception("getaddrinfo failed\n");
    }

    for (ptr = result; ptr != NULL; ptr->ai_next)
    {
        client_socket = socket(ptr->ai_family, ptr->ai_socktype, (int)ptr->ai_protocol);
        if (client_socket == INVALID_SOCKET)
        {
            WSACleanup();
            throw std::exception("socket failed\n");
        }

        iResult = connect(client_socket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR )
        {
            closesocket(client_socket);
            client_socket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);
    SendMessage();
}

void Client::SendMessage()
{
    std::string mess;
    std::cout << "enter message : ";
    std:: cin >> mess;

    if (client_socket == INVALID_SOCKET)
    {
        WSACleanup();
        throw std::exception("INVALID SOCKET\n");
    }

        iResult = send(client_socket, mess.c_str(), mess.size(), 0);
    if (iResult == SOCKET_ERROR)
    {
        closesocket(client_socket);
        WSACleanup();
        throw std::exception("send failed\n");
    }
}