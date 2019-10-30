#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QWidget>
//	The headers files for box layout style.
#include <QBoxLayout>
//#include <QHBoxLayout> In the constructor of the classes do not pass the parameter of vertical or horizontal location.
//#include <QVBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow();
};
#endif // MAINWINDOW_H
