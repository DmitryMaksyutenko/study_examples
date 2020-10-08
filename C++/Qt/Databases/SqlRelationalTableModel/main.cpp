#include <QApplication>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView tableView;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dvdrental");
    db.setUserName("test_role");
    db.setPassword("0000");

    QSqlRelationalTableModel relTableModel;
    QSqlRelation categoryRel("category", "category_id", "name");
    QSqlRelation filmRel("film", "film_id", "title");

    if (db.open()) {
        qDebug() << "CONNECTED";
    } else {
        qDebug() << "NO CONNECTION";
        return -1;
    }

    relTableModel.setTable("film_category");
    relTableModel.setRelation(0, filmRel);
    relTableModel.setRelation(1, categoryRel);
    relTableModel.select();

    tableView.setModel(&relTableModel);
    tableView.resize(600, 800);
    tableView.setColumnWidth(0, 200);
    tableView.setColumnWidth(1, 150);
    tableView.setColumnWidth(2, 200);

    tableView.show();
    return a.exec();
}
