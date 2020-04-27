#include <QApplication>

#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QPushButton *pButtonA = new QPushButton("Button1");
    QPushButton *pButtonB = new QPushButton("Button2");
    QPushButton *pButtonC = new QPushButton("Button3");

    QVBoxLayout *pVBL = new QVBoxLayout;
    pVBL->addWidget(pButtonA);
    pVBL->addWidget(pButtonB);
    pVBL->addWidget(pButtonC);

    w.setLayout(pVBL);
    a.setStyle(new Widget);

    w.show();
    return a.exec();
}
