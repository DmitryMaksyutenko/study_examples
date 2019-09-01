#include <chrono>
#include <thread>

#include "Server.h"

void timer()
{
    auto start = std::chrono::system_clock::now();
    bool flag = true;

    while(true)
    {
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> result = now - start;
        double sec = result.count();
        if ((int)sec % 5 == 0 && flag == true)
        {
            std::cout << "server uptime : " << (int)sec << " second\n";
            flag = false;
        }
        if ((int)sec % 5 == 1)
            flag = true;
    }
}

int main()
{
    Server srv;

    try
    {
        srv.RunServer();
        std::thread timer_thread(timer);
        timer_thread.detach(); // This thread is free

        Sleep(100);
        std::cout << "server IP: " << srv.GetServerIP() << std::endl;
        std::cout << "clients on server : " << srv.GetClientsCount() << std::endl;
    }
    catch(std::exception ex)
    {
        std::cout << ex.what();
    }

    return 0;
}
