#include "testlabel.h"
#include <QDebug>

TestLabel::TestLabel(QWidget *obj) : QLabel(obj)
{

}

void TestLabel::paintEvent(QPaintEvent *e)
{
    qDebug() << e->type();
    QPoint pos = getLocation();
    pos.rx() -= 15;
    pos.ry() -= 10;
    QRect rect(pos, QSize(30, 20));
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.drawRect(rect);

    QLabel::paintEvent(e);
}

const QPoint TestLabel::getLocation() const
{
    return QPoint(width() / 2, height() / 2);
}
