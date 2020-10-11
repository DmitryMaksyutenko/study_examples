#include "mainwindow.h"

#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QLabel(parent)
{
    resize(300, 150);
    setAlignment(Qt::AlignCenter);
    setStyleSheet("color: green;");
    QFont f = font();
    f.setPointSize(32);
    setFont(f);
}

MainWindow::~MainWindow()
{
}
