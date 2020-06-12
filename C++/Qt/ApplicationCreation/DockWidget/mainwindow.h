#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
  private:
    QDockWidget *mp_DockButtons;

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
