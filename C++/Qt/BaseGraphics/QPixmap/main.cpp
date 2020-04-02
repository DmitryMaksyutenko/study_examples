#include <QApplication>

#include "pmap.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    PixMap pMap;
    pMap.show();

    return app.exec();
}
