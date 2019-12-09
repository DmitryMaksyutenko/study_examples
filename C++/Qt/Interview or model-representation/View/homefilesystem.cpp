#include "homefilesystem.h"

HomeFileSystem::HomeFileSystem() : QFileSystemModel()
{
    setRootPath("/");
}

HomeFileSystem::HomeFileSystem(QString str) : QFileSystemModel()
{
    setRootPath(str);
}
