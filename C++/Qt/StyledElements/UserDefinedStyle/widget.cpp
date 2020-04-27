#include "widget.h"


void Widget::polish(QWidget *obj)
{
    if(qobject_cast<QPushButton *>(obj))
        obj->setAttribute(Qt::WA_Hover, true);
}

void Widget::unpolish(QWidget *obj)
{
    if(qobject_cast<QPushButton *>(obj))
        obj->setAttribute(Qt::WA_Hover, false);
}

void Widget::drawPrimitive(QStyle::PrimitiveElement elem,
                           const QStyleOption *pOpt,
                           QPainter *pPainter,
                           const QWidget *pWidg) const
{
    switch (elem)
    {
        case PE_PanelButtonCommand:
        {
            const QStyleOptionButton *pOptButton =
                    qstyleoption_cast<const QStyleOptionButton *>(pOpt);
            if(pOptButton)
            {
                bool bDown = (pOptButton->state & State_Sunken) ||
                        (pOptButton->state & State_On);
                QPixmap pix = bDown ? QPixmap(":/img/Linux.png") :
                                      QPixmap(":/img/Windows.png");
                pPainter->drawPixmap(pOptButton->rect, pix);

                bool bHover = (pOptButton->state & State_Enabled) &&
                        (pOptButton->state & State_MouseOver);
                if(bHover)
                {
                    pPainter->fillRect(pOptButton->rect,QColor(25, 97, 45, 83));
                }
            }
            break;
        }
        dafault:
            QCommonStyle::drawPrimitive(elem, pOpt, pPainter, pWidg);
    }
    return;
}
