#include "widget.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGroupBox colorGroup("Colors");

    QRadioButton colorRed("Red");
    QRadioButton colorBlue("Blue");
    QRadioButton colorGreen("Green");

    colorBlue.setChecked(true);

    QHBoxLayout hBox;
    hBox.addWidget(&colorRed);
    hBox.addWidget(&colorBlue);
    hBox.addWidget(&colorGreen);

    colorGroup.setLayout(&hBox);

    colorGroup.show();
    return a.exec();
}
