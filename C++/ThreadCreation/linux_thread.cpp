#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#include <sched.h>

#define STACK_SIZE 4096

static int foo(void* arg)
{
    for (int i = 0; i < 10; i++) {
        sleep(2);
        printf("this is \"foo\" thread\n");
    }
    return 0;
}

int main(int argc, char **argv)
{

    void *stack = malloc(STACK_SIZE) + STACK_SIZE;
    int thread_id = clone(foo, stack, CLONE_VM | CLONE_THREAD | CLONE_SIGHAND, NULL);
    printf("%d\n", thread_id);
    for (int i = 0; i < 10; i++) {
        sleep(1);
        printf("this is \"main\" thread\n");
    }
    exit(EXIT_SUCCESS);
}
