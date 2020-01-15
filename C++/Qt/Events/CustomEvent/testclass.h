#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QLabel>

class TestClass : public QWidget
{
    Q_OBJECT

private:
    int quantity;
    QLabel quantityLabel;

public:
    TestClass(QWidget *obj = nullptr);

protected:
    bool event(QEvent *event) override;

};

#endif // TESTCLASS_H
