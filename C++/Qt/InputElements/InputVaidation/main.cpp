#include "inputvalidator.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wi;
    QLabel label("No digits!");

    QLineEdit text;

    InputValidator valid(&text);

    text.setValidator(&valid);
    label.setBuddy(&text);

    QVBoxLayout vBox;
    vBox.addWidget(&label);
    vBox.addWidget(&text);
    wi.setLayout(&vBox);
    wi.show();

    return a.exec();
}
