#ifndef __FILE_H_

#include <dirent.h>
#include <stdbool.h>

void createFiles(int number, const char *dirName);
void deleteFiles(const char *dirName);

const char* randomFileName();
DIR* isDirOpened(const char *dirName);
bool isFileExists(DIR *dir, const char* fileName);
const char* buildFilePath(const char *dirName, const char *fileName);
void writeOneByte(int fd);

#endif __FILE_H_
