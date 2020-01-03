#include <QApplication>
#include "mouseobserver.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    MouseObserver observer;
    observer.setMouseTracking(true);

    observer.resize(250, 130);
    observer.show();
    return app.exec();
}
