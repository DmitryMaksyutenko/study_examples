#ifndef ADD_H
#define ADD_H

#include <QObject>

class Add : public QObject
{
    Q_OBJECT
public:
    Add();

    qint64 addition(qint64 lhs, qint64 rhs);
};

#endif // ADD_H
