#include <QApplication>

#include "mainwindow.h"
#include "threadmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile f("test");
    QReadWriteLock l;

    ReadWriteThread t1("Thread one", &f, w.textArea(), &l);
    ReadWriteThread t2("Thread two", &f, w.textArea(), &l);

    ThreadManager m;
    m.setThreads(&t1, &t2);
    m.setTextEdit(w.textArea());

    QObject::connect(w.buttonStart(), SIGNAL(clicked()), &m, SLOT(run()));

    w.show();
    return a.exec();
}
