#include "worker.h"

Worker::Worker(const QString &name, QStack<QString> *stack, const QTextEdit *te)
    : m_name(name),
    pm_stack(stack)
{
    pm_sem = new QSemaphore(2);
    QObject::connect(this, SIGNAL(sendRow(const QString &)), te, SLOT(append(const QString &)));
}

Worker::~Worker()
{

}

void Worker::run()
{
    pm_sem->acquire(2);
    sleep(1);
    QString str = pm_stack->pop();
    const QString toSend = m_name + " " + str;
    emit sendRow(toSend);
    pm_sem->release(2);
}
