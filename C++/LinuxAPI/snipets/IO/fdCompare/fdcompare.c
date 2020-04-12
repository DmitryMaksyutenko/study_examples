#include "fdcompare.h"

void fdcompare(int lhs, int rhs)
{
    printf("File descriptors:\nlhs = %d\nrhs = %d\n\n", lhs, rhs);

    if(isSameOffset(lhs, rhs))
        printf("The desctiptors has the same file offset.\n");
    else
        printf("The desctiptors hasn't the same file offset.\n");

    if(isSameFlags(lhs, rhs))
        printf("The desctiptors has the same flags.\n");
    else
        printf("The desctiptors hasn't the same flags.\n");
}

bool isSameOffset(int lhs, int rhs)
{
    off_t lhs_offset = lseek(lhs, 0, SEEK_CUR);
    off_t rhs_offset = lseek(rhs, 0, SEEK_CUR);

    if(lhs_offset == rhs_offset)
        return true;

    return false;
}
bool isSameFlags(int lhs, int rhs)
{
    int lhs_mode = fcntl(lhs, F_GETFL);
    int rhs_mode = fcntl(rhs, F_GETFL);

    if(lhs_mode == rhs_mode)
        return true;

    return false;
}