#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QProgressBar(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::customEvent(QEvent *e)
{
    if ((int)e->type() == ProgressEvent::ProgressType) {
        setValue(((ProgressEvent *)e)->value());
    }
    QWidget::customEvent(e);
}

