#include "widget.h"

Widget::Widget(QTreeWidget *parent)
    : QTreeWidget(parent)
{
    baseItem = QTreeWidgetItem(parent);
}

Widget::~Widget()
{
}
