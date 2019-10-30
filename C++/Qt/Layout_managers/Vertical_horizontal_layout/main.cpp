#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
/*
QBoxLayout::RightToLeft
QBoxLayout::LeftToRight
QBoxLayout::TopToBottom
QBoxLayout::BottomToTop
*/

    QBoxLayout layout(QBoxLayout::LeftToRight);

    QPushButton a("A");
    QPushButton b("B");
    QPushButton c("C");
    QPushButton d("D");

    layout.addWidget(&a, 1);
    layout.addWidget(&b, 2);
    layout.addWidget(&c, 3);
    layout.addWidget(&d, 4);

    w.setLayout(&layout);
    w.resize(700, 300);

    w.show();
    return app.exec();
}
