#include "brushtestclass.h"
#include <QDebug>

BrushTestClass::BrushTestClass(QWidget *obj) : QWidget(obj)
{
    setGeometry(650, 350, 600, 600);
}

void BrushTestClass::paintEvent(QPaintEvent *event)
{
    if(event->type() == QEvent::Paint)
    {
        QPainter painter(this);
        QBrush brush;
        QPoint a(10, 10);
        QSize rectSize(130, 80);
        qint8 indent = 5;

        for(int i = 1; i < 19; i++)
        {
            QRect tmpRect(a, rectSize);

            SetBrushStyle(painter, tmpRect, i);
            painter.drawRect(tmpRect);

            int newXPosition = rectSize.rwidth() + indent;

            if(IsRightBorder(a.rx() + rectSize.rwidth(), newXPosition))
            {
                a.rx() = 10 - newXPosition;
                a.ry() += rectSize.rheight() + indent;
            }

            a.rx() += newXPosition;
        }
    }
}

bool BrushTestClass::IsRightBorder(int rectTopRight, int rectTopLeft)
{
    if(rectTopRight > width() - rectTopLeft)
        return true;

    return false;
}

void BrushTestClass::SetBrushStyle(QPainter &obj, QRect rect, int val)
{
    switch (val) {
        case 15:
        {
            QLinearGradient gradient(rect.topLeft(), rect.bottomRight());
            gradient.setColorAt(0.0, Qt::red);
            gradient.setColorAt(1.0, Qt::blue);
            obj.setBrush(gradient);
            return;
        }
        case 16:
        {
            QPoint center(rect.x() + rect.width() / 2,
                          rect.y() - rect.height() / 2);
            QConicalGradient gradient(center, 70.0);
            gradient.setColorAt(0.0, Qt::green);
            gradient.setColorAt(1.0, Qt::red);
            obj.setBrush(gradient);
            return;
        }

        case 17:
        {
            QPoint center(rect.x() + rect.width() / 2,
                          rect.y() - rect.height() / 2);
            QRadialGradient gradient(center, 140);
            gradient.setColorAt(0.0, Qt::blue);
            gradient.setColorAt(1.0, Qt::white);
            obj.setBrush(gradient);
            return;
        }

        case 18:
        {
            QPixmap picture("/home/dima/Pictures/Linux.png");
            picture.scaled(rect.width(),
                           rect.height(),
                           Qt::AspectRatioMode::IgnoreAspectRatio,
                           Qt::TransformationMode::FastTransformation);
            obj.setBrush(QBrush(picture));
            return;
        }
    }

    obj.setBrush(QBrush(Qt::BrushStyle(val)));
}
