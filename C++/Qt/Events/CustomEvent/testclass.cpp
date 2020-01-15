#include "testclass.h"
#include <QDebug>

TestClass::TestClass(QWidget *obj) :
    QWidget(obj),
    quantity(0),
    quantityLabel(QString::number(quantity))
{
    quantityLabel.setAlignment(Qt::AlignCenter);
    quantityLabel.setText(QString::number(quantity));
    quantityLabel.resize(120, 30);
    quantityLabel.show();
}

bool TestClass::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *pKeyEvent = static_cast<QKeyEvent *>(event);

        if(pKeyEvent->key() == Qt::Key_Space)
            quantityLabel.setText(QString::number(++quantity));
    }

    return QWidget::event(event);
}
