#include <QApplication>
//#include <QSize>	// For decimal numbres.
//#include <QSizeF>	// For float point numbers.
#include <QPixmap>
#include <QLabel>
#include <QDebug>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QPixmap img("/home/dima/Pictures/Linux.png");
    QLabel wrap;
    wrap.setGeometry(700, 400, img.width(), img.height());

    QSize newSize;

    if(argc == 1)
    {
        qDebug() << argv[0];
        wrap.setPixmap(img);
        wrap.show();
    }
    else
    {
        QString arg(argv[1]);
        if(arg == "ignore")
        {
            qDebug() << argv[1];
            //	Change the original size, setting it as specified.
            newSize.scale(400, 400, Qt::IgnoreAspectRatio);
            wrap.resize(newSize);
            wrap.setPixmap(img.scaled(newSize));
            wrap.show();
        }
        if(arg == "keep")
        {
            qDebug() << argv[1];
            //	Saev the original propotions.
            newSize.scale(700, 400, Qt::KeepAspectRatio);
            wrap.resize(newSize);
            wrap.setPixmap(img.scaled(newSize));
            wrap.show();
        }
        if(arg == "keepexp")
        {
            qDebug() << argv[1];
            //	New size can be out of a specified size.
            newSize.scale(400, 400, Qt::KeepAspectRatioByExpanding);
            wrap.setPixmap(img.scaled(newSize));
            wrap.show();
        }
    }

    return app.exec();
}
