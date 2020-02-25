#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPointF>
#include <QtMath>
#include <QDebug>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // WINDOW_H
