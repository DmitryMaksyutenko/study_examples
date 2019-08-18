#include <windows.h>
#include <iostream>
#include <thread>
#include <mutex>

#include "data_race.h"

// Deadlock simulation
std::mutex mut1;
std::mutex mut2;

void foo()
{
    std::lock_guard<std::mutex> g1(mut1);
    std::cout << "foo -------->\n";
    std::lock_guard<std::mutex> g2(mut2);
}

void doo()
{
    std::lock_guard<std::mutex> g1(mut1);
    std::cout << "doo -------->\n";
    std::lock_guard<std::mutex> g2(mut2);
}

int main()
{
    //  Data-race, race condition.
    Storage storage;

    auto t1 = std::thread(&Storage::SetContent, std::ref(storage), 100);
    auto t2 = std::thread(&Storage::SetContent, std::ref(storage), 200);

    t1.join();
    t2.join();

    std::cout << "Content = " << storage.GetContent() << std::endl;

    auto t3 = std::thread(foo);
    auto t4 = std::thread(doo);

    t3.join();
    t4.join();

    std::cout << "this string will print, if there no deadlocks\n";

    system("pause");
    return 0;
}