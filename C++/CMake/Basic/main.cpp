#include <iostream>

#include <config.h>


int main(int argc, char **argv)
{
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version "
                  << baseapp_VERSION_MAJOR << "."
                  << baseapp_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    std::cout << "Hello World!\n";

    return 0;
}
