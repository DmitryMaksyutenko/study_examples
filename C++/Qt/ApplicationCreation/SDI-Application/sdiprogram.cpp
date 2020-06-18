#include "sdiprogram.h"

#include <QtWidgets>
#include <QMessageBox>

SDIProgram::SDIProgram(QWidget *parent) : QMainWindow(parent)
{
  QMenu *pm_file = new QMenu("&File", this);
  QMenu *pm_help = new QMenu("&Help", this);
  DocWindow *pm_doc = new DocWindow(this);

  pm_file->addAction("&Open...",
                     pm_doc,
                     SLOT(slotLoad()),
                     QKeySequence("CTRL+O"));
  pm_file->addAction("&Save...",
                     pm_doc,
                     SLOT(slotSave()),
                     QKeySequence("CTRL+S"));
  pm_file->addAction("&Save As...",
                     pm_doc,
                     SLOT(slotSaveAs()));
  pm_file->addSeparator();
  pm_file->addAction("&Quit",
                     qApp,
                     SLOT(quit()),
                     QKeySequence("CTRL+Q"));
  pm_help->addAction("&About",
                     this,
                     SLOT(slotAbout()),
                     Qt::Key_F1);
  menuBar()->addMenu(pm_file);
  menuBar()->addMenu(pm_help);

  setCentralWidget(pm_doc);
  connect(pm_doc,
          SIGNAL(changeWindowTitle(const QString &)),
          this,
          SLOT(slotChangeWindowTitle(const QString &)));
  statusBar()->showMessage("Ready", 2000);
}

void SDIProgram::slotAbout()
{
  QMessageBox::about(this, "Application", "SDI example");
}

void SDIProgram::slotChangeWindowTitle(const QString &str)
{
  setWindowTitle(str);
}
