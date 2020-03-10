#include "clipregionwidget.h"

#include <QDebug>

ClipRegionWidget::ClipRegionWidget(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 500, 500);
}

void ClipRegionWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QFileInfo fImage("/home/dima/Pictures/Windows.png");
    QPixmap image(150, 160);
    QRect imageArea(QPoint((width() /2) - image.width() / 2, (height() / 2) - image.height() / 2),
                    QPoint((width() /2) + image.width() / 2, (height() / 2) + image.height() / 2));

    QRect a(0, 0, width() / 2, height() / 2);
    QRect b(width() / 2, height() / 2, width(), height());
    painter.setClipRect(a);
    painter.setClipRect(b); // This will be displayed.

    image.load(fImage.absoluteFilePath());
    painter.drawPixmap(imageArea, image);

    event->accept();
}
