#include "greenwindow.h"

GreenWindow::GreenWindow(QWidget *obj) : QWidget(obj)
{
    int xPos = 700;
    int yPos = 400;
    int w = 500;
    int h = 500;

    if(obj != nullptr)
    {
        xPos = (obj->width() - w) / 2;
        yPos = (obj->height() - h) / 2;
    }

    setGeometry(xPos, yPos, w, h);
}


void GreenWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush(Qt::green);

    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());

    event->accept();
}

void GreenWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        qDebug() << event->type() << " on green window.";
    }

    event->ignore();
}
