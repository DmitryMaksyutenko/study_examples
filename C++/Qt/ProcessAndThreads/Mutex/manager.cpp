#include "manager.h"

Manager::Manager(MainWindow *obj)
{
    w = obj;
}

Manager::~Manager()
{

}


void Manager::slotDoWork() {

    int n = w->threadNumber();
    for (int i = 1; i <= n; i++) {
        Worker *worker = new Worker("Thread " + QString().number(i));
        QObject::connect(worker, SIGNAL(threadText(QString)), w, SLOT(slotTextAppend(QString)));
        worker->start();
    }
}
