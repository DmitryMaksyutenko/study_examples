#ifndef BRUSHTESTCLASS_H
#define BRUSHTESTCLASS_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QRect>
#include <QPoint>
#include <QSize>
#include <QLinearGradient>
#include <QConicalGradient>
#include <QRadialGradient>
#include <QPixmap>

class BrushTestClass : public QWidget
{
    Q_OBJECT

public:
    BrushTestClass(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool IsRightBorder(int rectTopRight, int rectTopLeft);
    void SetBrushStyle(QPainter &obj, QRect rect, int val);
};

#endif // BRUSHTESTCLASS_H
