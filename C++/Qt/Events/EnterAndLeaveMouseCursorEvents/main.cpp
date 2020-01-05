#include <QApplication>
#include "myclass.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MyClass a;

    a.resize(300, 300);
    a.show();
    return app.exec();
}
