#include <QApplication>

#include "wind.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Wind w;
    w.show();

    return app.exec();
}
