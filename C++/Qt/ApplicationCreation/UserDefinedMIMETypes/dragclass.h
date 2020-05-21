#ifndef DRAGCLASS_H
#define DRAGCLASS_H

#include <QDrag>
#include <QWidget>

#include "widgetmimedata.h"

class DragClass : public QDrag
{

public:
    DragClass(QWidget *parent = nullptr);

    void setWidget(QWidget *obj);
};
#endif // DRAGCLASS_H
