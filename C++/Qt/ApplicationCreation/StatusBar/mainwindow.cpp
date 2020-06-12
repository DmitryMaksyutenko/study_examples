#include "mainwindow.h"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  setMouseTracking(true);

  mp_xPos = new QLabel(this);
  mp_yPos = new QLabel(this);
  statusBar()->addWidget(mp_xPos);
  statusBar()->addWidget(mp_yPos);
}

MainWindow::~MainWindow()
{
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
  mp_xPos->setText("X = " + QString().setNum(e->x()));
  mp_yPos->setText("Y = " + QString().setNum(e->y()));
}

