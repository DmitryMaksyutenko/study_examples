#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent),
  m_nValue(30)
{
    pm_timer = new QTimer(this);

    connect(pm_timer, SIGNAL(timeout()), this, SLOT(setNextValue()));
}

void Worker::slotDoWork()
{
    pm_timer->start(1000);
}

void Worker::setNextValue()
{
    emit valueChanged(--m_nValue);
    if (!m_nValue) {
        pm_timer->stop();
        emit finished();
    }
}
