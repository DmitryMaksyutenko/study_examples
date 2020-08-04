#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QSemaphore>
#include <QStack>
#include <QTextEdit>

class Worker : public QThread
{
    Q_OBJECT

private:
    QString m_name;
    QSemaphore *pm_sem;
    QStack<QString> *pm_stack;

public:
    Worker(const QString &name, QStack<QString> *stack, const QTextEdit *te);
    virtual ~Worker();

    void run() override;

signals:
    void sendRow(const QString &str);
};

#endif // WORKER_H
