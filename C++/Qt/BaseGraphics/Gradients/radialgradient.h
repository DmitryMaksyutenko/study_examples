#ifndef RADIALGRADIENT_H
#define RADIALGRADIENT_H

#include <QWidget>
#include <QPaintEvent>
#include <QRadialGradient>
#include <QPainter>
#include <QPoint>

class RadialGradient : public QWidget
{
    Q_OBJECT

public:
    RadialGradient(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // RADIALGRADIENT_H
