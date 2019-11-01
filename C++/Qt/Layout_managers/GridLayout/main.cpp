#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Grid Layout");

    QPushButton b1("A");
    QPushButton b2("B");
    QPushButton b3("C");
    QPushButton b4("D");


    QGridLayout grid;
    grid.setContentsMargins(20, 20, 20, 20);
    grid.setSpacing(15);
    grid.addWidget(&b1, 0, 0);
    grid.addWidget(&b2, 0, 1);
    grid.addWidget(&b3, 1, 0);
    grid.addWidget(&b4, 1, 1);

    w.setLayout(&grid);

    w.show();
    return a.exec();
}
