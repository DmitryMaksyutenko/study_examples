#ifndef RECTANGELWINDOW_H
#define RECTANGELWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

class RectangelWindow : public QWidget
{
    Q_OBJECT

public:
    RectangelWindow(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // RECTANGELWINDOW_H
