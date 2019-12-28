#include <QApplication>

#include "painteventexampleclass.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    PaintEventExampleClass pIvent;

    pIvent.show();
    return app.exec();
}
