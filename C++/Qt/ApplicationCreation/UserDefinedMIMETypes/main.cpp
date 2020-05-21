#include <QApplication>

#include "dropclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DropClass d1;
    DropClass d2;

    d1.setWindowTitle("Widget 1");
    d1.setObjectName("Widget 1");
    d1.resize(200, 200);
    d1.show();

    d2.setWindowTitle("Widget 2");
    d2.setObjectName("Widget 2");
    d2.resize(200, 200);
    d2.show();

    return a.exec();
}
