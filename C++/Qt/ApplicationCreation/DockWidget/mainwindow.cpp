#include "mainwindow.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  mp_DockButtons = new QDockWidget("Buttons", this);
  QWidget *central = new QWidget(this);
  QPushButton *b1 = new QPushButton("button 1", this);
  QPushButton *b2 = new QPushButton("button 2", this);
  QPushButton *b3 = new QPushButton("button 3", this);
  QPushButton *b4 = new QPushButton("button 4", this);

  QVBoxLayout *lay = new QVBoxLayout(this);
  lay->addWidget(b1);
  lay->addWidget(b2);
  lay->addWidget(b3);
  lay->addWidget(b4);

  central->setLayout(lay);

  mp_DockButtons->setWidget(central);

  addDockWidget(Qt::TopDockWidgetArea ,mp_DockButtons);
}

MainWindow::~MainWindow()
{
}

