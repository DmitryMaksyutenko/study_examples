#ifndef GREENWINDOW_H
#define GREENWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include <QDebug>

class GreenWindow : public QWidget
{
    Q_OBJECT

public:
    GreenWindow(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // GREENWINDOW_H
