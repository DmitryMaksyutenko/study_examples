#include "window.h"

Window::Window(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 500, 500);
}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::red, 2));


    int points = 80;
    QPointF pointsList[points];
    float radius = 150.4;

    //	Draw points.
    for (int i = 0; i < points; i++)
    {
        qreal fAngle = 	::qDegreesToRadians(360.0 * i / points);
        qreal X = (width() / 2) + qCos(fAngle) * radius;
        qreal Y = (height() / 2) + qSin(fAngle) * radius;
        pointsList[i].setX(X);
        pointsList[i].setY(Y);

        painter.drawPoint(QPointF(X, Y));

        qDebug() << "angle = " << fAngle;
        qDebug() << "X point = " << X;
        qDebug() << "Y point = " << Y;
    }

    //	Draw Lines.
    painter.drawPolyline(pointsList, points);
    painter.drawLine(pointsList[0].rx(), pointsList[0].ry(),
            pointsList[points - 1].rx(), pointsList[points - 1].ry());

    event->accept();
}
