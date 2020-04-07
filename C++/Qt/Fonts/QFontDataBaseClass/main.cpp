#include <QApplication>
#include <QFontDatabase>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFontDatabase fontBase;
    QStringList fonts = fontBase.families();

    foreach (QString var, fonts)
        w.appendText(var);

    w.show();
    return a.exec();
}
