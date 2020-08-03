#include <QApplication>
#include <QTextBlock>
#include <QTextCursor>

#include "mainwindow.h"
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Manager m(&w);

    QObject::connect(w.buttonStart(), SIGNAL(clicked()), &m, SLOT(slotDoWork()));

    w.show();

    return a.exec();
}
