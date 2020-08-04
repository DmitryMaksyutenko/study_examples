#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QStack>

#include "worker.h"
#include "mainwindow.h"

class Manager : public QObject
{
    Q_OBJECT

private:
    Worker *pm_worker;
    QStack<QString> *pm_stack;
    MainWindow *pm_mw;

public:
    Manager(QStack<QString> *stack, MainWindow *w);
    virtual ~Manager();

public slots:
    void run();
};

#endif // MANAGER_H
