#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QTextEdit(parent)
{
  setReadOnly(true);
  mMenu.addAction("Red");
  mMenu.addAction("Green");
  mMenu.addAction("Blue");

  connect(&mMenu, SIGNAL(triggered(QAction*)), SLOT(slotActivated(QAction*)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::contextMenuEvent(QContextMenuEvent *e)
{
  mMenu.exec(e->globalPos());
}

void MainWindow::slotActivated(QAction *act)
{
  QString color = act->text().remove("&");
  setHtml(QString("<BODY BGCOLOR=%1></BODY>").arg(color));
}

