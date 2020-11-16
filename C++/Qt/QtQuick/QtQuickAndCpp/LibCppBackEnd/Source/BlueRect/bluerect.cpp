#include "bluerect.h"

BlueRect::BlueRect(QQuickPaintedItem *obj) : QQuickPaintedItem(obj)
{
}

QString BlueRect::name()
{
    return obj_name;
}

void BlueRect::set_name(const QString &name)
{
    obj_name = name;
}

QColor BlueRect::color()
{
    return obj_color;
}

void BlueRect::set_color(const QColor &color)
{
    obj_color = color;
}

void BlueRect::paint(QPainter *painter)
{
    QPen pen(obj_color, 2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, false);
    painter->drawRect(0, 0, 200,200);
    setProperty("color", "red");
}
