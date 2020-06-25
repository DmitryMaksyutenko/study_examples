#include "mainwindow.h"

#include <QPixmap>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  resize(640, 480);
  m_captureScreenButton.setText("Capture Screen.");
  connect(&m_captureScreenButton, SIGNAL(clicked()), this, SLOT(slotGrabScreen()));

  QWidget *p_centralWidget = new QWidget(this);
  QVBoxLayout *p_VBLMain = new QVBoxLayout(this);
  p_VBLMain->addWidget(&m_captureScreenButton);
  p_VBLMain->addWidget(&m_lbl);
  p_centralWidget->setLayout(p_VBLMain);
  setCentralWidget(p_centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotGrabScreen()
{
  QDesktopWidget *p_desctop = QApplication::desktop();
  QScreen *screenShot = QWidget::screen();
  QPixmap img = screenShot->grabWindow(p_desctop->winId());
  m_lbl.setPixmap(img.scaled(m_lbl.size()));
}

