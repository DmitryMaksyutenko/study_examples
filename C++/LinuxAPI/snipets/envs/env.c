#include <string.h>
#include <stdio.h>

#include "env.h"

int setEnv(const char *name, const char *value, int overwrite)
{
    int error = 0;
    char *check = getenv(name);
    char *newVar = malloc(strlen(name) + strlen(value) + 1);

    strcat(newVar, name);
    strcat(newVar, "=");
    strcat(newVar, value);

    if(check == 0)
    {
        error = putenv(newVar);
        if(!error) return 0;
        else return -1;
    }
    else
    {
        if(overwrite == 0) return 0;
        else
        {
            error = putenv(newVar);
            if(!error) return -1;
        }
    }

    return 0;
}

int unsetEnv(const char *name)
{
    int error = 0;
    char *check = getenv(name);

    if(check)
    {
        char **tmp = __environ;
        char *var = malloc(strlen(name) + strlen(check) + 1);
        strcat(var, name);
        strcat(var, "=");
        strcat(var, check);

        while(*__environ)
        {
            if(strcmp(*__environ, var) == 0)
            {
                free(*__environ);
                __environ = tmp;
                break;
            }
            *__environ++;
        }
        __environ = tmp;
        free(var);
        return 0;
    }

    return -1;
}