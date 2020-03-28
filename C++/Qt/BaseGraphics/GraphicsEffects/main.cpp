#include <QApplication>
#include <QGraphicsEffect>
#include <QGraphicsBlurEffect>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsColorizeEffect>
#include <QLabel>
#include <QPixmap>
#include <QFormLayout>

QLabel* lbl(QGraphicsEffect *pge)
{
    QLabel *lbl = new QLabel;
    lbl->setPixmap(QPixmap("/home/dima/Pictures/Linux.png"));

    if(pge) lbl->setGraphicsEffect(pge);

    return lbl;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;

    QGraphicsColorizeEffect *colorized = new QGraphicsColorizeEffect;
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;

    QFormLayout layout;

    layout.addRow("No Effect", lbl(nullptr));
    layout.addRow("Colorized", lbl(colorized));
    layout.addRow("Blur", lbl(blur));
    layout.addRow("shadow", lbl(shadow));

    w.setLayout(&layout);

    w.show();

    return app.exec();
}
