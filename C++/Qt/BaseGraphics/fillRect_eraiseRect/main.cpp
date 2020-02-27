#include <QApplication>

#include "rectangelwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    RectangelWindow w;

    w.show();

    return app.exec();
}
