#include <QApplication>

#include "pyramid.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Pyramid p;
    p.resize(200, 200);
    p.show();

    return app.exec();
}
