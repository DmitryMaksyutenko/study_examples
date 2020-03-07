#include <QApplication>

#include "trajectory.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Trajectory tr;
    tr.show();

    return app.exec();
}
