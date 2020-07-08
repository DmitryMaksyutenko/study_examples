#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QImage>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QFile file("testFile.bin");
    QImage img(":img/Linux.png");
    QDataStream dStream;

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "file don't opened.";
        app.exit();
    } else {
        dStream.setVersion(QDataStream::Qt_5_5);
        dStream.setDevice(&file);
        dStream << QPoint(19, 23) << img;
        file.close();
    }

    QPoint newPoint;
    QImage newImg;

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "file don't opened.";
        app.exit();
    } else {
        dStream.setVersion(QDataStream::Qt_5_5);
        dStream.setDevice(&file);
        dStream >> newPoint >> newImg;
        qDebug() << newPoint;
        file.close();
    }

    return app.exec();
}

