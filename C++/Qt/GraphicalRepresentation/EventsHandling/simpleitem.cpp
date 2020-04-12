#include "simpleitem.h"

SimpleItem::SimpleItem()
{

}

QRectF SimpleItem::boundingRect() const
{
    QPointF ptPosition(-10 - nPenWidth, -10 - nPenWidth);
    QSizeF size(20 + nPenWidth * 2, 20 + nPenWidth * 2);
    return QRectF(ptPosition, size);
}

void SimpleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setPen(QPen(Qt::blue, nPenWidth));
    painter->drawEllipse(-10, -10, 20 ,20);
    painter->restore();
}

void SimpleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QApplication::setOverrideCursor(Qt::PointingHandCursor);
    QGraphicsItem::mousePressEvent(event);
}

void SimpleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QApplication::restoreOverrideCursor();
    QGraphicsItem::mouseReleaseEvent(event);
}
