#include <QApplication>

#include "bluewindow.h"
#include "greenwindow.h"
#include "redwindow.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    BlueWindow blueWindow;
    GreenWindow greenWindow(&blueWindow);
    RedWindow redWindow(&greenWindow);

    blueWindow.show();
    greenWindow.show();
    redWindow.show();

    return app.exec();
}
