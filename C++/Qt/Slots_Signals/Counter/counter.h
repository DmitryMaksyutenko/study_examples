#ifndef COUNTER_H
#define COUNTER_H

// Base class with signals and slots.
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT // Property

private:
    int m_nValue;

public:
    Counter();

public slots:
    void slotIncrement();

signals:
    void goodbye();
    void counterIncrement(int);

};
#endif // COUNTER_H
