#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_buttonStart.setText("Start");
    m_pBarOne.setMinimum(0);
    m_pBarOne.setMaximum(100);
    m_pBarOne.setValue(0);
    m_pBarTwo.setMinimum(0);
    m_pBarTwo.setMaximum(100);
    m_pBarTwo.setValue(0);
    m_pBarThree.setMinimum(0);
    m_pBarThree.setMaximum(100);
    m_pBarThree.setValue(0);

    m_vbl.addWidget(&m_pBarOne);
    m_vbl.addWidget(&m_pBarTwo);
    m_vbl.addWidget(&m_pBarThree);
    m_vbl.addWidget(&m_buttonStart);

    m_centralWidget.setLayout(&m_vbl);
    setCentralWidget(&m_centralWidget);
}

MainWindow::~MainWindow()
{
}

QPushButton *MainWindow::buttonStart()
{
    return &m_buttonStart;
}

QProgressBar *MainWindow::progressBarOne()
{
    return &m_pBarOne;
}

QProgressBar *MainWindow::progressBarTwo()
{
    return &m_pBarTwo;
}

QProgressBar *MainWindow::progressBarThree()
{
    return &m_pBarThree;
}

