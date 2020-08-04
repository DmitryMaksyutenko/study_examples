#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_textArea.resize(300, 400);
    m_buttonStart.setText("Start");

    m_vbl.addWidget(&m_textArea);
    m_vbl.addWidget(&m_buttonStart);

    m_centralWidget.setLayout(&m_vbl);
    setCentralWidget(&m_centralWidget);
}

MainWindow::~MainWindow()
{
}

QTextEdit *MainWindow::textArea()
{
    return &m_textArea;
}

QPushButton *MainWindow::buttonStart()
{
    return &m_buttonStart;
}

