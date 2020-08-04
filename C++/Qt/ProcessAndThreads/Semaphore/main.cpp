#include <QApplication>
#include <QStack>

#include "mainwindow.h"
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QStack<QString> strStack;
    strStack << "row 1" << "row 2" << "row 3" << "row 4" << "row 5"
             << "row 6" << "row 7" << "row 8" << "row 9" << "row 10";

    Manager m(&strStack, &w);

    QObject::connect(w.buttonStart(), SIGNAL(clicked()), &m, SLOT(run()));

    w.show();
    return a.exec();
}
