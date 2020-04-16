#include "src/env.h"

int main()
{
    int error = 0;
    error = setEnv("TEST_NAME", "test_value", 0);
    if(!error)
        printf("%s\n", getenv("TEST_NAME"));
    else
        printf("Function return %i\n", error);

    error = unsetEnv("TEST_NAME");

    exit(EXIT_SUCCESS);
}