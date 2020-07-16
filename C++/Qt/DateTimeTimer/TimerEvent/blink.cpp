#include <QApplication>
#include <QFont>

#include "blink.h"

void Blink::timerEvent(QTimerEvent *event)
{
    if (isVisible()) hide();
    else show();

    QObject::timerEvent(event);
}

Blink::Blink(int interval, QWidget *parent)
    : QLabel(parent),
      interval(interval)
{
    setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(40);
    setFont(font);
    setText("Text.");
    resize(300, 300);

    startTimer(interval);
}

Blink::~Blink()
{
}

