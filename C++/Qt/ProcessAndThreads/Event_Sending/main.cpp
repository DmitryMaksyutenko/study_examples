#include "mainwindow.h"
#include "thread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Thread t(&w);
    t.start();
    w.show();
    return a.exec();
}
