#include "testtimer.h"
#include <QDebug>

TestTimer::TestTimer(QWidget *obj) : QWidget(obj), timer(new QTimer())
{
    timer.start(1000);
    startTimer(1000);
}

QTimer& TestTimer::GetTimer()
{
    return timer;
}

void TestTimer::RestartTimer()
{
    timer.start(1000);
}

void TestTimer::AgregatedTimer()
{
    qDebug() << "Do not calling the timerEvent on this object.";
}

void TestTimer::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == 1)
        resize(width() + 10, height() +10);
    else
        resize(width() - 10, height() - 10);

}
