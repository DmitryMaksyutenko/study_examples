#include "bluewindow.h"

BlueWindow::BlueWindow(QWidget *obj) : QWidget(obj)
{
    setGeometry(600, 200, 700, 700);
}

void BlueWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush(Qt::blue);

    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());

    event->accept();
}

void BlueWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        qDebug() << event->type() << " on blue window.";
    }

    event->ignore();
}
