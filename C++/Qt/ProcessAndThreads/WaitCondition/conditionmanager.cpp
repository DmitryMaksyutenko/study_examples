#include "conditionmanager.h"

ConditionManager::ConditionManager(QWaitCondition *w, QObject *obj)
    : QObject(obj),
      mp_condition(w)
{
    m_workerList.reserve(5);
    m_isRunning = false;
}

void ConditionManager::addToWorkerList(ProgressBarWorker *obj)
{
    m_workerList.append(obj);
}

void ConditionManager::startWorkers()
{
    foreach (auto i, m_workerList) {
        if (i->isRunning()) {
            continue;
        } else {
            i->start();
        }
    }
}

void ConditionManager::slotCondition()
{
    startWorkers();
    mp_condition->wakeAll();
}
