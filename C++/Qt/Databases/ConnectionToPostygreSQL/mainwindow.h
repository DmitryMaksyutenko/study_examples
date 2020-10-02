#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connected();

private:
    QWidget m_centralWidget;
    QLabel m_connectionLabel;

};
#endif // MAINWINDOW_H
