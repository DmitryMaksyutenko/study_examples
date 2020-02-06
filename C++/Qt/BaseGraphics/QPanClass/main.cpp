#include <QApplication>

#include "pentestclass.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    PenTestClass test;

    test.show();

    return app.exec();
}
