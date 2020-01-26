#include <QApplication>

#include "testlabel.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    TestLabel widget;
    widget.setGeometry(700, 400, 300, 300);

    QRect testRectangle(QPoint(10, 10), QSize(30, 20));

    widget.setText("size: " +
                   QString::number(testRectangle.size().width()) +
                   " " +
                   QString::number(testRectangle.size().height()) +
                   "\nwidth: " +
                   QString::number(testRectangle.width()) +
                   "\nheight: " +
                   QString::number(testRectangle.height()) +
                   "\npos x: " +
                   QString::number(testRectangle.x()) +
                   "\npos y: " +
                   QString::number(testRectangle.y()));

    widget.show();
    return app.exec();
}
