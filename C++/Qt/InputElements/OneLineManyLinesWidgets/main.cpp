#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit login;
    QLineEdit password;
    QTextEdit information;

    Widget w(&login, &password, &information);
    w.show();
    return a.exec();
}
