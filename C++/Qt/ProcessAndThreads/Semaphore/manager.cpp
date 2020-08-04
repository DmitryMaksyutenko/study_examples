#include "manager.h"

Manager::Manager(QStack<QString> *stack, MainWindow *w)
    : pm_stack(stack),
     pm_mw(w)
{

}

Manager::~Manager()
{

}

void Manager::run()
{
    for (int i = 1; i != 5; i++) {
        pm_worker = new Worker("thread " + QString::number(i), pm_stack, pm_mw->textArea());
        pm_worker->start();
    }
}
