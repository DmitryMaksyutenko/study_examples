#include "mainwindow.h"
#include "newthread.h"

#include <QApplication>

const QString priorityToString(QThread::Priority p)
{
    QString result;

    switch (p) {
        case QThread::Priority::LowPriority:
            result = "Thread Priority is LowPriority";
        break;
        case QThread::Priority::HighPriority:
            result = "Thread Priority is HighPriority";
        break;
        case QThread::Priority::IdlePriority:
            result = "Thread Priority is IdlePriority";
        break;
        case QThread::Priority::LowestPriority:
            result = "Thread Priority is LowestPriority";
        break;
        case QThread::Priority::NormalPriority:
            result = "Thread Priority is NormalPriority";
        break;
        case QThread::Priority::HighestPriority:
            result = "Thread Priority is HighestPriority";
        break;
        case QThread::Priority::InheritPriority:
            result = "Thread Priority is InheritPriority";
        break;
        case QThread::Priority::TimeCriticalPriority:
            result = "Thread Priority is TimeCriticalPriority";
        break;
    default:
        result = "No Priority";
    }

    return result;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    NewThread t;
    t.start();

    w.textInsert("New " + priorityToString(t.priority()));
    w.show();

    return a.exec();
}
