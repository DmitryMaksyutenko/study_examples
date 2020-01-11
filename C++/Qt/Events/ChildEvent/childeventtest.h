#ifndef CHILDEVENTTEST_H
#define CHILDEVENTTEST_H

#include <QWidget>
#include <QChildEvent>

class ChildEventTest : public QWidget
{
    Q_OBJECT

public:
    ChildEventTest(QWidget *obj = nullptr);

protected:
    void childEvent(QChildEvent *e) override;

};

#endif // CHILDEVENTTEST_H
