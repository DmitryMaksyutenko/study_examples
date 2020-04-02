#include <QApplication>

#include "widow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPixmap img(":img/Linux.png");

    QPixmapCache imgCache;
    imgCache.insert("linux" ,img);

    widow w;
    w.show();

    return app.exec();
}
