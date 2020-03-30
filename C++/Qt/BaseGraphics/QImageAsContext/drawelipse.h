#ifndef DRAWELIPSE_H
#define DRAWELIPSE_H

#include <QWidget>
#include <QPaintEvent>
#include <QImage>
#include <QPainter>

class DrawElipse : public QWidget
{
    Q_OBJECT

public:
    DrawElipse(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // DRAWELIPSE_H
