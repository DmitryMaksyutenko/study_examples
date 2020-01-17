#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "eventfilter.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton pButton("QPushButton");
    pButton.installEventFilter(new EventFilter(&pButton));
    pButton.show();

    QLabel lab("QLabel");
    lab.installEventFilter(new EventFilter(&lab));
    lab.show();


    QLineEdit lEdit("QLineEdit");
    lEdit.installEventFilter(new EventFilter(&lEdit));
    lEdit.show();

    return app.exec();
}
