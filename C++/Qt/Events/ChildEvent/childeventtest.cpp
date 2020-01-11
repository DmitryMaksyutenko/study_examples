#include "childeventtest.h"

#include <QDebug>

ChildEventTest::ChildEventTest(QWidget *obj) : QWidget(obj)
{

}

void ChildEventTest::childEvent(QChildEvent *e)
{
    qDebug() << e->type();
}
