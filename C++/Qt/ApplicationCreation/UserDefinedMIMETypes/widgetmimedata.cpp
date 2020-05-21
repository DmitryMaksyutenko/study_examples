#include "widgetmimedata.h"

WidgetMimeData::WidgetMimeData()
    : QMimeData()
{

}

QString WidgetMimeData::mimeType()
{
    return "application/widget";
}

void WidgetMimeData::setWidget(QWidget *obj)
{
    mWgt = obj;
    setData(mimeType(), QByteArray());
}

QWidget *WidgetMimeData::widget() const
{
    return mWgt;
}
