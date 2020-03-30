#include <QApplication>

#include "drawelipse.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    DrawElipse elipse;

    elipse.show();

    return app.exec();
}
