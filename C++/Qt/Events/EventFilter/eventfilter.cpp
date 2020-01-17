#include "eventfilter.h"

EventFilter::EventFilter(QObject *obj) : QObject(obj)
{

}

bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(static_cast<QMouseEvent *>(event)->button() == Qt::LeftButton)
        {
            QString text = watched->metaObject()->className();
            QMessageBox::information(0, "Class name ", text);

            //	Not send to a parent.
            return true;
        }
    }

    //	Send to parent.
    return false;
}
