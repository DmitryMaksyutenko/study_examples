#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QProcess>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTextEdit m_content;
    QLineEdit m_processName;
    QPushButton m_buttonStart;
    QWidget m_centralWidget;
    QVBoxLayout m_verticalLayout;
    QHBoxLayout m_horizontalLayout;

    QString m_processString;
    QProcess *pm_process;

    void connections();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotGetProcessName();
    void slotIsButtonEnable();
    void slotReadFromStdout();

};
#endif // MAINWINDOW_H
