#include <QApplication>
#include <QtSql>
#include <QDebug>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("dvdrental");
    db.setUserName("test_role");
    db.setPassword("0000");

    if (db.open()) {
        w.connected();
    } else {
        qDebug() << db.lastError();
    }

    w.show();
    return a.exec();
}
