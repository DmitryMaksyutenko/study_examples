#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotInfoCilcked();
    void slotAppendText(const QHostInfo &hostInfo);
};
#endif // MAINWINDOW_H
