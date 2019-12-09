#ifndef HOMEFILESYSTEM_H
#define HOMEFILESYSTEM_H

#include <QFileSystemModel>


class HomeFileSystem : public QFileSystemModel
{
public:
    HomeFileSystem();
    HomeFileSystem(QString str);
};

#endif // HOMEFILESYSTEM_H
