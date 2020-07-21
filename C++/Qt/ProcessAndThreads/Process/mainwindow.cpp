#include "mainwindow.h"

#include <QDebug>

void MainWindow::connections()
{
    QObject::connect(&m_buttonStart, SIGNAL(clicked()), this, SLOT(slotGetProcessName()));
    QObject::connect(&m_processName, SIGNAL(textEdited(const QString &)), this, SLOT(slotIsButtonEnable()));
    QObject::connect(pm_process, SIGNAL(readyReadStandardOutput()), this, SLOT(slotReadFromStdout()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_buttonStart.setText("Start");
    m_buttonStart.setEnabled(false);

    m_horizontalLayout.addWidget(&m_processName);
    m_horizontalLayout.addWidget(&m_buttonStart);

    m_verticalLayout.addWidget(&m_content);
    m_verticalLayout.addLayout(&m_horizontalLayout);

    m_centralWidget.setLayout(&m_verticalLayout);
    setCentralWidget(&m_centralWidget);

    pm_process = new QProcess(this);

    connections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotGetProcessName()
{
    m_processString = m_processName.text();

    qDebug() << pm_process->state();
    pm_process->start(m_processString, QStringList());
    qDebug() << pm_process->state();
}

void MainWindow::slotIsButtonEnable()
{
    m_processName.text().length() ? m_buttonStart.setEnabled(true) : m_buttonStart.setEnabled(false);
}

void MainWindow::slotReadFromStdout()
{
     m_content.setText(pm_process->readAll());
}
