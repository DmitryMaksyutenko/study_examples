#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTextEdit content;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void appendText(QString str);
};
#endif // MAINWINDOW_H
