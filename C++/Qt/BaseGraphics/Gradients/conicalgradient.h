#ifndef CONICALGRADIENT_H
#define CONICALGRADIENT_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QConicalGradient>
#include <QPoint>

class ConicalGradient : public QWidget
{
    Q_OBJECT

public:
    ConicalGradient(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // CONICALGRADIENT_H
