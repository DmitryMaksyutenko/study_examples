#include <windows.h>
#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex> // Header file required to use mutex
 
std::map<std::string, std::string> pages;
/*  The mutex class is a synchronization primitive 
    that can be used to protect shared data from being simultaneously accessed by multiple threads.
*/
std::mutex _mutex;
 
void save_page(const std::string &url)
{
    std::string result = "some value";
 
 /* The class lock_guard is a mutex wrapper that provides a convenient 
 RAII-style "https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization" mechanism for owning a mutex 
 for the duration of a scoped block.
 When a lock_guard object is created, it attempts to take ownership of the mutex it is given. 
 When control leaves the scope in which the lock_guard object was created, 
 the lock_guard is destructed and the mutex is released.
 */
    std::lock_guard<std::mutex> guard(_mutex);
    pages[url] = result;
}
 
int main() 
{
    std::thread t1(save_page, "key one");
    std::thread t2(save_page, "key two");
    t1.join();
    t2.join();
 
    for (const auto &pair : pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }

    system("pause");
}