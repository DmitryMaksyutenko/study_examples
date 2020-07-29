#include "mainwindow.h"

void MainWindow::run()
{
    for (int i = 0; i <= 100; i++) {
        usleep(1000000);
        emit process(i);
    }
}

