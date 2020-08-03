#include "mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    QHBoxLayout *hbl = new QHBoxLayout(this);
    QVBoxLayout *vbl = new QVBoxLayout(this);

    m_textArea.setFixedSize(300, 500);
    m_ButtonStart.setText("Start");
    m_threadsNumber.setValue(1);

    vbl->addWidget(&m_threadsNumber);
    vbl->addWidget(&m_ButtonStart);
    hbl->addWidget(&m_textArea);
    hbl->addLayout(vbl);
    central->setLayout(hbl);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{

}

QPushButton *MainWindow::buttonStart()
{
    return &m_ButtonStart;
}

QTextEdit *MainWindow::textArea()
{
    return &m_textArea;
}

int MainWindow::threadNumber() const
{
    return m_threadsNumber.value();
}

void MainWindow::slotTextAppend(const QString &str)
{
    m_mutex.lock();
    m_textArea.append(str);
    m_mutex.unlock();
}
