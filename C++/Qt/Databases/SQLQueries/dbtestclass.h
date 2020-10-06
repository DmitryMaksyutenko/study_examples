#ifndef DBTESTCLASS_H
#define DBTESTCLASS_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

class DBTestClass : public QObject
{
    Q_OBJECT

public:
    DBTestClass(QObject *obj = nullptr);
    ~DBTestClass();

private:
    void createTable() const;
    void dropTable() const;
    void insertValues();
    void selectAll();

signals:
    void connected();
    void connectionError(const QString &);
    void next(const QString&);
    void previous(const QString&);

public slots:
    void slotNextData();
    void slotPreviousData();

private:
    QSqlDatabase m_db;
    QSqlQuery *mp_query;
    const QString m_tableName;
    QString m_data;
};


#endif // DBTESTCLASS_H
