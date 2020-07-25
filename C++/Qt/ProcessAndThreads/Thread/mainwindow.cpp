#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    text = new QTextEdit(this);
    text->setFixedSize(600, 300);
}

MainWindow::~MainWindow()
{
}

void MainWindow::textInsert(const QString &str)
{
    text->append(str);
}

