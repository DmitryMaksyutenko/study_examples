#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class QPainter;

class Widget : public QCommonStyle
{
public:
    void polish(QWidget *obj) override;
    void unpolish(QWidget *obj) override;
    void drawPrimitive(PrimitiveElement elem,
                       const QStyleOption *pOpt,
                       QPainter *pPainter,
                       const QWidget *pWidg) const override;

};

#endif // WIDGET_H
