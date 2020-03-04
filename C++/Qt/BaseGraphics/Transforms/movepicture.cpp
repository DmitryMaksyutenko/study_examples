#include "movepicture.h"

#include <QDebug>

MovePicture::MovePicture(QWidget *obj) : QWidget(obj)
{
    setGeometry(700, 400, 500, 500);
    image.load("/home/dima/Pictures/Linux.png");
    imageWidth = 100;
    imageHeight = 110;
    x = (width() / 2) - (imageWidth / 2);
    y = (height() / 2) - (imageWidth / 2);

    for_x_Translate = 0;
    for_y_Translate = 0;
    for_x_Scale = 1.0;
    for_y_Scale = 1.0;
    forRotate = 0.0;
}

void MovePicture::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(event->region().contains({x, y, imageWidth, imageHeight}))
    {
        painter.translate(for_x_Translate, for_y_Translate);
        painter.scale(for_x_Scale, for_y_Scale);
        painter.rotate(forRotate);
        painter.drawPixmap(x, y, imageWidth, imageHeight, image);
    }

    event->ignore();
}

void MovePicture::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key::Key_Up)
    {
        for_y_Translate -= 10;
        update();
    }
    if(event->key() == Qt::Key::Key_Down)
    {
        for_y_Translate += 10;
        update();
    }
    if(event->key() == Qt::Key::Key_Left)
    {
        for_x_Translate -= 10;
        update();
    }
    if(event->key() == Qt::Key::Key_Right)
    {
        for_x_Translate += 10;
        update();
    }
    if(event->key() == Qt::Key::Key_S)
    {
        for_x_Scale += 0.2;
        for_y_Scale += 0.2;
        update();
    }
    if(event->key() == Qt::Key::Key_R)
    {
        forRotate += 10.0;
        update();
    }

    event->accept();
}
