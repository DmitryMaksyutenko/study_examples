#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      mSettings("Producer", "Product name") {
  mpLbl = new QLabel;
  mpTxt = new QTextEdit;
  mpCbox = new QComboBox;
  mpChck = new QCheckBox("Disable edit");

  mpCbox->addItem("Classic");
  mpCbox->addItem("Borland");

  connect(mpChck, SIGNAL(clicked()), SLOT(slotCheckBoxClicked()));
  connect(mpCbox, SIGNAL(activated(int)), SLOT(slotComboBoxActivated(int)));

  readSettings();

  QVBoxLayout *pVBLayout = new QVBoxLayout;
  QHBoxLayout *pHBLayout = new QHBoxLayout;

  pVBLayout->setContentsMargins(5, 5, 5, 5);
  pHBLayout->setSpacing(15);
  pVBLayout->setSpacing(15);
  pVBLayout->addWidget(mpLbl);
  pVBLayout->addWidget(mpTxt);
  pHBLayout->addWidget(mpCbox);
  pHBLayout->addWidget(mpChck);

  pVBLayout->addLayout(pHBLayout);
  setLayout(pVBLayout);
}

Widget::~Widget() {
  writeSetings();
}

void Widget::writeSetings() {
    mSettings.beginGroup("/Settings");
    mSettings.setValue("/counter", mAppStartCounter);
    mSettings.setValue("/text", mpTxt->toPlainText());
    mSettings.setValue("/width", width());
    mSettings.setValue("/height", height());
    mSettings.setValue("/highlight", mpCbox->currentIndex());
    mSettings.setValue("/edit", mpChck->isChecked());
    mSettings.endGroup();
}

void Widget::readSettings() {
    mSettings.beginGroup("/Settings");
    QString strText = mSettings.value("/text", "").toString();
    int w = mSettings.value("/width", width()).toInt();
    int h = mSettings.value("/height", height()).toInt();
    int comboItem = mSettings.value("/highlight", 0).toInt();
    bool edit = mSettings.value("/edit", false).toBool();
    mAppStartCounter = mSettings.value("/counter", 1).toInt() + 1;
    QString str = QString().setNum(mAppStartCounter);
    mpLbl->setText("This program has been started " + str + " times");
    mpTxt->setPlainText(strText);
    resize(w, h);
    mpChck->setChecked(edit);
    slotCheckBoxClicked();
    mpCbox->setCurrentIndex(comboItem);
    mSettings.endGroup();
}

void Widget::slotCheckBoxClicked() {
    mpTxt->setEnabled(!mpChck->isChecked());
}

void Widget::slotComboBoxActivated(int n) {
    QPalette pal = mpTxt->palette();
    pal.setColor(QPalette::Active, QPalette::Base, n ? Qt::darkBlue : Qt::white);
    pal.setColor(QPalette::Active, QPalette::Text, n ? Qt::yellow : Qt::black);
    mpTxt->setPalette(pal);
}
