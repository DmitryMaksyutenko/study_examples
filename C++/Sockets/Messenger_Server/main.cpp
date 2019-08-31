#include <chrono>

#include "Server.h"

void timer()
{
    auto start = std::chrono::system_clock::now();

    while(true)
    {
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> result = now - start;
        double sec = result.count();
        if ((int)sec % 5 == 0)
        {
            std::cout << "server uptime : " << (int)sec << " second\n";
        }
    }
}

int main()
{
    Server srv;

    try
    {
        srv.RunServer();
        timer();
    }
    catch(std::exception ex)
    {
        std::cout << ex.what();
    }

    return 0;
}
