#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFF_SIZE 128

uid_t getUidByName(const char *name)
{
    struct passwd *pwd = getpwnam(name);
    if (pwd == NULL)
        return 0;

    return pwd->pw_uid;
}

void showInfo(char *proc, uid_t uid)
{
    char uid_str[48];
    sprintf(uid_str, "%d", uid);
    if (strstr(proc, uid_str)) {
        char *posName = strstr(proc, "Name:");
        char *posPid = strstr(proc, "Pid:");
        int nameLen = abs((strlen(strstr(posName, "\n")) - strlen(posName)));
        int pidLen = abs((strlen(strstr(posPid, "\n")) - strlen(posPid)));
        char name[nameLen];
        char pid[pidLen];
        memcpy(name, posName, nameLen);
        memcpy(pid, posPid, pidLen);
        name[nameLen] = '\0';
        pid[pidLen] = '\0';
        printf("%s\n", name);
        printf("%s\n", pid);
    }
}

void getInfo(const char *f, uid_t uid)
{
    char str[BUFF_SIZE];
    int fd = open(f, O_RDONLY);

    if (fd == -1) {
        printf("open failed\n");
        return;
    }else{
        read(fd, str, BUFF_SIZE);
        showInfo(str, uid);
    }

    close(fd);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Enter the namae of the user\n");
        exit(EXIT_FAILURE);
    }
    uid_t uid = getUidByName(argv[1]);
    struct dirent *dp;
    char uid_str[48];
    char path[48] = "/proc/";

    sprintf(uid_str, "%d", uid);

    DIR *udir = opendir(path);

    if (udir == NULL) {
        printf("opendir failed\n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        dp = readdir(udir);
        if (dp == NULL)
            break;
        if (strcmp(dp->d_name, ".") == 0 ||
            strcmp(dp->d_name, "..") == 0 ||
            dp->d_type == DT_REG)
            continue;

        char f[50];
        strcpy(f, path);
        strcat(f, dp->d_name);
        strcat(f, "/status");
        getInfo(f, uid);
    }

    closedir(udir);
    return 0;
}

