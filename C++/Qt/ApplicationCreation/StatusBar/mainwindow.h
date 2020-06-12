#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT
  private:
    QLabel *mp_xPos;
    QLabel *mp_yPos;

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  protected:
    void mouseMoveEvent(QMouseEvent *e);
};
#endif // MAINWINDOW_H
