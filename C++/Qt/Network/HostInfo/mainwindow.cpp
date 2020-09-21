#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(slotInfoCilcked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotInfoCilcked()
{
    QHostInfo::lookupHost(ui->lineEdit->text(), this,
                          SLOT(slotAppendText(QHostInfo)));
}

void MainWindow::slotAppendText(const QHostInfo &hostInfo)
{
    QString infoText;
    QString addresses;
    const auto addressList = hostInfo.addresses();

    for (const QHostAddress &addres : addressList) {
        addresses += "\n    " + addres.toString();
    }

    infoText.append("ID:\n    " + QString::number(hostInfo.lookupId()) + "\n");
    infoText.append("Host name:\n    " + hostInfo.hostName() + "\n");
    infoText.append("Host addresses : " + addresses + "\n");
    ui->textEdit->append(infoText);
}
