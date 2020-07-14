#include <QCoreApplication>
#include <QTime>
#include <QDebug>

void foo()
{
    for(int i = 0; i < 100000000; i+= 2){
       i--;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTime t1(2, 43, 55, 0);
    QTime t2;

    t2 = QTime::fromString("0:01:00:000", "h:mm:ss:zzz");

    qDebug() << "current time: " << QTime::currentTime().toString();

    qDebug() << "----------------------";

    qDebug() << "t1";
    qDebug() << "t1 is valid: " << t1.isValid();
    qDebug() << "t1: " << t1.toString();
    qDebug() << "t1 in format: " << t1.toString("H:mm:ss:zzz");
    qDebug() << "t1 hour: " << t1.hour();
    qDebug() << "t1 minutes: " << t1.minute();
    qDebug() << "t1 seconds: " << t1.second();
    qDebug() << "t1 milliseconds: " << t1.msec();

    qDebug() << "----------------------";

    qDebug() << "t2";
    qDebug() << "t2 is valid: " << t2.isValid();
    qDebug() << "t2: " << t2.toString();
    qDebug() << "t2 in format: " << t2.toString("H:mm:ss:zzz");
    qDebug() << "t2 hour: " << t2.hour();
    qDebug() << "t2 minutes: " << t2.minute();
    qDebug() << "t2 seconds: " << t2.second();
    qDebug() << "t2 milliseconds: " << t2.msec();

    qDebug() << "----------------------";

    qDebug() << t1.toString() << " < " << t2.toString() << (t1 < t2);
    qDebug() << t1.toString() << " == " << t2.toString() << (t1 == t2);
    qDebug() << t1.toString() << " > " << t2.toString() << (t1 > t2);

    qDebug() << "----------------------";

    QTime test;
    test.start();
    foo();
    qDebug() << "foo work time is: " << test.elapsed() << " msec.";

    return a.exec();
}

