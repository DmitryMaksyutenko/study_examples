#include "readwritethread.h"
#include <QDebug>

ReadWriteThread::ReadWriteThread(QString n,
                                 QFile *f,
                                 QTextEdit *t,
                                 QReadWriteLock *l)
    : mp_file(f),
      mp_textArea(t),
      mp_rvLock(l),
      m_threadName(n)
{
    m_threadName += "\n";
}

ReadWriteThread::~ReadWriteThread()
{

}

void ReadWriteThread::run()
{
    mp_rvLock->lockForWrite();
    mp_file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    mp_file->write(m_threadName.toUtf8().data());
    mp_file->close();
    mp_rvLock->unlock();

    mp_rvLock->lockForRead();
    mp_file->open(QIODevice::ReadOnly | QIODevice::Text);
    QString tmp = mp_file->readAll();
    emit text(tmp + m_threadName);
    mp_file->close();
    mp_rvLock->unlock();
}
