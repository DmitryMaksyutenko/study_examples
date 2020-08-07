#ifndef CONDITIONMANAGER_H
#define CONDITIONMANAGER_H

#include <QObject>
#include <QWaitCondition>
#include <QList>

#include "progressbarworker.h"

class ConditionManager : public QObject
{
    Q_OBJECT

private:
    QWaitCondition *mp_condition;
    QList<ProgressBarWorker*> m_workerList;
    bool m_isRunning;

public:
    ConditionManager(QWaitCondition *w, QObject *obj = nullptr);

    void addToWorkerList(ProgressBarWorker *obj);
    void startWorkers();

public slots:
    void slotCondition();

};

#endif // CONDITIONMANAGER_H
