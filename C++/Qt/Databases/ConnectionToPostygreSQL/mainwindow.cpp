#include "mainwindow.h"

#include <QVBoxLayout>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(350, 200);
    m_connectionLabel.setText("No Connection");
    QFont font = m_connectionLabel.font();
    font.setPointSize(32);
    m_connectionLabel.setStyleSheet("color: red");
    m_connectionLabel.setFont(font);
    m_connectionLabel.setAlignment(Qt::AlignCenter);

    QVBoxLayout *vbl = new QVBoxLayout(this);
    vbl->addWidget(&m_connectionLabel);

    m_centralWidget.setLayout(vbl);
    setCentralWidget(&m_centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::connected()
{
    m_connectionLabel.setStyleSheet("color: green");
    m_connectionLabel.setText("Connected!");
}

