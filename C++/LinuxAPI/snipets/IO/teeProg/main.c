#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* setName(char *file, char *name)
{
    file = malloc(strlen(name) + strlen(".txt"));
    strcpy(file, name);
    strcat(file, ".txt");
    return file;
}

void writeFile(int fd)
{
    int size = 1024;
    char buffer[size + 1];

    while(read(STDIN_FILENO, buffer, size) != 0)
    {
        printf("%s", buffer);
        write(fd, buffer, strlen(buffer));
        memset(buffer, 0, size);
    }
}

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("application reaquire params:\n");
        printf("%s -a<append> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    bool isAppend = false;
    int fd;
    char *fileName;

    if(argc == 2)
    {
        if(strcmp(argv[1], "-a") == 0)
        {
            printf("application reaquire file name:\n");
            printf("%s -a<append> <filename>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            fileName = setName(fileName, argv[1]);
            fd = open(fileName,
                        O_CREAT | O_WRONLY| O_TRUNC ,
                        S_IRUSR | S_IWUSR | S_IWGRP);

            writeFile(fd);

            free(fileName);
            close(fd);
            exit(EXIT_SUCCESS);
        }
    }

    if(argc == 3)
    {
        if(strcmp(argv[1],"-a") == 0)
            fileName = setName(fileName, argv[2]);
        else
            fileName = setName(fileName, argv[1]);

        fd = open(fileName,
                    O_CREAT | O_WRONLY | O_APPEND,
                    S_IRUSR | S_IWUSR | S_IWGRP);

        writeFile(fd);

        free(fileName);
        close(fd);
        exit(EXIT_SUCCESS);
    }

    exit(EXIT_SUCCESS);
}