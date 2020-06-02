#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QPushButton("Press me", parent)
{
  connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotButtonClicked()
{
  InputDialog *pInputDialog = new InputDialog;

  if (pInputDialog->exec() == QDialog::Accepted) {
    QMessageBox::information(0, "Information",
                             "First Name: " +
                             pInputDialog->firstName() +
                             "\nLast Name: " +
                             pInputDialog->lastName());
  }
  delete pInputDialog;
}

