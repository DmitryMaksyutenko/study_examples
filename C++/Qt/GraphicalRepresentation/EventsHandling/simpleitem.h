#ifndef SIMPLEITEM_H
#define SIMPLEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>

class SimpleItem : public QGraphicsItem
{
private:
    enum {nPenWidth = 3};

public:
    SimpleItem();

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SIMPLEITEM_H
