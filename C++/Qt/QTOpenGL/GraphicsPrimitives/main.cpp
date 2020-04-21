#include <QApplication>

#include "primitives.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Primitives p;
    p.resize(400, 400);
    p.show();

    return app.exec();
}
