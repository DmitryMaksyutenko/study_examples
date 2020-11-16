#ifndef BACKENDCLASS_H
#define BACKENDCLASS_H

#include <QObject>
#include <qqml.h>

class BackEndClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString user_name READ user_name WRITE set_user_name NOTIFY user_name_changed)
    QML_ELEMENT

private:
    QString name;

public:
    BackEndClass(QObject *obj = nullptr);

    QString user_name();
    void set_user_name(const QString &name);

signals:
    void user_name_changed();


public slots:
    void slot_name_changed();
};

#endif // BACKENDCLASS_H
