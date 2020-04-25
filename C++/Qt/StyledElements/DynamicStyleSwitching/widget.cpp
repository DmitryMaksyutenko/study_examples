#include "widget.h"

#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QComboBox *pComBox = new QComboBox;
    QSpinBox *pSpinBox = new QSpinBox;
    QSlider *pSlider = new QSlider(Qt::Horizontal);
    QRadioButton *pRButton = new QRadioButton("&Radio Button");
    QCheckBox *pCheckBox = new QCheckBox("&Check Box");
    QPushButton *pButton = new QPushButton("&Push Button");

    pComBox->addItems(QStyleFactory::keys());

    connect(pComBox,
            SIGNAL(activated(const QString&)),
            SLOT(slotChangeStyle(const QString&)));

    QVBoxLayout *pVBlay = new QVBoxLayout;
    pVBlay->addWidget(pComBox);
    pVBlay->addWidget(pSpinBox);
    pVBlay->addWidget(pSlider);
    pVBlay->addWidget(pRButton);
    pVBlay->addWidget(pCheckBox);
    pVBlay->addWidget(pButton);
    setLayout(pVBlay);
}

Widget::~Widget()
{
}

void Widget::slotChangeStyle(const QString &str)
{
    QStyle *pStyle = QStyleFactory::create(str);
    QApplication::setStyle(pStyle);
}

