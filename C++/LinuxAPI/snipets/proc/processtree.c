#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <memory.h>
#include <stdbool.h>

#define BUFFER 128

char *getCommand(char *info)
{
    char *position = strstr(info, "Name:");
    if (position == NULL) return NULL;
    char copy[strlen(position)];
    strcpy(copy, position);
    int size = abs((strlen(strstr(copy + 5, "\n")) - strlen(copy + 5)));
    char *command = malloc(size + 1);
    memcpy(command, copy + 5, size);
    return command;
}

char *getPPid(const char *info)
{
    char *position = strstr(info, "PPid:");
    if (position == NULL) return NULL;
    char copy[strlen(position)];
    strcpy(copy, position);
    int size = abs((strlen(strstr(copy + 5, "\n")) - strlen(copy + 5)));
    char *ppid = malloc(size);
    memcpy(ppid, copy + 5, size);
    return ppid;
}

char *getPid(const char *info)
{
    char *position = strstr(info, "Pid:");
    if (position == NULL) return NULL;
    char copy[strlen(position)];
    strcpy(copy, position);
    int size = abs((strlen(strstr(copy + 5, "\n")) - strlen(copy + 4)));
    char *pid = malloc(size);
    memcpy(pid, copy + 4, size);
    return pid;
}

void showTree(char *file, int indent)
{
    if (!file) return;
    char *space = malloc(indent);
    memset(space, '.', indent);
    char path[50] = "/proc/";
    strcat(path, file + 1);
    strcat(path, "/status");
    int fd = open(path, O_RDONLY);
    char fileInfo[BUFFER];
    read(fd, fileInfo, BUFFER);

    if (strcmp(file + 1, "1") == 0) {
        char *pid = getPid(fileInfo);
        char *command = getCommand(fileInfo);
        printf("%s %s %s\n", space, pid, command);
        free(space);
        close(fd);
        return;
    }else{
        char *ppid = getPPid(fileInfo);
        showTree(ppid, indent += 1);
        char *pid = getPid(fileInfo);
        char *command = getCommand(fileInfo);
        printf("%s %s %s\n", space, pid, command);
        free(space);
    }
}


void readFile(int fd)
{
    char fileInfo[BUFFER];
    read(fd, fileInfo, BUFFER);
    char *pid = getPid(fileInfo);
    showTree(pid, 1);
    free(pid);
    close(fd);
}

int main(void)
{
    struct dirent *dir;
    DIR *pDir = opendir("/proc/");
    if (pDir == NULL) {
        printf("opendir error\n");
        exit(EXIT_FAILURE);
    }
    for (;;) {
        dir = readdir(pDir);
        if (dir == NULL) {
            printf("readdir error\n");
            break;
        }
        char path[50] = "/proc/";
        strcat(path, dir->d_name);
        strcat(path, "/status");
        int fd = open(path, O_RDONLY);
        readFile(fd);
    }

    return 0;
}
