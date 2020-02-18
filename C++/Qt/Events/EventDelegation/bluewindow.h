#ifndef BLUEWINDOW_H
#define BLUEWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include <QDebug>

class BlueWindow : public QWidget
{
    Q_OBJECT

public:
    BlueWindow(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // BLUEWINDOW_H
