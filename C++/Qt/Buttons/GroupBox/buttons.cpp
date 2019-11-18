#include "buttons.h"

Buttons::Buttons(QWidget *parent)
    : QGroupBox("Group Box", parent)
{
    resize(200, 350);
    setCheckable(true);
    setChecked(true);

    m_rbRed = new QRadioButton("&Red");
    m_rbGreen = new QRadioButton("&Green");
    m_rbBlue = new QRadioButton("&Blue");
    m_rbGreen->setChecked(true);

    connect(m_rbRed, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_rbGreen, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_rbBlue, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    m_pcheck = new QCheckBox("&Light");
    m_pcheck->setChecked(true);
    connect(m_pcheck, SIGNAL(clicked()),SLOT(slotButtonClicked()
));

    QPushButton *exitButton = new QPushButton("Exit");
    connect(exitButton, SIGNAL(clicked()), qApp ,SLOT(quit()));

    QVBoxLayout *vBox = new QVBoxLayout();
    vBox->addWidget(m_rbRed);
    vBox->addWidget(m_rbBlue);
    vBox->addWidget(m_rbGreen);
    vBox->addWidget(m_pcheck);
    vBox->addWidget(exitButton);

    setLayout(vBox);

    slotButtonClicked();
}

Buttons::~Buttons()
{
}


void Buttons::slotButtonClicked()
{
    QPalette palette;

    int nLight = m_pcheck->isChecked() ? 150 : 80;

    if (m_rbRed->isChecked())
        palette.setColor(backgroundRole(), QColor(Qt::red).light(nLight));
    else if (m_rbBlue->isChecked())
        palette.setColor(backgroundRole(), QColor(Qt::blue).light(nLight));
    else
        palette.setColor(backgroundRole(), QColor(Qt::green).light(nLight));

    setPalette(palette);
}
