#include "mainwindow.h"
#include "newthread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    NewThread t;
    t.start();
    w.show();
    return a.exec();
}
