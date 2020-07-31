#ifndef PROGRESSEVENT_H
#define PROGRESSEVENT_H

#include <QEvent>

class ProgressEvent : public QEvent
{
private:
    int m_value;

public:
    enum {ProgressType = User + 1};

public:
    ProgressEvent();

    void setValue(int val);
    int value() const;
};

#endif // PROGRESSEVENT_H
