#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(700, 200, 300, 700);
    content.setParent(this);
    content.setGeometry(rect());
}

MainWindow::~MainWindow()
{
}

void MainWindow::appendText(QString str)
{
    content.append(str);
}
