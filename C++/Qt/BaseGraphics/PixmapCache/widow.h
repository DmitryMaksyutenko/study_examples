#ifndef WIDOW_H
#define WIDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmapCache>

class widow : public QWidget
{
    Q_OBJECT

public:
    widow(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // WIDOW_H
