#include <unistd.h>
#include <cstdio>
#include <cstdlib>

static int globalData = 111;

int main()
{
    int stackData = 222;
    pid_t childPid;

    switch (childPid = fork()) {
        case -1:
            printf("fork() ERROR\n");
            exit(EXIT_FAILURE);
        case 0:
            globalData *= 3;
            stackData *= 3;
            break;
        default:
            sleep(3);
            break;
    }

    printf("PID=%ld %s globalData=%d stackData=%d\n",
            (long) getpid(),
            (childPid == 0) ? "CHILD" : "PARENT",
            globalData,
            stackData);

    return 0;
}
