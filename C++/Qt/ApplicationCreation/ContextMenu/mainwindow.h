#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QAction>
#include <QContextMenuEvent>

class MainWindow : public QTextEdit
{
    Q_OBJECT

  private:
    QMenu mMenu;

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  protected:
    void contextMenuEvent(QContextMenuEvent *e) override;

  public slots:
    void slotActivated(QAction *act);
};
#endif // MAINWINDOW_H
