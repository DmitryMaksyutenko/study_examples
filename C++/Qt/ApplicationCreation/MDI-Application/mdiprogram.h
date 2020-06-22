#ifndef MDIPROGRAM_H
#define MDIPROGRAM_H

#include <QWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMdiArea>
#include <QSignalMapper>

#include "docwindow.h"

class MDIProgram : public QMainWindow
{
    Q_OBJECT

  private:
    QMdiArea *pm_mdiArea;
    QMenu *pm_menu;
    QSignalMapper *pm_sigMapper;

    DocWindow *createNewDoc();

  public:
    MDIProgram(QWidget *parent = nullptr);
    ~MDIProgram();

  private slots:
    void slotChangeWindowTitle(const QString&);
    void slotNewDoc();
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotAbout();
    void slotWindows();
    void slotSetActieveSubWindow(QWidget*);
};
#endif // MDIPROGRAM_H
