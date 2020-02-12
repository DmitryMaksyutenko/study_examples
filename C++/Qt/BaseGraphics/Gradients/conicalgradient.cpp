#include "conicalgradient.h"

ConicalGradient::ConicalGradient(QWidget *obj) : QWidget(obj)
{
    setGeometry(600, 400, 500, 500);
}

void ConicalGradient::paintEvent(QPaintEvent *event)
{
    //	Conical gradients interpolate colors counter-clockwise around a center point.
    QPoint center(width() / 2, height() / 2);
    QConicalGradient gradient(center, 10.0);
    gradient.setColorAt(0.0, Qt::yellow);
    gradient.setColorAt(1.0, Qt::red);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(gradient);
    painter.drawRect(0, 0, height(), width());

    event->accept();
}
