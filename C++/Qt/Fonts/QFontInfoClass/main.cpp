#include <QApplication>
#include <QFontInfo>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFontInfo fontInfo(w.font());
    w.addItemToList(fontInfo.family());
    w.addItemToList(fontInfo.styleName());

    w.show();
    return a.exec();
}
