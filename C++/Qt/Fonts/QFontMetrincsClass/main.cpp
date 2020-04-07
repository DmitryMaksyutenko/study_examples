#include <QApplication>
#include <QFontMetrics>
#include <QDebug>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFontMetrics fontMetrics(w.font());

    qDebug() << "width: " << fontMetrics.width("some text") << '\n'
             << "height: " << fontMetrics.height() << '\n'
             << "descent: " << fontMetrics.descent() << '\n'
             << "leading: " << fontMetrics.leading() << '\n'
             << "maxWdth: " << fontMetrics.maxWidth() << '\n'
             << "ascent: " << fontMetrics.ascent() << '\n';

    w.show();
    return a.exec();
}
