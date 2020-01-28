#include <QApplication>
#include <QWidget>
#include <QPalette>
#include <QDebug>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setGeometry(700, 400, 100, 100);

    QColor color(0, 0, 0);
    QColor color2(255, 255, 255);

    // RGB
    qDebug() << (color == color2);
    qDebug() << color.red();
    qDebug() << color.green();
    qDebug() << color.blue();

    color.setRed(255);
    color.setGreen(70);
    color.setBlue(30);


    // HSV
    /*	H - the color in angle 0 - 360
        S - white color 0 - 255
        V - bright 0 - 255
    */
    QColor color3;
    color3.setHsv(100, 150, 20);

    //	CMYK
    /*
        C - cyan 0 - 255
        M - magneta 0 - 255
        Y - yellow 0 - 255
        K - black 0 - 255
    */
    QColor color4;
    color4.setCmyk(30, 34, 42, 100);

    QPalette p(color4);

    w.setPalette(p);
    w.show();

    return app.exec();
}
