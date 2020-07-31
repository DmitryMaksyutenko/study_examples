#include <QApplication>

#include "thread.h"

Thread::Thread(QObject *obj)
    : mp_receiver(obj)
{

}

void Thread::run()
{
    for (int i = 0; i <= 100; i++) {
        usleep(100000);
        ProgressEvent *event = new ProgressEvent;
        event->setValue(i);
        QApplication::postEvent(mp_receiver, event);
    }
}
