#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets>
#include <QPalette>

class MyClass : public QWidget
{
    Q_OBJECT

public:
    MyClass(QWidget *obj = nullptr);

protected:
    void enterEvent(QEvent *e) override;
    void leaveEvent(QEvent *e) override;
};

#endif // MYCLASS_H
