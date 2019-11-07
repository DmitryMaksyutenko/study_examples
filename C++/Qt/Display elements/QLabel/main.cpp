#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //	The widget of the inscription serves to display information about the application state or the explain information.
    //	This field can't be modified by the user.
    //	Inherited from QFrame, so can has the frame.
    //	The displayed information may be the text, graphical or animation type. setText(), setPixmap(), setMovie()
    //	The setAlignment() method use for text layout.
    //	It can display the HTML format.
    QLabel label("<h1>Hello</h1>"
                 "<hr>"
                 "<img src=\"/home/dima/Pictures/linux-ubuntu-logo.jpg\">"
                 "<ol>"
                 "<li>One</li>"
                 "<li><Two/li>"
                 "<li>Three</li>"
                 "</ol>");

    QPixmap i("/home/dima/Pictures/linux-ubuntu-logo.jpg");
    qDebug() << i.size();
    QLabel label2;
    label2.resize(i.size());
    label2.setPixmap(i);

    label.setGeometry(0, 0, 900, 1000);
    label.show();

    label2.setGeometry(label.size().width() + 20, 0, 900, 1000);
    label2.show();

    return a.exec();
}
