#include "backendclass.h"

#include <QDebug>

BackEndClass::BackEndClass(QObject *obj) : QObject(obj)
{

}

QString BackEndClass::user_name()
{
    return name;
}

void BackEndClass::set_user_name(const QString &name)
{
    this->name = name;
    emit user_name_changed();
}

void BackEndClass::slot_name_changed()
{
    qDebug() << name;
}
