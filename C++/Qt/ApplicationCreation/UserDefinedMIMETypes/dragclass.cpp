#include "dragclass.h"


DragClass::DragClass(QWidget *parent)
    : QDrag(parent)
{
}

void DragClass::setWidget(QWidget *obj)
{
    WidgetMimeData *pwdt = new WidgetMimeData;
    pwdt->setWidget(obj);
    setMimeData(pwdt);
}
