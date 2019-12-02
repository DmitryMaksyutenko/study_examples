#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QTreeWidget
{
    Q_OBJECT

private:
    QTreeWidgetItem baseItem;

public:
    Widget(QTreeWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
