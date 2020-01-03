#include "mouseobserver.h"

MouseObserver::MouseObserver(QWidget *obj) : QLabel(obj)
{
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions\n(Press mouse button)");
}

void MouseObserver::mousePressEvent(QMouseEvent *e)
{
    dumpEvent(e, "Mouse Pressed");
}

void MouseObserver::mouseReleaseEvent(QMouseEvent *e)
{
    dumpEvent(e, "Mouse Released");
}

void MouseObserver::mouseMoveEvent(QMouseEvent *e)
{
    dumpEvent(e, "Mouse is Move");
}

void MouseObserver::dumpEvent(QMouseEvent *e, const QString &message)
{
    setText(message + "\n buttons() = " + buttonsInfo(e)
            + "\n x() = " + QString::number(e->x())
            + "\n y() = " + QString::number(e->y())
            + "\n globalX() = " + QString::number(e->globalX())
            + "\n globalY() = " + QString::number(e->globalY())
            + "\n modifiers() = " + modifiersInfo(e));
}

QString MouseObserver::modifiersInfo(QMouseEvent *e)
{
    QString str;

    if(e->modifiers() & Qt::ShiftModifier) str += "Shift";
    if(e->modifiers() & Qt::ControlModifier) str += "Control";
    if(e->modifiers() & Qt::AltModifier) str += "Alt";

    return str;
}

QString MouseObserver::buttonsInfo(QMouseEvent *e)
{
    QString str;

    if(e->buttons() & Qt::LeftButton) str += "Left";
    if(e->buttons() & Qt::RightButton) str += "Right";
    if(e->buttons() & Qt::MiddleButton) str += "Middle";

    return str;
}
