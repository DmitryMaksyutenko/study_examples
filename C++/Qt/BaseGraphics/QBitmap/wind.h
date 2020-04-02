#ifndef WIND_H
#define WIND_H

#include <QWidget>
#include <QPaintEvent>
#include <qbitmap.h>
#include <QPainter>

class Wind : public QWidget
{
    Q_OBJECT
public:
    Wind(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // WIND_H
