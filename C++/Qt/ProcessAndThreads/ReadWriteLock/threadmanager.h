#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QTextEdit>

#include "readwritethread.h"

class ThreadManager : public QObject
{
    Q_OBJECT

private:
    ReadWriteThread *mp_t1;
    ReadWriteThread *mp_t2;
    QTextEdit *mp_textArea;

public:
    explicit ThreadManager(QObject *parent = nullptr);

    void setThreads(ReadWriteThread *one, ReadWriteThread *two);
    void setTextEdit(QTextEdit *t);

public slots:
    void run();
};

#endif // THREADMANAGER_H
