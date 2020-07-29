#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>

class MainWindow : public QThread
{
    Q_OBJECT

public:
    void run() override;

signals:
    void process(int);
};
#endif // MAINWINDOW_H
