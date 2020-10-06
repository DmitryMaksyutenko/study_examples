#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setText("Not Connected.");
    ui->label->setStyleSheet("color: red");

    ui->textEdit->setReadOnly(true);

    connect(ui->buttonNext, SIGNAL(clicked()), this, SIGNAL(nextClicked()));
    connect(ui->buttonPrev, SIGNAL(clicked()), this, SIGNAL(previousClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotSetLableConnected()
{
    ui->label->setText("Connected");
    ui->label->setStyleSheet("color: green");
}

void MainWindow::slotChangeTextAreaData(const QString &str)
{
    ui->textEdit->clear();
    ui->textEdit->setText(str);
}

