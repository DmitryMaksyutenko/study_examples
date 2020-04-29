#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>

struct passwd *getPwNum(const char *name)
{
    struct passwd *info = malloc(sizeof(struct passwd));

    while (1)
    {
        info = getpwent();
        if(info == NULL)
            return NULL;
        if(strcmp(info->pw_name, name) ==0)
            return info;
    }

    endpwent();

    return NULL;
}

void printInfo(const struct passwd *info)
{
    printf("======================\n");
    printf("name: %s\n", info->pw_name);
    printf("password: %s\n", info->pw_passwd);
    printf("uid: %i\n", info->pw_uid);
    printf("gid: %i\n", info->pw_gid);
    printf("disc: %s\n", info->pw_gecos);
    printf("dir: %s\n", info->pw_dir);
    printf("shell: %s\n", info->pw_shell);
    printf("======================\n");
}

void main()
{
    char *name;
    printf("enter name: ");
    fgets(name, 20, stdin);
    name[strlen(name) - 1] = '\0';
    struct passwd *info = getPwNum(name);

    if (info == NULL)
        printf("No appropriate row in the password file\n");
    else
        printInfo(info);

    exit(EXIT_SUCCESS);
}