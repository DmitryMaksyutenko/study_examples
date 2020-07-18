#ifndef __CMD_H_

struct DirInfo
{
    int filecount;
    char *dirName;
};

struct DirInfo* getCmdParams(int argc, char **argv);

#endif __CMD_H_
