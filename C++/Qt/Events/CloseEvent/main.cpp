#include <QApplication>

#include "testclose.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TestClose w;

    w.show();
    return app.exec();
}
