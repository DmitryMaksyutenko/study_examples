#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextEdit>

class MainWindow : public QTextEdit
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void slotDirectoryChanged(const QString&);
    void slotFileChanged(const QString&);
};
#endif // MAINWINDOW_H
