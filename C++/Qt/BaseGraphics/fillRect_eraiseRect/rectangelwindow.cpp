#include "rectangelwindow.h"

RectangelWindow::RectangelWindow(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 500, 500);
}

void RectangelWindow::paintEvent(QPaintEvent *event)
{
    QRect a(50, 50, 400, 400);

    QPainter painter(this);
    painter.fillRect(a, QBrush(Qt::Dense4Pattern));
    painter.eraseRect(a.x() + 10, a.y() + 10,
                      a.width() - 20, a.height() - 20);

    event->accept();
}
