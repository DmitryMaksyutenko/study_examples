#include "trajectory.h"

Trajectory::Trajectory(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 500, 500);
}

void Trajectory::paintEvent(QPaintEvent *event)
{
    QPainterPath path;
    QPointF p1(width(), height() / 2);
    QPointF p2(width() / 2, -height());
    QPointF p3(width() / 2, height() * 2);
    QPointF p4(0, height() / 2);

    path.moveTo(p1);
    path.cubicTo(p2, p3, p4);

    QRect rect(width() / 4, height() / 4, width() / 2, height() / 2);
    path.addRect(rect);
    path.addEllipse(rect);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::blue, 6));
    painter.drawPath(path);

    event->accept();
}
