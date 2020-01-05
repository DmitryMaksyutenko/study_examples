#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QWidget *obj) : QWidget(obj)
{

}

void MyClass::enterEvent(QEvent *e)
{
    qDebug() << e->type();

    QPalette palette(Qt::red);

    setPalette(palette);
}

void MyClass::leaveEvent(QEvent *e)
{
    qDebug() << e->type();

    QPalette palette(Qt::green);

    setPalette(palette);
}
