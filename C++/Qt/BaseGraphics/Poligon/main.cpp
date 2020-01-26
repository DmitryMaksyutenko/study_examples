#include <QCoreApplication>
#include <QPolygon>
#include <QDebug>

int main (int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QPolygon pol;
    pol << QPoint(10, 30) << QPoint(10, 20) << QPoint(30 , 30);

    qDebug() << pol;
    qDebug() << pol.boundingRect();
    qDebug() << *pol.data();
    qDebug() << pol.last();
    qDebug() << pol.first();

    return app.exec();
}
