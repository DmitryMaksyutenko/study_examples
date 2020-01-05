#ifndef WHELLTEST_H
#define WHELLTEST_H

#include <QtWidgets>
#include <QWheelEvent>

class WheelTest : public QWidget
{
    Q_OBJECT

public:
    WheelTest(QWidget *obj = nullptr);

protected:
    void wheelEvent(QWheelEvent *e) override;

signals:
    void scrolledUp(const QString);
    void scrolledDown(const QString);
};

#endif // WHELLTEST_H
