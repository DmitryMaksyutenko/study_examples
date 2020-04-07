#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QListWidget itemsList;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addItemToList(QString str);
};
#endif // MAINWINDOW_H
