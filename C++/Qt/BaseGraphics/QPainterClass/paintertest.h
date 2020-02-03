#ifndef PAINTERTEST_H
#define PAINTERTEST_H

#include <QPainter>
#include <QPaintEvent>
#include <QLine>
#include <QWidget>

class PainterTest : public QWidget
{
    Q_OBJECT

public:
    PainterTest(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // PAINTERTEST_H
