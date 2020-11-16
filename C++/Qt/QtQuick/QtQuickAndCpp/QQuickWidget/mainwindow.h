#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QQuickWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QQuickWidget *main_rect;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
