#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QRgb>

QImage brightnes(const QImage &origin, int brightnes)
{
    QImage tmpImg = origin;

    qint32 imgHeight = tmpImg.height();
    qint32 imgWidth = tmpImg.width();

    for(qint32 y = 0; y < imgHeight; ++y)
    {
        QRgb *tmpLine = reinterpret_cast<QRgb*>(tmpImg.scanLine(y));

        for(qint32 x = 0; x < imgWidth; ++x)
        {
            int r = qRed(*tmpLine) + brightnes;
            int g = qGreen(*tmpLine) + brightnes;
            int b = qBlue(*tmpLine) + brightnes;
            int a = qAlpha(*tmpLine) + brightnes;

            *tmpLine++ = qRgba(r > 255 ? 255 : r < 0 ? 0 : r,
                               g > 255 ? 255 : g < 0 ? 0 : g,
                               b > 255 ? 255 : b < 0 ? 0 : b,
                               a);
        }
    }

    return tmpImg;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QImage img("/home/dima/Pictures/Linux.png");
    QWidget w;

    QHBoxLayout layout;
    layout.setSpacing(0);

    for(int i = -150; i < 150; i+= 50)
    {
        QLabel *lbl = new QLabel;
        lbl->setFixedSize(img.size());
        lbl->setPixmap(QPixmap::fromImage(brightnes(img, i)));
        layout.addWidget(lbl);
    }

    w.setLayout(&layout);
    w.show();

    return app.exec();
}
