#include "guidownloader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiDownloader w;

    w.resize(280, 100);
    w.show();
    return a.exec();
}
