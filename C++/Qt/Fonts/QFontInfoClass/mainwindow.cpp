#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    itemsList(this)
{
    setGeometry(600, 300, 300, 200);
    itemsList.setGeometry(rect());
}

MainWindow::~MainWindow()
{
}

void MainWindow::addItemToList(QString str)
{
    itemsList.addItem(str);
}
