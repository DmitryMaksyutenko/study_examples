#ifndef BLUERECT_H
#define BLUERECT_H

#include <QObject>
#include <QtQuick/QQuickPaintedItem>
#include <QString>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <qqml.h>

class BlueRect : public QQuickPaintedItem
{
    Q_PROPERTY(QString name READ name WIRTE set_name)
    Q_PROPERTY(QColor color READ color WIRTE set_color)
    QML_ELEMENT

private:
    QString obj_name;
    QColor obj_color;

public:
    BlueRect(QQuickPaintedItem *obj = nullptr);

    QString name();
    void set_name(const QString &name);
    QColor color();
    void set_color(const QColor &color);
    void paint(QPainter *painter);
};

#endif // BLUERECT_H
