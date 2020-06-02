#include "inputdialog.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

InputDialog::InputDialog(QWidget *obj)
  : QDialog(obj, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
  QLabel *pFirsName = new QLabel("&First Name", this);
  QLabel *pLastName = new QLabel("&Last Name", this);
  pFirsName->setBuddy(&mFirstName);
  pLastName->setBuddy(&mLastName);
  QPushButton *pOk = new QPushButton("&Ok");
  QPushButton *pCancel = new QPushButton("&Cancel");

  connect(pOk, SIGNAL(clicked()), SLOT(accept()));
  connect(pCancel, SIGNAL(clicked()), SLOT(reject()));

  QGridLayout *pLay = new QGridLayout(this);
  pLay->addWidget(pFirsName, 0, 0);
  pLay->addWidget(pLastName, 1, 0);
  pLay->addWidget(&mFirstName, 0, 1);
  pLay->addWidget(&mLastName, 1, 1);
  pLay->addWidget(pOk, 2, 0);
  pLay->addWidget(pCancel, 2, 1);
  setLayout(pLay);
}

QString InputDialog::firstName() const
{
  return mFirstName.text();
}

QString InputDialog::lastName() const
{
  return mLastName.text();
}
