#include <QApplication>
#include <QtWidgets>
#include <QFile>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;

    QPushButton b1("Button1");
    QPushButton b2("Button2");
    QPushButton b3("Button3");

    QVBoxLayout vbl;
    vbl.addWidget(&b1);
    vbl.addWidget(&b2);
    vbl.addWidget(&b3);

    w.setLayout(&vbl);

    QFile file(":/newStyle.qss");
    file.open(QFile::ReadOnly);
    QString css = QLatin1String(file.readAll());

    app.setStyleSheet(css);

    w.show();

    return app.exec();
}
