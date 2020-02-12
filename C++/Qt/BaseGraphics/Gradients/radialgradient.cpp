#include "radialgradient.h"

RadialGradient::RadialGradient(QWidget *obj) : QWidget(obj)
{
    setGeometry(500, 400, 500, 500);
}

void RadialGradient::paintEvent(QPaintEvent *event)
{
    QPoint center(width() / 2, height() / 2);
    QRadialGradient gradient(center, 250, {250, 250});
    gradient.setColorAt(0.0, Qt::blue);
    gradient.setColorAt(1.0, Qt::green);
    QPainter painter(this);
    painter.setBrush(gradient);
    painter.drawRect(0, 0, width(), height());

    event->accept();
}
