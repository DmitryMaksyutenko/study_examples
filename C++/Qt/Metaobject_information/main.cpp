#include "myclass.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClass w;
    w.show();

    QObject obj;

    // Every object created from QObject or inherited from it has QMetaObject class.
    // This class keeps information about signals, slots, about a class itself and its inheritance

    qDebug() << "\n----- Show meta information -----";
    qDebug() << obj.metaObject()->className();
    qDebug() << "--------------------------------------------";
    qDebug() << w.metaObject()->className();
    qDebug() << "method count: " << w.metaObject()->methodCount();
    qDebug() << "method offset: " << w.metaObject()->methodOffset();
    qDebug() << "property count: " << w.metaObject()->propertyCount();
    qDebug() << "class info count: " << w.metaObject()->classInfoCount();
    qDebug() << "enumerator count: " << w.metaObject()->enumeratorCount();
    qDebug() << "construct count: " << w.metaObject()->constructorCount();

    qDebug() << "---------------------------------------------";

    if (w.inherits("QWidget"))
        qDebug() << w.metaObject()->className() << " inherited from QWidget ?" << "TRUE";
    else
        qDebug() << w.metaObject()->className() << " inherited from QWidget ?" << "FALSE";

    qDebug() << "---------------------------------------------";

    if (obj.inherits("QWidget"))
        qDebug() << obj.metaObject()->className() << " inherited from QWidget ?" << "TRUE";
    else
        qDebug() << obj.metaObject()->className() << " inherited from QWidget ?" << "FALSE";
    return a.exec();
}
