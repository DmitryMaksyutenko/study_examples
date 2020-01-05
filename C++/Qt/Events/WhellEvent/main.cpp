#include <QApplication>
#include "whelltest.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    WheelTest wheel;

    QLabel la(&wheel);
    la.setText("DIRECTION");

    QObject::connect(&wheel, SIGNAL(scrolledUp(const QString)), &la, SLOT(setText(const QString)));
    QObject::connect(&wheel, SIGNAL(scrolledDown(const QString)), &la, SLOT(setText(const QString)));

    wheel.resize(300, 300);
    wheel.show();
    return app.exec();
}
