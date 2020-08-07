#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget m_centralWidget;
    QVBoxLayout m_vbl;
    QProgressBar m_pBarOne;
    QProgressBar m_pBarTwo;
    QProgressBar m_pBarThree;
    QPushButton m_buttonStart;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton *buttonStart();
    QProgressBar *progressBarOne();
    QProgressBar *progressBarTwo();
    QProgressBar *progressBarThree();
};
#endif // MAINWINDOW_H
