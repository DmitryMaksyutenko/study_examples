#include "mainwindow.h"

#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTextEdit *t = new QTextEdit(this);
    t->setFixedSize(300, 300);
}

MainWindow::~MainWindow()
{
}

