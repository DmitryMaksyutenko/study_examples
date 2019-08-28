#include "Client.h"

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#pragma comment(lib, "AdvApi32.lib")

int __cdecl main(int argc, char **argv)
{
    if (argc !=2 )
    {
        std::cout << "failed " << argv[0] << std::endl;
        return 1;
    }

    Client client;

    if (!client.WinsockInit())
        return 1;
    if (!client.ResolveAddrPort(argv))
        return 1;
    if (!client.Connect())
        return 1;
    if (!client.MessSend())
        return 1;
    if (!client.ShotDown())
        return 1;
    client.Receive();
    
    return 0;
}