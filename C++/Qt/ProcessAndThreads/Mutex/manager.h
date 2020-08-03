#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

#include "mainwindow.h"

class Manager : public QObject
{
    Q_OBJECT

private:
    MainWindow *w;
    Worker *worker;

public:
    Manager(MainWindow *w);
    virtual ~Manager();

public slots:
    void slotDoWork();

};

#endif // MANAGER_H
