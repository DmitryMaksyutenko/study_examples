#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  QMenu *pMenu = new QMenu("&Menu", this);
  pMenu->addAction("&about", this, SLOT(slotAbout()), Qt::CTRL + Qt::Key_Q);
  pMenu->addSeparator();

  QAction *pCheck = pMenu->addAction("&CheckableItem");
  pCheck->setCheckable(true);
  pCheck->setChecked(true);

  QMenu *pSubMenu = new QMenu("&SubMenu", pMenu);
  pMenu->addMenu(pSubMenu);
  pSubMenu->addAction("&Sub");

  pMenu->addSeparator();
  pMenu->addAction("&Exit", qApp, SLOT(quit()));

  menuBar()->addMenu(pMenu);
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotAbout()
{
  QMessageBox *message = new QMessageBox(this);
  message->setText("Some text");
  message->show();
}

