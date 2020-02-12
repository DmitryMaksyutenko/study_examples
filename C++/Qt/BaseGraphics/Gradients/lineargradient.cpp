#include "lineargradient.h"

LinearGradient::LinearGradient(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 500, 500);
}

void LinearGradient::paintEvent(QPaintEvent *event)
{
    //	Linear gradients interpolate colors between start and end points.
    //	Outside these points the gradient is either padded, reflected or
    //	repeated depending on the currently set spread method.
    QLinearGradient gradient(500, 0, height(), width());
    gradient.setColorAt(0.0, Qt::red);
    gradient.setColorAt(0.5, Qt::green);
    gradient.setColorAt(1.0, Qt::blue);
    QPainter painter(this);
    painter.setBrush(gradient);
    painter.drawRect(0, 0, height(), width());

    event->accept();
}
