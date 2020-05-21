#include "dropclass.h"

#include <QApplication>
#include "dragclass.h"


DropClass::DropClass()
{
    setAcceptDrops(true);
}

void DropClass::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
        mDragPos = ev->pos();
    QWidget::mousePressEvent(ev);
}

void DropClass::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
        int distance = (ev->pos() - mDragPos).manhattanLength();
        if(distance > QApplication::startDragDistance())
            startDrag();
    }
    QWidget::mouseMoveEvent(ev);
}

void DropClass::dragEnterEvent(QDragEnterEvent *ev)
{
    if(ev->mimeData()->hasFormat(WidgetMimeData::mimeType()))
        ev->acceptProposedAction();
}

void DropClass::dropEvent(QDropEvent *ev)
{
    const WidgetMimeData *pMimeData =
            dynamic_cast<const WidgetMimeData *>(ev->mimeData());
    if(pMimeData)
    {
        QWidget *pWidt = pMimeData->widget();
        QString str("Widget is dropped\n ObjectName: %1");
        setText(str.arg(pWidt->objectName()));
    }
}

void DropClass::startDrag()
{
    DragClass *pDrag = new DragClass(this);
    pDrag->setWidget(this);
    pDrag->exec(Qt::CopyAction);
}
