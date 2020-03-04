#include <QApplication>

#include "movepicture.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MovePicture w;

    w.show();

    return app.exec();
}
