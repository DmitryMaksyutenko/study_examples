#include "redwindow.h"

RedWindow::RedWindow(QWidget *obj) : QWidget(obj)
{
    int xPos = 700;
    int yPos = 400;
    int w = 300;
    int h = 300;

    if(obj != nullptr)
    {
        xPos = (obj->width() - w) / 2;
        yPos = (obj->height() - h) / 2;
    }

    setGeometry(xPos, yPos, w, h);
}

void RedWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush(Qt::red);

    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());

    event->accept();
}

void RedWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        qDebug() << event->type() << " on red window.";
    }

    event->ignore();
}
