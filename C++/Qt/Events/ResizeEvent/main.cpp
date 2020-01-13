#include <QApplication>

#include "resizeobserver.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    ResizeObserver w;

    w.resize(250, 130);
    w.show();
    return app.exec();
}
