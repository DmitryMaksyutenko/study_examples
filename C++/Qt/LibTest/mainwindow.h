#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>

class MainWindow : public QLabel
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
