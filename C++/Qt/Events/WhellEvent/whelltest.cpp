#include "whelltest.h"
#include <QDebug>

WheelTest::WheelTest(QWidget *obj) : QWidget(obj)
{

}

void WheelTest::wheelEvent(QWheelEvent *e)
{
    //	angleDelta() method return the angle of mouse wheel rotate.
    QPoint angle = e->angleDelta();
    //	pixelDelta() method return the pixels value of touchpad scrolled area.
    QPoint pixels = e->pixelDelta();

    // If methods returns the positive value, the wheel was turned forward.
    // If methods returns the negative value, the wheel was rotate back.

    if(!angle.isNull())
    {
        if(angle.y() > 0) emit scrolledUp(QString("UP"));
        if(angle.y() < 0) emit scrolledDown(QString("DOWN"));
    }
    else if(!pixels.isNull())
    {
        if(angle.y() > 0) emit scrolledUp(QString("UP"));
        if(angle.y() < 0) emit scrolledDown(QString("DOWN"));
    }
}
