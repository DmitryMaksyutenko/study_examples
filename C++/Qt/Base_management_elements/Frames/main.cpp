#include "mainwindow.h"

#include <QApplication>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFrame f;
    f.setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    f.setContentsMargins(10, 10, 10, 10);
    f.setLineWidth(3);

    w.show();
    f.show();
    return a.exec();
}
