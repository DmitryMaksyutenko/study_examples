#ifndef READWRITETHREAD_H
#define READWRITETHREAD_H

#include <QThread>
#include <QTextEdit>
#include <QFile>
#include <QReadWriteLock>

class ReadWriteThread : public QThread
{
    Q_OBJECT

private:
    QFile *mp_file;
    QTextEdit *mp_textArea;
    QReadWriteLock *mp_rvLock;
    QString m_threadName;

public:
    ReadWriteThread(QString n,
                    QFile *f = nullptr,
                    QTextEdit *t = nullptr,
                    QReadWriteLock *l = nullptr);
    virtual ~ReadWriteThread();

    void run() override;

signals:
    void text(const QString &srt);
};

#endif // READWRITETHREAD_H
