#include <QApplication>

#include "brushtestclass.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    BrushTestClass test;

    test.show();

    return app.exec();
}
