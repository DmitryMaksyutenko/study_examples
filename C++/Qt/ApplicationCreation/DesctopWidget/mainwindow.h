#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  private:
    QLabel m_lbl;
    QPushButton m_captureScreenButton;

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    void slotGrabScreen();
};
#endif // MAINWINDOW_H
