#include "blink.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Blink w(1000);
    w.show();
    return a.exec();
}
