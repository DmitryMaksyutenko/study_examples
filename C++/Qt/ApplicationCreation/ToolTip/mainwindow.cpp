#include "mainwindow.h"

#include <QHelpEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  mLbl.setWindowFlag(Qt::ToolTip);
}

MainWindow::~MainWindow()
{
}

bool MainWindow::event(QEvent *event)
{
  if (event->type() == QEvent::ToolTip) {
    QHelpEvent *pHelp = static_cast<QHelpEvent *>(event);
    mLbl.move(pHelp->globalPos());
    mLbl.setText(toolTip());
    mLbl.show();
    QTimer::singleShot(3000, &mLbl, SLOT(hide()));
  }

  return QWidget::event(event);
}
