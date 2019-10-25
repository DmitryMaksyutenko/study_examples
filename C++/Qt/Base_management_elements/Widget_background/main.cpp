#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlag(Qt::Window);
    w.setWindowTitle("Background color");

    //	QPalette is the object stores the colors groups and bitmap.
    QPalette palette;
    palette.setColor(w.backgroundRole(), Qt::blue);
    w.setPalette(palette);

    QWidget w2(&w);
    QPalette pal2;
    pal2.setBrush(w2.backgroundRole(), QBrush(QPixmap("/home/dima/Projects/Qt/Widget_background/wall4.jpg")));
    w2.setPalette(pal2);
    w2.setGeometry(80, 100, 250, 200);
    //	This method sets the property autoFillBackground that makes children of the base widget visible.
    w2.setAutoFillBackground(true);

    QWidget w3(&w);
    QPalette pal3;
    pal3.setColor(QPalette::ColorRole::Background, Qt::green);
    w3.setPalette(pal3);
    w3.setGeometry(0, 0, 400, 100);
    w3.setAutoFillBackground(true);

    w.resize(400, 400);
    w.show();
    return a.exec();
}
