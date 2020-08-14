#include <QApplication>

#include "server.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srv::Server w(8001);
    w.show();

    return a.exec();
}
