#include "drag.h"

#include <QMimeData>

Drag::Drag(QWidget *parent)
  : QLabel("Draggable text.", parent)
{
  setGeometry(500, 300, 150, 150);
}

Drag::~Drag()
{}

void Drag::startDrag()
{
    QMimeData *pMimeData = new QMimeData;
    pMimeData->setText(text());
    QDrag *pDrag = new QDrag(this);
    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(QPixmap(":img/Linux.png"));
    pDrag->exec();
}

void Drag::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
      mMouseDragPosition = ev->pos();

    QWidget::mousePressEvent(ev);
}

void Drag::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton) {
      int distance = (ev->pos() - mMouseDragPosition).manhattanLength();
      if(distance > QApplication::startDragDistance())
        startDrag();
    }
    QWidget::mouseMoveEvent(ev);
}

