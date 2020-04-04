#ifndef NWINDOW_H
#define NWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPolygon>

class NWindow : public QWidget
{
    Q_OBJECT

    QPainterPath linesPath;
    QPolygon figure;
    QPoint mousePosition;

public:
    NWindow(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
};

#endif // NWINDOW_H
