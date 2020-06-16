#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

void openFd(char *path, char *name)
{
    char buf[1024];
    int len;
    char new_path[50] = {};
    strcat(new_path, path);
    strcat(new_path, "/fd");
    struct dirent *dir;
    DIR *pDir = opendir(new_path);
    if (pDir == NULL) return;
    do {
        dir = readdir(pDir);
        if (dir == NULL) break;
        char tmp_path[50] = {};
        strcat(tmp_path, new_path);
        strcat(tmp_path, "/");
        strcat(tmp_path, dir->d_name);
        len = readlink(tmp_path, buf, sizeof(buf) - 1);
        if (len == -1) continue;
        if (strstr(buf, name)) {
            printf("Process name: %s\n", path);
            break;
        }
    }while(dir != NULL);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Specify the file name.\n");
        exit(EXIT_FAILURE);
    }
    printf("File name: %s\n", argv[1]);

    struct dirent *dir;
    DIR *pDir = opendir("/proc/");
    if (pDir == NULL) {
        printf("opendir failed\n");
        exit(EXIT_FAILURE);
    }

    do {
        dir = readdir(pDir);
        if (dir == NULL) {
            break;
        }
        char path[50] = "/proc/";
        strcat(path, dir->d_name);
        openFd(path, argv[1]);
    }while(dir != NULL);

    return EXIT_SUCCESS;
}

