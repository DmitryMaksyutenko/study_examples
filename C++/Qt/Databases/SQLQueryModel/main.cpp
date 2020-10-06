#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QTableView>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dvdrental");
    db.setUserName("test_role");
    db.setPassword("0000");

    QTableView tableview;

    if (db.open()) {
        qDebug() << "CONNECTED!";
    } else {
        qDebug() << "NO CONNECTION!";
        return -1;
    }

    QSqlQueryModel qModel;
    qModel.setQuery("SELECT * FROM film;");
    tableview.setModel(&qModel);
    tableview.show();
    db.close();

    return a.exec();
}
