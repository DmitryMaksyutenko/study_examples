#include "worker.h"

Worker::Worker(const QString &str)
{
    m_name = str;
}

void Worker::run()
{
    for (int i = 0; i < 10; i++) {
        sleep(1);
        emit threadText(m_name);
    }
}
