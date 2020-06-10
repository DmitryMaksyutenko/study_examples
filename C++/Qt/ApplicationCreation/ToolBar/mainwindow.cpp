#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  addToolBar(Qt::TopToolBarArea, createToolBar());
  addToolBar(Qt::BottomToolBarArea, createToolBar());
  addToolBar(Qt::LeftToolBarArea, createToolBar());
  addToolBar(Qt::RightToolBarArea, createToolBar());
}

MainWindow::~MainWindow()
{
}

QToolBar *MainWindow::createToolBar()
{
  QToolBar *p_tb = new QToolBar("Linker ToolBar", this);

  p_tb->addAction("One", this, SLOT(slotNoImpl()));
  p_tb->addAction("Two", this, SLOT(slotNoImpl()));
  p_tb->addSeparator();
  p_tb->addAction("Three", this, SLOT(slotNoImpl()));
  p_tb->addAction("Four", this, SLOT(slotNoImpl()));

  return p_tb;
}

void MainWindow::slotNoImpl()
{
  QMessageBox::information(this, "Message", "Not Implemented");
}

