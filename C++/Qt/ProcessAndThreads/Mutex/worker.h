#ifndef WORKER_H
#define WORKER_H

#include <QThread>

class Worker : public QThread
{
    Q_OBJECT

private:
    QString m_name;

public:
    explicit Worker(const QString &str);
    void run() override;

signals:
    void threadText(const QString &str);
};

#endif // WORKER_H
