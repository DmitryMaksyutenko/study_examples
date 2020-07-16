#include "widget.h"

Widget::Widget(int timeRange, QWidget *parent)
    : QLabel(parent)
{
    m_dateTime = QDateTime::currentDateTime();
    setText(m_dateTime.toString("ddd MMMM d yy h:m:a ap"));
    setAlignment(Qt::AlignCenter);
    m_timer.start(1000);
    m_closeTimer.setSingleShot(true);
    m_closeTimer.start(timeRange);
    resize(300, 100);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(timeChange()), Qt::DirectConnection);
    connect(&m_closeTimer, SIGNAL(timeout()), this, SLOT(close()), Qt::DirectConnection);
}

Widget::~Widget()
{
}

void Widget::timeChange()
{
    m_dateTime = QDateTime::currentDateTime();
    setText(m_dateTime.toString("ddd MMMM d yy h:m:s ap"));
}
