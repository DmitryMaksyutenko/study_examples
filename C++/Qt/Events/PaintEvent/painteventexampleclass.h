#ifndef PAINTEVENTEXAMPLECLASS_H
#define PAINTEVENTEXAMPLECLASS_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

//	The QPaintEvent class contains event parameters for paint events.
//	Paint events are sent to widgets that need to update themselves,
//	for instance when part of a widget is exposed because a covering widget was moved.

//	The event contains a region() that needs to be updated, and a rect() that is the bounding rectangle of that region.
//	Both are provided because many widgets cannot make much use of region(), and rect() can be much faster than region().boundingRect().

class PaintEventExampleClass : public QWidget
{
    Q_OBJECT

public:
    PaintEventExampleClass();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // PAINTEVENTEXAMPLECLASS_H
