#ifndef BLINK_H
#define BLINK_H

#include <QLabel>
#include <QTimerEvent>

class Blink : public QLabel
{
    Q_OBJECT

private:
    int interval;

protected:
    void timerEvent(QTimerEvent *event);

public:
    Blink(int interval, QWidget *parent = nullptr);
    ~Blink();

};
#endif // BLINK_H
