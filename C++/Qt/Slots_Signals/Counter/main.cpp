#include <QtWidgets>
#include "counter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel lbl("0");
    QPushButton cmd("Add");
    Counter counter;

    lbl.show();
    cmd.show();

    // clicked signal connect with slotIncrement slot from Counter object.
    // Every click call coressponding method.
    QObject::connect(&cmd, SIGNAL(clicked()),
                     &counter, SLOT(slotIncrement()));

    // Signal counterIncrement from Counter object connect with setNum slot of Label object.
    QObject::connect(&counter, SIGNAL(counterIncrement(int)),
                     &lbl, SLOT(setNum(int)));

    //  Singal goodbye of Counter object connect with quit slot of application object.
    QObject::connect(&counter, SIGNAL(goodbye()),
                     &app, SLOT(quit()));

    return app.exec();
}
