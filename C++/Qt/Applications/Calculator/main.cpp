#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow calculator;
    calculator.setWindowTitle("Calculator");
    calculator.resize(230, 200);
    calculator.show();
    return a.exec();
}
