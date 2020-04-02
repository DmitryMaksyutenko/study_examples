#ifndef PIXMAP_H
#define PIXMAP_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class PixMap : public QWidget
{
    Q_OBJECT

public:
    PixMap(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // PIXMAP_H
