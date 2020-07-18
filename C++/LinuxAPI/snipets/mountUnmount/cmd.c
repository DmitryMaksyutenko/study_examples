#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

#include "cmd.h"

struct DirInfo* getCmdParams(int argc, char **argv)
{
    struct DirInfo *dirInfo;

    if (argc == 1) {
        printf("Provide two arguments for command line (filenum dirname).\n");
        exit(EXIT_FAILURE);
    } else if (argc == 2) {
        printf("Provide two arguments for command line (filenum dirname).\n");
        exit(EXIT_FAILURE);
    } else if (argc > 3) {
        printf("Provide two arguments for command line (filenum dirname).\n");
        exit(EXIT_FAILURE);
    } else {
        dirInfo = malloc(sizeof(struct DirInfo));
        dirInfo->filecount = atoi(argv[1]);
        dirInfo->dirName = malloc(strlen(argv[2]) + 1);
        memcpy(dirInfo->dirName, argv[2], strlen(argv[2]) + 1);
    }

    return dirInfo;
}
