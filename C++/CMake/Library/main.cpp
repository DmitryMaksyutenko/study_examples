#include <iostream>
#include "config.h"

#ifdef MYLIB

#include "mylib.h"

#endif

int main(int argc, char **argv)
{
    std::cout << helloFunction();

    return 0;
}
