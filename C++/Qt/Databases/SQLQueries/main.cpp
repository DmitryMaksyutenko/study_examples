#include <QApplication>

#include "mainwindow.h"
#include "dbtestclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DBTestClass db;

    QObject::connect(&db, SIGNAL(connected()),
                     &w, SLOT(slotSetLableConnected()));
    QObject::connect(&db, SIGNAL(connectionError(const QString &)),
                     &w, SLOT(slotChangeTextAreaData(const QString &)));
    QObject::connect(&w, SIGNAL(nextClicked()), &db, SLOT(slotNextData()));
    QObject::connect(&w, SIGNAL(previousClicked()), &db, SLOT(slotPreviousData()));
    QObject::connect(&db, SIGNAL(next(const QString &)),
                     &w, SLOT(slotChangeTextAreaData(const QString&)));
    QObject::connect(&db, SIGNAL(previous(const QString &)),
                     &w, SLOT(slotChangeTextAreaData(const QString&)));
    w.show();
    return a.exec();
}
