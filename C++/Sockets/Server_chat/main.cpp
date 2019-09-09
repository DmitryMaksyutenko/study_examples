#include "Server.h"

int main()
{
    Server serv;

    try
    {
        serv.BuildServer();
        std::cout << "server IP: " << serv.GetIp() << std::endl;
        serv.Runserver();
        serv.CloseServer();
    }
    catch(std::exception &ex)
    {
        std::cerr << ex.what();
    }

    return 0;
}