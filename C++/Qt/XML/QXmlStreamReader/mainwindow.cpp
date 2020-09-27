#include <QDir>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->treeView, SIGNAL(clicked(const QModelIndex &)),
            this, SLOT(slotFileSelected(const QModelIndex &)));
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SIGNAL(showClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFileSystemModel(QFileSystemModel *fsm)
{
    ui->treeView->setModel(fsm);
    ui->treeView->setRootIndex(fsm->index(QDir::homePath()));
}

void MainWindow::slotFileSelected(const QModelIndex &index)
{
    emit fileSelected(index);
}

void MainWindow::slotReceiveData(const QStringList &list)
{
    ui->textEdit->clear();
    for (QString str : list) {
        ui->textEdit->append(str);
    }
}

