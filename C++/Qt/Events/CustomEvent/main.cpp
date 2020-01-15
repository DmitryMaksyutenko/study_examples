#include <QApplication>
#include "testclass.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TestClass test;

    test.show();
    return app.exec();
}
