#include "resizeobserver.h"

ResizeObserver::ResizeObserver(QWidget *obj) : QLabel(obj)
{
    setAlignment(Qt::AlignCenter);
}

void ResizeObserver::resizeEvent(QResizeEvent *e)
{
    setText(QString("Resized")
            + "\n width() = " + QString::number(e->size().width())
            + "\n height() = " + QString::number(e->size().height()));
}
