#include "show_process_info.h"
#include "write_file.h"
#include "src/error_functions.h"

int main(int argc, char **argv)
{
    if(argc < 3 || argc > 4)
        errExit("Incorrect arguments count\n");

    char *fileName = argv[1];
    int bytesCount = atoi(argv[2]);

    showProcessInfo();

    write_file(argc, fileName, bytesCount);

    return 0;
}