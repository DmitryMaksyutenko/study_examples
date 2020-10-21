#include <unistd.h>
#include <iostream>


int main(int argc, char **argv)
{
    execve("./test.py", argv, nullptr);

    // If execve() system call is successful, the rest of the program will not execute.
    std::cout << "The main process.\n";
    return 0;
}
