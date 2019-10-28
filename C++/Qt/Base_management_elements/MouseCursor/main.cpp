#include "mainwindow.h"

#include <QApplication>
#include <QCursor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPixmap pixM("/home/dima/Projects/Qt/MouseCursor/cursor.png");

    //	The mouse pointer is a small bitmap image.
    QCursor cursor(pixM);

    //	The setCursor() method requires the png image as the argument or the Qt::CursorShape enum.
    w.setCursor(cursor);

    /*
        QGuiApplication::setOverrideCursor(Qt::CursorShape::WaitCursor) - method notifies the user that the application is under load.
        QGuiApplication::restoreOverrideCursor() - method returns the default mouse image.

        QCursor::pos() - return QPoint object (mouse cursor position).
        QCursor::setPos() - change mouse cursor position.
    */

    w.show();
    return a.exec();
}
