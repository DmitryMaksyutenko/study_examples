#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

//	The class inherited from QWidget.
//	This allows creating the object hierarchy, use signals and slots.
class MainWindow : public QWidget
{
    Q_OBJECT

private:

public:
    MainWindow(QWidget* pwgt = nullptr);
    MainWindow(QWidget* pwgt, Qt::WindowFlags f);
    ~MainWindow();
};

#endif // MAINWINDOW_H
