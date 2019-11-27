#ifndef SPINBOX_H
#define SPINBOX_H

#include <QSpinBox>

class SpinBox : public QSpinBox
{
    Q_OBJECT

public:
    SpinBox(QSpinBox *parent = nullptr);
    ~SpinBox();
};
#endif // SPINBOX_H
