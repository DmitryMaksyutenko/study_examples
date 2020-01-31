#include <QCoreApplication>
#include <QColor>
#include <QDebug>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QColor color;
    color.setRgb(123, 123, 123);

    qDebug() << color;

    color = color.lighter(12);
    qDebug() << color;

    color.setRgb(20, 20, 20);
    qDebug() << color;
    color = color.darker(15);
    qDebug() << color;

    return app.exec();
}
