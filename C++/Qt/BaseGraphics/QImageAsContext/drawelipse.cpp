#include "drawelipse.h"

DrawElipse::DrawElipse(QWidget *obj) : QWidget(obj)
{

}

void DrawElipse::paintEvent(QPaintEvent *event)
{
    QImage img(size(), QImage::Format_RGBA64_Premultiplied);
    QPainter painter;

    painter.begin(&img);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.eraseRect(rect());
    painter.drawEllipse(0, 0, size().width(), size().height());
    painter.end();

    painter.begin(this);
    painter.drawImage(0, 0, img);
    painter.end();

    event->accept();
}
