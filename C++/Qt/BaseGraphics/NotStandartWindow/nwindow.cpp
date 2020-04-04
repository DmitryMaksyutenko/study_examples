#include "nwindow.h"

NWindow::NWindow(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 500, 500);
    figure.push_back(QPoint(width() / 2, 0));
    figure.push_back(QPoint(width() / 2 + 50, height() / 2 - 50));

    figure.push_back(QPoint(width() / 2 + 50, height() / 2 - 50));
    figure.push_back(QPoint(width(), height() / 2));

    figure.push_back(QPoint(width() , height() / 2));
    figure.push_back(QPoint(width() / 2 + 50 , height() / 2 + 50));

    figure.push_back(QPoint(width() / 2 + 50 , height() / 2 + 50));
    figure.push_back(QPoint(width() / 2, height()));

    figure.push_back(QPoint(width() / 2, height()));
    figure.push_back(QPoint(width() / 2 - 50, height()/ 2 + 50));

    figure.push_back(QPoint(width() / 2 -50, height() / 2 + 50));
    figure.push_back(QPoint(0, height() / 2));

    figure.push_back(QPoint(0, height() / 2));
    figure.push_back(QPoint(width() /2 - 50, height() / 2 - 50));

    figure.push_back(QPoint(width() /2 - 50, height() / 2 - 50));
    figure.push_back(QPoint(width() /2, 0));

    linesPath.addPolygon(figure);
}

void NWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::red);

    painter.drawPath(linesPath);
    painter.fillPath(linesPath, QBrush(Qt::white));

    event->accept();
}

void NWindow::mousePressEvent(QMouseEvent *e)
{
    mousePosition = e->pos();
}

void NWindow::mouseMoveEvent(QMouseEvent *e)
{
    move(e->globalPos() - mousePosition);
}
