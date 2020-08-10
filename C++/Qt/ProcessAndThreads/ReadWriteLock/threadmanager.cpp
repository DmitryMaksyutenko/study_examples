#include "threadmanager.h"

ThreadManager::ThreadManager(QObject *parent)
    : QObject(parent)
{

}

void ThreadManager::setThreads(ReadWriteThread *one, ReadWriteThread *two)
{
    mp_t1 = one;
    mp_t2 = two;
}

void ThreadManager::setTextEdit(QTextEdit *t)
{
    mp_textArea = t;
}

void ThreadManager::run()
{
    mp_t1->start();
    mp_t2->start();

    QObject::connect(mp_t1, SIGNAL(text(const QString &)), mp_textArea, SLOT(setPlainText(const QString &)));
    QObject::connect(mp_t2, SIGNAL(text(const QString &)), mp_textArea, SLOT(setPlainText(const QString &)));
}
