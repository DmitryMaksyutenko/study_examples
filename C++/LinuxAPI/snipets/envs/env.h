#ifndef __ENV_H
#define __ENV_H

#include <unistd.h>
#include <stdlib.h>

int setEnv(const char *name, const char *value, int overwrite);
int unsetEnv(const char *name);

#endif