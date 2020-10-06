#include <QApplication>
#include <QSql>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("qt_test");
    db.setUserName("qt_test_role");
    db.setPassword("qt1234");

    if (db.open()) {
        qDebug() << "CONNECTED!";
    } else {
        qDebug() << "NO CONNECTION!";
        return -1;
    }

    QSqlQuery query("CREATE TABLE test_user ("
                    "first_name VARCHAR(30) NOT NULL,"
                    "last_name VARCHAR(30) NOT NULL"
                    ");");

    QSqlTableModel tModel;
    QTableView tableView;

    tModel.setTable("test_user");
    tModel.setEditStrategy(QSqlTableModel::OnRowChange);

    QSqlRecord record = tModel.record();
    record.setValue("first_name", "Dima");
    record.setValue("last_name", "LastName");

    tModel.insertRecord(-1, record);

    tableView.setModel(&tModel);
    tableView.show();

    return a.exec();
}
