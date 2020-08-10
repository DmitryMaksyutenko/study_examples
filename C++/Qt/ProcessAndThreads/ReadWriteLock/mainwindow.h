#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTextEdit m_textArea;
    QPushButton m_buttonStart;
    QVBoxLayout m_vbl;
    QWidget m_centralWidget;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTextEdit *textArea();
    QPushButton *buttonStart();
};
#endif // MAINWINDOW_H
