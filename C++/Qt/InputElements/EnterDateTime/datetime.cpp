#include "datetime.h"

DateTime::DateTime(QDateTimeEdit *parent)
    : QDateTimeEdit(parent)
{
    setDateTime(QDateTime::currentDateTime());
    show();
}

DateTime::~DateTime()
{
}

