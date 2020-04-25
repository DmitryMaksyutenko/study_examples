#include <QApplication>
#include <QtWidgets>

QWidget *newStyle(QStyle *pStyle)
{
    QGroupBox *pGb = new QGroupBox(pStyle->metaObject()->className());
    QScrollBar *pSb = new QScrollBar(Qt::Horizontal);
    QCheckBox *pChBox = new QCheckBox("&Check Box");
    QSlider *pSlider = new QSlider(Qt::Horizontal);
    QRadioButton *pRButton = new QRadioButton("&Radio Button");
    QPushButton *pPushButton = new QPushButton("&Push Button");

    QVBoxLayout *pVBLayout = new QVBoxLayout;
    pVBLayout->addWidget(pSb);
    pVBLayout->addWidget(pChBox);
    pVBLayout->addWidget(pSlider);
    pVBLayout->addWidget(pRButton);
    pVBLayout->addWidget(pPushButton);
    pGb->setLayout(pVBLayout);

    QList<QWidget *> pwidgList = pGb->findChildren<QWidget *>();

    foreach (QWidget *item, pwidgList)
        item->setStyle(pStyle);

    return pGb;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget widget;

    QHBoxLayout *pHBlayout = new QHBoxLayout;

    foreach(QString str, QStyleFactory::keys())
        pHBlayout->addWidget(newStyle(QStyleFactory::create(str)));

    widget.setLayout(pHBlayout);
    widget.show();

    return app.exec();
}
