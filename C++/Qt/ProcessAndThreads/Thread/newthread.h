#ifndef NEWTHREAD_H
#define NEWTHREAD_H

#include <QThread>

class NewThread : public QThread
{
    Q_OBJECT

public:
    NewThread();

    void run() override;

protected slots:
    void slotShowTime();

};

#endif // NEWTHREAD_H
