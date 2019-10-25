#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

void modify(QWidget& w, QString message)
{
    qDebug() << "\n"<< message;

    //	The height(), width() methods returns values of widget size. The size() function return the QSize object.
    //	The QSize object is storage of the widget height and width.
    int height = w.height();
    int width = w.width();
    QSize size = w.size();
    qDebug() << "----- height width and size -----";
    qDebug() << "height " << height;
    qDebug() << "width " << width;
    qDebug() << "size " << size;
    qDebug() << "---------------------------------";

    //	The x(), y() methods purpose for defining the coordinate of the widget, returns a value.
    //	The pos() method returns the QPoint object that store the coordinates.
    int x = w.x();
    int y = w.y();
    QPoint point = w.pos();
    qDebug() << "----- x,y and point -----";
    qDebug() << "x position " << x;
    qDebug() << "y position " << y;
    qDebug() << "the points of the position " << point;
    qDebug() << "---------------------------------";

    //	The geometry() return the QRect object, this object describes the position and size of the widget.
    QRect rect = w.geometry();
    qDebug() << "----- position and size -----";
    qDebug() << "QRect object " << rect;
    qDebug() << "---------------------------------";

    qDebug();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlag(Qt::WindowType::Window);

    modify(w, "----- Default parameters -----");

    //	The move() method can change the position of the widget, the resize() method changes the size.
    w.resize(700, 700);
    w.move(100, 100);

    //	The setGeometry(x, y, width, height) method can change the parameters of the widget simultaneously.
    w.setGeometry(500, 200, 300, 300);

    modify(w, "----- The widget parameters after the change -----");

    w.show();
    return a.exec();
}
