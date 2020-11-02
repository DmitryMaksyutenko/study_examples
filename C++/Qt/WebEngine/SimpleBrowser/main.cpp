#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget webBtowser;
    webBtowser.show();
    return a.exec();
}
