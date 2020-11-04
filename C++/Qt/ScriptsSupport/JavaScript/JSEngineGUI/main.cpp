#include <QApplication>
#include <QJSEngine>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lableVidget;

    QJSEngine jsEngine;
    QJSValue jsLable = jsEngine.newQObject(&lableVidget);

    jsEngine.globalObject().setProperty("lable", jsLable);
    jsEngine.evaluate("lable.text = 'Hello World!'");
    jsEngine.evaluate("lable.show()");

    return a.exec();
}
