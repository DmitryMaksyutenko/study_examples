#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

#include "nwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton buttonX("X");
    buttonX.setFixedSize(16, 16);

    NWindow w;
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.setWindowFlag(Qt::FramelessWindowHint);

    QVBoxLayout layout;
    layout.addWidget(&buttonX);
    layout.addStretch(1);

    w.setLayout(&layout);
    w.show();

    QObject::connect(&buttonX, SIGNAL(clicked()), &w, SLOT(close()));

    return app.exec();
}
