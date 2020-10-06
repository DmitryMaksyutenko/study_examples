#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotSetLableConnected();
    void slotChangeTextAreaData(const QString &);

signals:
    void nextClicked();
    void previousClicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
