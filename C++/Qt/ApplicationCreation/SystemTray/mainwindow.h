#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCloseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  private:
    QSystemTrayIcon *pm_sysTray;
    QMenu *pm_menu;
    bool m_iconSwitch;

  protected:
    void closeEvent(QCloseEvent *e) override;

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    void slotShowHide();
    void slotShowMessage();
    void slotChangeIcon();
};
#endif // MAINWINDOW_H
