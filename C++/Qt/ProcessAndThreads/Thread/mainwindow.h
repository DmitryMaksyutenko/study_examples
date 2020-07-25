#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTextEdit *text;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void textInsert(const QString &str);
};
#endif // MAINWINDOW_H
