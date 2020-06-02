#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "inputdialog.h"

class MainWindow : public QPushButton
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    void slotButtonClicked();
};
#endif // MAINWINDOW_H
