#include "dbtestclass.h"

#include <QDebug>

#include <QTimer>
#include <QVariant>

DBTestClass::DBTestClass(QObject *obj)
    : QObject(obj),
      m_tableName("TestTable"),
      m_data("")
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("qt_test_db");
    m_db.setUserName("qt_test_role");
    m_db.setPassword("qt1234");

    if (m_db.open()) {
        QTimer::singleShot(0, this, SIGNAL(connected()));
        createTable();
        insertValues();
        selectAll();
    } else {
        QSqlError err = m_db.lastError();
        const QString error = err.text();
        QTimer::singleShot(0, this, [error, this](){connectionError(error);});
    }

}

DBTestClass::~DBTestClass()
{
    dropTable();
    m_db.close();
    delete mp_query;
}

void DBTestClass::createTable() const
{
    QSqlQuery query("CREATE TABLE IF NOT EXISTS " + m_tableName + "("
                                "id SERIAL PRIMARY KEY NOT NULL,"
                                "test_col_1 CHAR(5) NOT NULL,"
                                "test_col_2 INT NOT NULL"
                   ");");
}

void DBTestClass::dropTable() const
{
    QSqlQuery query("DROP TABLE IF EXISTS " + m_tableName + ";");
}

void DBTestClass::insertValues()
{
    QSqlQuery query;
    query.prepare("INSERT INTO " + m_tableName + "(test_col_1, test_col_2) "
                  "VALUES (:chars, :int);");

    for (int i = 0; i < 1000; i++) {
        QVariant ch(QString("a" + QString::number(i)));
        QVariant in(i);
        query.bindValue(":chars", ch);
        query.bindValue(":int", in);
        query.exec();
    }
}

void DBTestClass::selectAll()
{
    mp_query = new QSqlQuery(m_db);
    mp_query->exec("SELECT * FROM " + m_tableName + ";");
}

void DBTestClass::slotNextData()
{
    if (mp_query->next()) {
        QString nextData = "id: " + mp_query->value(0).toString() + "\n";
        nextData += "col_1: " + mp_query->value(1).toString() + "\n";
        nextData += "col_2: " + mp_query->value(2).toString() + "\n";
        emit next(nextData);
    } else {
        emit next("NO DATA.");
    }
}

void DBTestClass::slotPreviousData()
{
    if (mp_query->previous()) {
        QString prevData = "id: " + mp_query->value(0).toString() + "\n";
        prevData += "col_1: " + mp_query->value(1).toString() + "\n";
        prevData += "col_2: " + mp_query->value(2).toString() + "\n";
        emit previous(prevData);
    } else {
        emit previous("NO DATA.");
    }
}
