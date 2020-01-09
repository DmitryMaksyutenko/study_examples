#include <QApplication>

#include "testtimer.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    TestTimer a;

    QObject::connect(&a.GetTimer(), SIGNAL(timeout()), &a, SLOT(AgregatedTimer()));

    a.show();
    return app.exec();
}
