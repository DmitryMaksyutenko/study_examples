#include "widget.h"

#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QLCDNumber lcd;
    QSpinBox spinBox;

    lcd.setSegmentStyle(QLCDNumber::Flat);
    lcd.setMode(QLCDNumber::Hex);

    spinBox.setFixedHeight(30);

    QObject::connect(&spinBox, SIGNAL(valueChanged(int)), &lcd, SLOT(display(int)));

    QVBoxLayout vLayout;
    vLayout.addWidget(&lcd);
    vLayout.addWidget(&spinBox);

    w.setLayout(&vLayout);

    w.resize(250, 150);
    w.show();
    return a.exec();
}
