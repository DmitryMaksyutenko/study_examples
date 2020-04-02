#include "wind.h"

Wind::Wind(QWidget *obj) : QWidget(obj)
{

}

void Wind::paintEvent(QPaintEvent *event)
{
    QBitmap imgLinux(":/img/Linux.png");
    QBitmap imgBiLevel(":/img/bi-level.png");

    QPainter painter(this);
    painter.drawPixmap(0, 0, imgLinux);
    painter.drawPixmap(imgLinux.width(), 0, imgBiLevel);

    event->accept();
}
