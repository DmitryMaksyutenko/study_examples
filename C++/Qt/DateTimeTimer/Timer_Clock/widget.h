#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QDateTime>
#include <QTimer>

class Widget : public QLabel
{
    Q_OBJECT

private:
    QTimer m_timer;
    QTimer m_closeTimer;
    QDateTime m_dateTime;

public:
    Widget(int timeRange, QWidget *parent = nullptr);
    ~Widget();


public slots:
    void timeChange();
};
#endif // WIDGET_H
