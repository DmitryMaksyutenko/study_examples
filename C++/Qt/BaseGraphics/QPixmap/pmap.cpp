#include "pmap.h"

PixMap::PixMap(QWidget *obj) : QWidget(obj)
{}

void PixMap::paintEvent(QPaintEvent *e)
{
    QPixmap img(":/img/Linux.png");
    QPainter painter(this);
    QRect r(img.width(), 0, img.width() / 2, img.height());

    painter.drawPixmap(0, 0, img);
    painter.drawPixmap(r, img);

    e->accept();
}
