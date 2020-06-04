#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  private:
    QLabel mLbl;

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  protected:
    bool event(QEvent *event) override;
};
#endif // MAINWINDOW_H
