#ifndef THREAD_H
#define THREAD_H

#include <QThread>

#include "progressevent.h"

class Thread : public QThread
{
    Q_OBJECT

private:
    QObject *mp_receiver;

public:
    Thread(QObject *obj = nullptr);

    void run() override;
};

#endif // THREAD_H
