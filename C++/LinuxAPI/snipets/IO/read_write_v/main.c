#include "src/read_write_v.h"

int main(void)
{

    int fdFrom = open("test.txt", O_RDONLY);
    int fdTo = open("testTo.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    ssize_t readed = lseek(fdFrom, 0, SEEK_END);
    lseek(fdFrom, 0, SEEK_SET);
    int buffSize = 16;
    int buffsCount = readed / buffSize + 1;
    struct iovec *buffs = malloc(buffsCount);

    int last = readed - (buffsCount * buffSize);

    for(int i = 0; i < buffsCount; i++)
    {
        buffs[i].iov_len = buffSize;
        buffs[i].iov_base = (char*)malloc(buffSize);
    }

    ssize_t readedFrom = readV(fdFrom, buffs, buffsCount);
    ssize_t writedTo = writeV(fdTo, buffs, buffsCount);

    close(fdFrom);
    close(fdTo);

    return 0;
}