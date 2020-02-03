#include "paintertest.h"

PainterTest::PainterTest(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 400, 400);
}

void PainterTest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.drawLine(QLine({0, 0}, {400, 400}));

    if(event->type() == QEvent::Paint)
    {
        QWidget tmp(this);
        tmp.setGeometry(500, 200, 200, 200);

        painter.begin(&tmp);
        painter.drawLine(QLine({0, 200}, {200, 0}));
        painter.end();

    }
}
