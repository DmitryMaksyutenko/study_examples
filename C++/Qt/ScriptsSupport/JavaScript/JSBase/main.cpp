#include <QCoreApplication>
#include <QDebug>
#include <QJSEngine>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QJSEngine scripEngine;
    QJSValue result = scripEngine.evaluate("1 + 3");

    qDebug() << result.toInt();

    return a.exec();
}
