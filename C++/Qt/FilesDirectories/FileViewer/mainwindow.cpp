#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QTextEdit(parent)
{
  setWindowTitle("File System Viewer.");
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotDirectoryChanged(const QString &str)
{
  append("Directory changed:" + str);
}

void MainWindow::slotFileChanged(const QString &str)
{
  append("File changed:" + str);
}

