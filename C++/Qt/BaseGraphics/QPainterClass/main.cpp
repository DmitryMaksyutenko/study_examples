#include <QApplication>

#include "paintertest.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    PainterTest widget;

    widget.show();
    return app.exec();
}
