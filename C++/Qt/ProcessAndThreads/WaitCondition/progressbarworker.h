#ifndef PROGRESSBARWORKER_H
#define PROGRESSBARWORKER_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QProgressBar>

class ProgressBarWorker : public QThread
{
    Q_OBJECT

private:
    QMutex *mp_mut;
    QWaitCondition *mp_condition;
    QProgressBar *mp_progressBar;

public:
    ProgressBarWorker(QMutex *m,
                      QWaitCondition *w,
                      QProgressBar *b);

    void run() override;

signals:
    void valueChanged(int num);
};

#endif // PROGRESSBARWORKER_H
