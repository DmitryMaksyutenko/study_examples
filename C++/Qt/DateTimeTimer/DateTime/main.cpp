#include <QCoreApplication>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QTimeZone>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDateTime dt1 = QDateTime::currentDateTime();
    QDateTime dt2(QDate::currentDate(),
                  QTime::currentTime(),
                  QTimeZone::systemTimeZone());

    qDebug() << "dt1";
    qDebug() << "dt1: " << dt1.toString();
    qDebug()<< "dt1 in format: " << dt1.toString("d:mm:yyyy:h:mm:ss:zzz");
    qDebug()<< "dt1 date: " << dt1.date().toString();
    qDebug()<< "dt1 time: " << dt1.time().toString();

    qDebug() << "------------------------------------";

    qDebug()<< "dt2";
    qDebug()<< "dt2: " << dt2.toString();
    qDebug()<< "dt2 in format: " << dt2.toString("d:mm:yyyy:h:mm:ss:zzz");
    qDebug()<< "dt2 date: " << dt2.date().toString();
    qDebug()<< "dt2 time: " << dt2.time().toString();

    return a.exec();
}
