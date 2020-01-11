#include <QApplication>

#include "testarea.h"
#include "testwidget.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TestArea areaWidget;
    TestWidget testWidget;

    areaWidget.show();
    testWidget.show();
    return app.exec();
}
