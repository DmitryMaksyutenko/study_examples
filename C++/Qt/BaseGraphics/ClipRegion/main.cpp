#include <QApplication>

#include "clipregionwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ClipRegionWidget w;

    w.show();

    return app.exec();
}
