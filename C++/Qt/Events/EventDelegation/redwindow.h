#ifndef REDWINDOW_H
#define REDWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include <QDebug>

class RedWindow : public QWidget
{
    Q_OBJECT

public:
    RedWindow(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // REDWINDOW_H
