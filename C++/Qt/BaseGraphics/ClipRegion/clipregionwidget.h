#ifndef CLIPREGIONWIDGET_H
#define CLIPREGIONWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QRegion>
#include <QPoint>
#include <QFileInfo>

class ClipRegionWidget : public QWidget
{
    Q_OBJECT

public:
    ClipRegionWidget(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CLIPREGIONWIDGET_H
