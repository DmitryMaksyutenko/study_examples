#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QCheckBox normal("The normal check box");
    normal.setChecked(true);

    QCheckBox tristate("The treesrate chack box");
    tristate.setTristate(true);
    tristate.setCheckState(Qt::PartiallyChecked);

    QVBoxLayout vBox;
    vBox.addWidget(&normal);
    vBox.addWidget(&tristate);

    w.setLayout(&vBox);
    w.show();
    return a.exec();
}
