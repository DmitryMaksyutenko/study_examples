#include <QApplication>

#include "childeventtest.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    ChildEventTest chEvTest;

    QWidget w;
    w.setParent(&chEvTest);


    chEvTest.show();
    return app.exec();
}
