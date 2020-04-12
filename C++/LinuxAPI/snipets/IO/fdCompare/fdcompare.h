#ifndef _FDCOMAPARE_H
#define _FDCOMAPARE_H

#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void compareFd(int lhs, int rhs);
bool isSameOffset(int lhs, int rhs);
bool isSameFlags(int lhs, int rhs);

#endif