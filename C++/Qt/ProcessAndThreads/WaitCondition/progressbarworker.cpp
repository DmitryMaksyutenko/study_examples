#include "progressbarworker.h"

ProgressBarWorker::ProgressBarWorker(QMutex *m,
                                     QWaitCondition *w,
                                     QProgressBar *b)
    : mp_mut(m),
      mp_condition(w),
      mp_progressBar(b)
{
    QObject::connect(this, SIGNAL(valueChanged(int)),
                     mp_progressBar, SLOT(setValue(int)));
}

void ProgressBarWorker::run()
{
    mp_mut->lock();
    mp_condition->wait(mp_mut);
    for (int i = 1; i != 101; i++) {
        msleep(50);
        emit valueChanged(i);
    }
    mp_mut->unlock();
}
