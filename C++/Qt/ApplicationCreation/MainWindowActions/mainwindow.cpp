#include "mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QWidget>
#include <QPushButton>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QAction>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  setGeometry(700, 300, 500, 500);
  QMenuBar *pMenu = menuBar();
  QWidget *pCentralWidget = new QWidget(this);
  QStatusBar *pStatusBar = statusBar();
  QVBoxLayout *lay = new QVBoxLayout(this);

  QMenu *pFileMenu = new QMenu("&File", this);
  pMenu->addMenu(pFileMenu);
  QMenu *pViewMenu = new QMenu("&View", this);
  pMenu->addMenu(pViewMenu);
  pMenu->addMenu(new QMenu("&Edit", pMenu));
  pMenu->addMenu(new QMenu("&Help", pMenu));
  pMenu->addMenu(new QMenu("&About", pMenu));

  QPushButton *b1 = new QPushButton("&File", this);
  QPushButton *b2 = new QPushButton("&View", this);
  lay->addWidget(b1);
  lay->addWidget(b2);
  lay->setMargin(100);
  pCentralWidget->setLayout(lay);
  setCentralWidget(pCentralWidget);

  QLabel *status = new QLabel("Hello", this);
  pStatusBar->addWidget(status);

  // Actions.
  QFileDialog *pFileDialog = new QFileDialog(this);
  QAction *pFileAction = new QAction("Show Files.", this);
  pFileAction->setShortcut(QKeySequence("CTRL+F"));
  pFileAction->setWhatsThis("Open a File Dialog.");
  pFileAction->setToolTip("Open a File Dialog.");
  connect(pFileAction, SIGNAL(triggered()), pFileDialog, SLOT(show()));
  pFileMenu->addAction(pFileAction);
  connect(b1, SIGNAL(clicked()), pFileAction, SLOT(trigger()));

  QColorDialog *pColorDialog = new QColorDialog(this);
  QAction *pColorAction = new QAction("Show Color choise.", this);
  pColorAction->setShortcut(QKeySequence("CTRL+A"));
  pFileAction->setWhatsThis("Open a Color Dialog.");
  pFileAction->setToolTip("Open a Color Dialog.");
  connect(pColorAction, SIGNAL(triggered()), pColorDialog, SLOT(show()));
  pViewMenu->addAction(pColorAction);
  connect(b2, SIGNAL(clicked()), pColorAction, SLOT(trigger()));
}

MainWindow::~MainWindow()
{
}

