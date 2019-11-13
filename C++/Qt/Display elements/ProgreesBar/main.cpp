#include <QApplication>

#include "Progress.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Progress p;
    p.show();

    return a.exec();
}
