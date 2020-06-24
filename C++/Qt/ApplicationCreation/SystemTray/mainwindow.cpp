#include "mainwindow.h"

#include <QAction>
#include <QApplication>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  setWindowTitle("System Tray.");
  QAction *p_showHiedeAction = new QAction("&Show/Hide Application window.", this);
  connect(p_showHiedeAction, SIGNAL(triggered()), this, SLOT(slotShowHide()));

  QAction *p_showMessageAction = new QAction("&Show Message.", this);
  connect(p_showMessageAction, SIGNAL(triggered()), this, SLOT(slotShowMessage()));

  QAction *p_changeIconAction = new QAction("&Change Icon.", this);
  connect(p_changeIconAction, SIGNAL(triggered()), this, SLOT(slotChangeIcon()));

  QAction *p_quitAction = new QAction("&Quit.", this);
  connect(p_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

  pm_menu = new QMenu(this);
  pm_menu->addAction(p_showHiedeAction);
  pm_menu->addAction(p_showMessageAction);
  pm_menu->addAction(p_changeIconAction);
  pm_menu->addAction(p_quitAction);

  pm_sysTray = new QSystemTrayIcon(this);
  pm_sysTray->setContextMenu(pm_menu);
  pm_sysTray->setToolTip("System Tray");

  slotChangeIcon();

  pm_sysTray->show();
}

MainWindow::~MainWindow()
{
}


void MainWindow::closeEvent(QCloseEvent *e)
{
  if (pm_sysTray->isVisible()) hide();
  e->accept();
}


void MainWindow::slotShowHide()
{
  setVisible(!isVisible());
}

void MainWindow::slotShowMessage()
{
  pm_sysTray->showMessage("Information message",
                          "This is informatin message.",
                          QSystemTrayIcon::Information,
                          3000);
}

void MainWindow::slotChangeIcon()
{
  m_iconSwitch = !m_iconSwitch;
  QString iconName = m_iconSwitch ? ":/img/Linux.png" : ":/img/MacOSX.png";
  pm_sysTray->setIcon(QPixmap(iconName));
}
