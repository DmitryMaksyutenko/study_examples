#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QProgressBar>
#include <QEvent>

#include "progressevent.h"

class MainWindow : public QProgressBar
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void customEvent(QEvent *e);
};
#endif // MAINWINDOW_H
