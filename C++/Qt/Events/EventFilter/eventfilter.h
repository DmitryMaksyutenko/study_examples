#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QMessageBox>

class EventFilter : public QObject
{
    Q_OBJECT

public:
    EventFilter(QObject *obj = nullptr);

protected:
    //	For the filter realization must be inherited class QObject, and override method eventFilter.
    virtual bool eventFilter(QObject *watched, QEvent *event) override;

};

#endif // EVENTFILTER_H
