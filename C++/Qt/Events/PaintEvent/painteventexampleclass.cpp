#include "painteventexampleclass.h"
#include <QMessageBox>

PaintEventExampleClass::PaintEventExampleClass()
    : QWidget()
{
    setGeometry(50, 50, 300, 400);
}

void PaintEventExampleClass::paintEvent(QPaintEvent *event)
{
    //	The QPainter class performs low-level painting on widgets and other paint devices.
    //	QPainter provides highly optimized functions to do most of the drawing GUI programs require.
    //	It can draw everything from simple lines to complex shapes like pies and chords.
    //	It can also draw aligned text and pixmaps. Normally, it draws in a "natural" coordinate system,
    //	but it can also do view and world transformation. QPainter can operate on any object
    //	that inherits the QPaintDevice class.
    //
    //	The common use of QPainter is inside a widget's paint event: Construct and customize
    //	(e.g. set the pen or the brush) the painter. Then draw. Remember to destroy the
    //	QPainter object after drawing.
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    QRect rect(100, 100, 90, 170);
    QRect rect1(400, 700, 50, 70);

    //	QRegion is used with QPainter::setClipRegion() to limit the paint area to what needs to be painted.
    //	There is also a QWidget::repaint() function that takes a QRegion parameter.
    //	QRegion is the best tool for minimizing the amount of screen area to be updated by a repaint.

    //	This class is not suitable for constructing shapes for rendering, especially as outlines.
    //	Use QPainterPath to create paths and shapes for use with QPainter.

    // Returns true if the region overlaps the rectangle rect, otherwise returns false.
    if(event->region().contains(rect))
        painter.drawRect(rect);

    //	Out from region.
    if(!event->region().contains(rect1))
    {
        auto a = new QMessageBox(this);
        a->setText("Rectangle out of region");
        a->show();
    }
}
