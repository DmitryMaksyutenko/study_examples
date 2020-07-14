#include <QCoreApplication>
#include <QDate>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDate date1(2020, 7, 14);
    QDate date2;

    date2 = QDate::fromString("2020.7.20", "yyyy.M.d");

    qDebug() << "date1";
    qDebug() << "is valid: " << date1.isValid();
    qDebug() << "date: " << date1.toString();
    qDebug() << "date in format: " << date1.toString(Qt::ISODate);
    qDebug() << "date in format: " << date1.toString(Qt::RFC2822Date);
    qDebug() << "day: " << date1.day();
    qDebug() << "month: " << date1.month();
    qDebug() << "year: " << date1.year();
    qDebug() << "year: " << date1.year();
    qDebug() << "days in year: " << date1.daysInYear();
    qDebug() << "days in month: " << date1.daysInMonth();
    qDebug() << "day of week: " << date1.dayOfWeek();

    qDebug() << "-------------------------------------";

    qDebug() << "date2";
    qDebug() << "is valid: " << date2.isValid();
    qDebug() << "date: " << date2.toString();
    qDebug() << "date in format: " << date2.toString(Qt::ISODate);
    qDebug() << "date in format: " << date2.toString(Qt::RFC2822Date);
    qDebug() << "day: " << date2.day();
    qDebug() << "month: " << date2.month();
    qDebug() << "year: " << date2.year();
    qDebug() << "year: " << date2.year();
    qDebug() << "days in year: " << date2.daysInYear();
    qDebug() << "days in month: " << date2.daysInMonth();
    qDebug() << "day of week: " << date2.dayOfWeek();

    qDebug() << "-------------------------------------";

    qDebug() << date1.toString() << " < " << date2.toString() << " is: " << (date1 < date2);
    qDebug() << date1.toString() << " > " << date2.toString() << " is: " << (date1 > date2);
    qDebug() << date1.toString() << " add days from "
             << date2.toString() << " is: "
             << date1.addDays(date2.day()).toString();

    return a.exec();
}

