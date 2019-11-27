#ifndef DATETIME_H
#define DATETIME_H

#include <QDateTimeEdit>

class DateTime : public QDateTimeEdit
{
    Q_OBJECT

public:
    DateTime(QDateTimeEdit *parent = nullptr);
    ~DateTime();
};
#endif // DATETIME_H
