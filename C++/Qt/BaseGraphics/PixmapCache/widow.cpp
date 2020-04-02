#include "widow.h"

widow::widow(QWidget *obj) : QWidget(obj)
{}

void widow::paintEvent(QPaintEvent *e)
{
    QPixmap img;
    QPainter painter(this);

    QPixmapCache::find("linux", &img);

    painter.drawPixmap(0, 0, img);

    e->accept();
}
