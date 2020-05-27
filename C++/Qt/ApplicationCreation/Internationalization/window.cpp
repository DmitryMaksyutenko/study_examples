#include "window.h"

#include <QHBoxLayout>
#include <QApplication>
#include <QDir>

#include <QDebug>

Window::Window(QWidget *parent)
  : QLabel(parent),
    ru("RU", this),
    de("DE", this)
{
  setGeometry(500, 300, 200, 270);
  setAlignment(Qt::AlignCenter);
  setFont(QFont("Consolas", 28));
  ru.setObjectName("RU");
  de.setObjectName("DE");

  QHBoxLayout *lay = new QHBoxLayout(this);
  lay->addWidget(&ru);
  lay->addWidget(&de);
  lay->setAlignment(Qt::AlignTop);
  setLayout(lay);

  QObject::connect(&ru, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
  QObject::connect(&de, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
}

Window::~Window()
{
}

void Window::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::LanguageChange) {
      setText(tr("Text"));
    } else
        QWidget::changeEvent(e);
}

void Window::slotButtonClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QString lang = pButton->text();

    if (lang == "RU") {
        transl.load(":/translations/main_ru.qm");
    }
    if (lang == "DE") {
        transl.load(":/translations/main_de.qm");
    }
    qApp->installTranslator(&transl);
}

