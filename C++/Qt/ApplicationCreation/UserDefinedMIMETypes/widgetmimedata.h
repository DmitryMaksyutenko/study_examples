#ifndef WIDGETMIMEDATA_H
#define WIDGETMIMEDATA_H

#include <QMimeData>
#include <QWidget>

class WidgetMimeData : public QMimeData
{
private:
    QWidget *mWgt;

public:
    WidgetMimeData();

    static QString mimeType();
    void setWidget(QWidget *obj);
    QWidget *widget() const;
};

#endif // WIDGETMIMEDATA_H
