#include <windows.h>
#include <iostream>
#include <string>
#include <thread>  //  Header file required to use threads

// Function prints message passed by r-value reference
void foo(std::string &&val)
{
    std::cout << val << std::endl; 
}

int main()
{
    /*  std:: thread is the class represents a single thread execution.
        Threads allow multiple functions to execute concurrently. (Not necessary parallel)
        Threads begin execution immediately upon the construction of the associated thread object (pending any OS scheduling delaus.), starting at top-level function provided as a constructor argument. 
    */   
   //   Create a thread and run execution of passed to the constructor lambda function.
    auto thread_1 = std::thread([]{std::cout << "Thread 1\n";});
    auto thread_2 = std::thread(foo, "Thread 2\n");
    
    /*  yield() Provides a hint to the implementation to reschedule the execution of threads, allowing other threads to run.
    */
    std::this_thread::yield();
    std::cout << "main thread\n";
    
    /*  join() method of the Thread class, blocks the current thread until the thread identified by *this            finishes.
        The completion of the thread identified by *this synchronizes with the corresponding successful return from join().
    */
    thread_1.join();
    thread_2.join();

    system("pause");
    return 0;
}