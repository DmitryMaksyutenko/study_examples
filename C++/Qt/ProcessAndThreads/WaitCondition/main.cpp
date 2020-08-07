#include <QApplication>

#include "mainwindow.h"
#include "progressbarworker.h"
#include "conditionmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWaitCondition conditinonObj;
    ConditionManager manager(&conditinonObj, &w);
    QMutex mutex;

    ProgressBarWorker w1(&mutex, &conditinonObj, w.progressBarOne());
    ProgressBarWorker w2(&mutex, &conditinonObj, w.progressBarTwo());
    ProgressBarWorker w3(&mutex, &conditinonObj, w.progressBarThree());

    manager.addToWorkerList(&w1);
    manager.addToWorkerList(&w2);
    manager.addToWorkerList(&w3);

    QObject::connect(w.buttonStart(), SIGNAL(clicked()),
                     &manager, SLOT(slotCondition()));

    w.show();
    return a.exec();
}
