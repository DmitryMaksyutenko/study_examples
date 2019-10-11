#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets>

class MyClass : public QObject
{
    Q_OBJECT

public:
    MyClass()
    {
        QSignalMapper *psigMapper = new QSignalMapper(this);
        connect(psigMapper, SIGNAL(mapped(const QString&)),
                this, SLOT(slotShowAction(const QString&)));

        QPushButton *pcmd = new QPushButton("Button1");
        QPushButton *pcmd2 = new QPushButton("Button2");
        pcmd->show();
        pcmd2->show();

        connect(pcmd, SIGNAL(clicked()), psigMapper, SLOT(map()));
        psigMapper->setMapping(pcmd, "Button1 Action");

        connect(pcmd2, SIGNAL(clicked()), psigMapper, SLOT(map()));
        psigMapper->setMapping(pcmd2, "Button2 Action");
    }

    ~MyClass(){}

public slots:
    void slotShowAction(const QString& str)
    {
        qDebug() << str;
    }
};
#endif // MYCLASS_H
