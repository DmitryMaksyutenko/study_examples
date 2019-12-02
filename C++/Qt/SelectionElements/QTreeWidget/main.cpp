#include "widget.h"

#include <QApplication>
#include <QDirIterator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QDirIterator files("/home/dima/Projects", QDirIterator::Subdirectories);
    QFileInfo fileinfo;

    QTreeWidgetItem *newDir = new QTreeWidgetItem(&w);
    newDir->setText(0, files.fileName());
    QTreeWidgetItem *newFile;

    while(files.hasNext())
    {
        files.next();
        fileinfo = files.fileInfo();
        if(fileinfo.isDir())
        {
            newDir = new QTreeWidgetItem(&w);
            newDir->setText(0, files.fileName());
            newDir->setExpanded(true);
        }
        else
        {
            newFile = new QTreeWidgetItem(newDir);
            newFile->setText(0, files.fileName());
        }
    }

    w.resize(500, 800);
    w.show();
    return a.exec();
}
