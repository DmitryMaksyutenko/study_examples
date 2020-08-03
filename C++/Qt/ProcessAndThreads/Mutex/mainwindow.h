#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QPushButton>
#include <QTextEdit>
#include <QMutex>

#include "worker.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QSpinBox m_threadsNumber;
    QPushButton m_ButtonStart;
    QTextEdit m_textArea;
    QMutex m_mutex;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPushButton* buttonStart();
    QTextEdit* textArea();
    int threadNumber() const;

public slots:
    void slotTextAppend(const QString &str);
};

#endif // MAINWINDOW_H
