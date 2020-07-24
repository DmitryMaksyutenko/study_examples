#include "newthread.h"

#include <QDebug>
#include <QTimer>
#include <QTime>

NewThread::NewThread()
{
    QTimer *t = new QTimer(this);
    t->start(1000);

    connect(t, SIGNAL(timeout()), this, SLOT(slotShowTime()), Qt::DirectConnection);
}

void NewThread::run()
{
    qDebug() << "The new thread started.";
}

void NewThread::slotShowTime()
{
    qDebug() << "Time: " << QTime::currentTime().toString();
}
