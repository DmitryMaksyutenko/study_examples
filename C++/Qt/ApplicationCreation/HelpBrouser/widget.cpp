#include "widget.h"

Widget::Widget(const QString &path, const QString &fileName, QWidget *parent)
  : QWidget(parent)
{
  QPushButton *pBackButton = new QPushButton("<<", this);
  QPushButton *pHomeButton = new QPushButton("Home", this);
  QPushButton *pForwardButton = new QPushButton(">>", this);
  QTextBrowser *pTextBrouser = new QTextBrowser(this);

  connect(pBackButton, SIGNAL(clicked()), pTextBrouser, SLOT(backward()));
  connect(pHomeButton, SIGNAL(clicked()), pTextBrouser, SLOT(home()));
  connect(pForwardButton, SIGNAL(clicked()), pTextBrouser, SLOT(forward()));
  connect(pTextBrouser, SIGNAL(backwardAvailable(bool)), pBackButton, SLOT(setEnabled(bool)));
  connect(pTextBrouser, SIGNAL(forwardAvailable(bool)), pForwardButton, SLOT(setEnabled(bool)));

  pTextBrouser->setSearchPaths(QStringList() << path);
  pTextBrouser->setSource(QString(fileName));

  QVBoxLayout *pVBL = new QVBoxLayout(this);
  QHBoxLayout *pHBL = new QHBoxLayout(this);
  pHBL->addWidget(pBackButton);
  pHBL->addWidget(pHomeButton);
  pHBL->addWidget(pForwardButton);
  pVBL->addLayout(pHBL);
  pVBL->addWidget(pTextBrouser);
  setLayout(pVBL);
}

Widget::~Widget()
{
}

