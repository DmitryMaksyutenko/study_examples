#ifndef MOVEPICTURE_H
#define MOVEPICTURE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <QRect>

class MovePicture : public QWidget
{
    Q_OBJECT

    QPixmap image;
    int x;
    int y;
    int imageWidth;
    int imageHeight;

    int for_x_Translate;
    int for_y_Translate;
    qreal for_x_Scale;
    qreal for_y_Scale;
    qreal forRotate;

public:
    MovePicture(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MOVEPICTURE_H
