#include <QApplication>

#include "readxml.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ReadXml reader;
    QFileSystemModel fsModel;
    fsModel.setRootPath(QDir::homePath());

    w.setFileSystemModel(&fsModel);

    QObject::connect(&w, SIGNAL(fileSelected(const QModelIndex &)),
                     &reader, SLOT(readFile(const QModelIndex &)));
    QObject::connect(&w, SIGNAL(showClicked()),
                     &reader, SLOT(slotShowClicked()));
    QObject::connect(&reader, SIGNAL(sendData(const QStringList&)),
                     &w, SLOT(slotReceiveData(const QStringList&)));
    w.show();

    return a.exec();
}
