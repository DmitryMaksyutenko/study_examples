#include <QApplication>
#include <QTreeView>

#include <QDebug>

#include "homefilesystem.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    HomeFileSystem fileModel;

    QTreeView fileView;
    fileView.setWindowTitle("File Explorer");
    fileView.setGeometry(200, 200, 500, 600);
    fileView.setModel(&fileModel);
    fileView.setRootIndex(fileModel.index(fileModel.rootPath()));

    fileView.show();
    app.exec();
}
