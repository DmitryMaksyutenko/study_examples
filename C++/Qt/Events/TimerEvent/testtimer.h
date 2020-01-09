#ifndef TESTTIMER_H
#define TESTTIMER_H

#include <QtWidgets>
#include <QTimerEvent>

class TestTimer : public QWidget
{
    Q_OBJECT

private:
    QTimer timer;

public:
    TestTimer(QWidget *obj = nullptr);

    QTimer& GetTimer();

    void RestartTimer();


public slots:
    void AgregatedTimer();

protected:
    void timerEvent(QTimerEvent *e) override;
};

#endif // TESTTIMER_H
