#include <QApplication>

#include "mainwindow.h"
#include "MyLib/mylib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    MyLib l;

    w.setText(l.helloWorld());

    w.show();
    return a.exec();
}
