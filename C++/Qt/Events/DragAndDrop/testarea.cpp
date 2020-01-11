#include "testarea.h"

#include <QDebug>

TestArea::TestArea(QWidget *obj) : QWidget(obj)
{
    setGeometry(600, 300, 600, 500);
}

void TestArea::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << event->type();
}

void TestArea::dragLeaveEvent(QDragLeaveEvent *event)
{
    qDebug() << event->type();
}

void TestArea::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug() << event->type();
}

void TestArea::dropEvent(QDropEvent *event)
{
    qDebug() << event->type();
}
