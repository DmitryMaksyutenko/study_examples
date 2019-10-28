#include "mainwindow.h"

#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPixmap img("/home/dima/Pictures/wall4.jpg");
    QPalette palette;
    palette.setBrush(w.backgroundRole(), QBrush(img));
    w.setPalette(palette);
    w.setFixedSize(img.width(), img.height());

    QScrollArea scroll;
    scroll.setWidget(&w);

    scroll.show();
    return a.exec();
}
