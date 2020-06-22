#include "mdiprogram.h"

#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>
#include <QList>

MDIProgram::MDIProgram(QWidget *parent)
  : QMainWindow(parent)
{
  QAction *pActNew = new QAction("New File", this);
  pActNew->setText("&New");
  pActNew->setShortcut(QKeySequence("CTRL+N"));
  pActNew->setToolTip("New Document");
  pActNew->setStatusTip("Create a new file");
  pActNew->setWhatsThis("Create a new file");
  connect(pActNew, SIGNAL(triggered()), this, SLOT(slotNewDoc()));

  QAction *pActOpen = new QAction("Open File", this);
  pActOpen->setText("&Open");
  pActOpen->setShortcut(QKeySequence("CTRL+O"));
  pActOpen->setToolTip("Open Document");
  pActOpen->setStatusTip("Open file");
  pActOpen->setWhatsThis("Open file");
  connect(pActOpen, SIGNAL(triggered()), this, SLOT(slotLoad()));

  QAction *pActSave = new QAction("Save File", this);
  pActSave->setText("&Save");
  pActSave->setShortcut(QKeySequence("CTRL+S"));
  pActSave->setToolTip("Save Document");
  pActSave->setStatusTip("Save file");
  pActSave->setWhatsThis("Save file");
  connect(pActSave, SIGNAL(triggered()), this, SLOT(slotSave()));

  QToolBar *pTool = new QToolBar("File Operations", this);
  pTool->addAction(pActNew);
  pTool->addAction(pActOpen);
  pTool->addAction(pActSave);
  addToolBar(pTool);

  QMenu *pMenuFile = new QMenu("&File", this);
  pMenuFile->addAction(pActNew);
  pMenuFile->addAction(pActOpen);
  pMenuFile->addAction(pActSave);
  pMenuFile->addAction("Save &As...", this, SLOT(slotSaveAs()));
  pMenuFile->addSeparator();
  pMenuFile->addAction("&Quit", qApp, SLOT(), QKeySequence("CTRL+Q"));

  menuBar()->addMenu(pMenuFile);

  pm_menu = new QMenu("&Windows");
  menuBar()->addMenu(pm_menu);
  connect(pm_menu, SIGNAL(aboutToShow()), this, SLOT(slotWindows()));
  menuBar()->addSeparator();

  QMenu *pHelp = new QMenu("&Help", this);
  pHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);
  menuBar()->addMenu(pHelp);

  pm_mdiArea = new QMdiArea;
  pm_mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  pm_mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  setCentralWidget(pm_mdiArea);

  pm_sigMapper = new QSignalMapper(this);
  connect(pm_sigMapper, SIGNAL(mapped(QWidget*)), this, SLOT(slotSetActieveSubWindow(QWidget*)));

  statusBar()->showMessage("Ready", 3000);
}

MDIProgram::~MDIProgram()
{
}

DocWindow *MDIProgram::createNewDoc()
{
  DocWindow *pDoc = new DocWindow(this);
  pm_mdiArea->addSubWindow(pDoc);
  pDoc->setAttribute(Qt::WA_DeleteOnClose);
  pDoc->setWindowTitle("Unnamed Document");
  connect(pDoc,
          SIGNAL(changeWindowTitle(const QString&)),
          this,
          SLOT(slotChangeWindowTitle(const QStting&)));

  return pDoc;
}

void MDIProgram::slotChangeWindowTitle(const QString &str)
{
  qobject_cast<DocWindow *>(sender())->setWindowTitle(str);
}

void MDIProgram::slotNewDoc()
{
  createNewDoc()->show();
}

void MDIProgram::slotLoad()
{
  DocWindow *pDoc = createNewDoc();
  pDoc->slotLoad();
  pDoc->show();
}

void MDIProgram::slotSave()
{
  DocWindow *pDoc = qobject_cast<DocWindow *>(pm_mdiArea);
  if (pDoc) pDoc->slotSave();
}

void MDIProgram::slotSaveAs()
{
  DocWindow *pDic = qobject_cast<DocWindow *>(pm_mdiArea);
  if (pDic) pDic->slotSaveAs();
}

void MDIProgram::slotAbout()
{
  QMessageBox::about(this, "Application", "MDI Example");
}

void MDIProgram::slotWindows()
{
  pm_menu->clear();

  QAction *pAct = pm_menu->addAction("&Cascade",
                                     pm_mdiArea,
                                     SLOT(cascadeSubWindows()));
  pAct->setEnabled(!pm_mdiArea->subWindowList().isEmpty());
  pAct = pm_menu->addAction("&Title",
                            pm_mdiArea,
                            SLOT(titleSubWindows()));
  pAct->setEnabled(!pm_mdiArea->subWindowList().isEmpty());

  pm_menu->addSeparator();
  QList<QMdiSubWindow *> listDoc = pm_mdiArea->subWindowList();
  for (int i = 0; i < listDoc.size(); i++) {
    pAct = pm_menu->addAction("&Action");
    pAct->setCheckable(true);
    pAct->setChecked(pm_mdiArea->activeSubWindow() == listDoc.at(i));
    connect(pAct, SIGNAL(triggered()), pm_sigMapper, SLOT(map()));
  }

}

void MDIProgram::slotSetActieveSubWindow(QWidget *obj)
{
}

