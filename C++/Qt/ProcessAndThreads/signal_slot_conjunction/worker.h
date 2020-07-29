#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>

class Worker : public QObject
{
    Q_OBJECT
private:
    int m_nValue;
    QTimer *pm_timer;

public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void valueChanged(int);
    void finished();

public slots:
    void slotDoWork();

private slots:
    void setNextValue();

};

#endif // WORKER_H
