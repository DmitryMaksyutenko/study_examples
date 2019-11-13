#include <QtWidgets>
#include "Progress.h"

Progress::Progress(QWidget *pobj) : QWidget(pobj), m_nStep(0)
{
    m_pprg = new QProgressBar();
    m_pprg->setRange(0, 5);
    m_pprg->setMinimumWidth(200);

    QPushButton* pButtonStep = new QPushButton("&Step");
    QPushButton* pButtonReset = new QPushButton("&Reset");

    QObject::connect(pButtonStep, SIGNAL(clicked()), SLOT(slotStep()));
    QObject::connect(pButtonReset, SIGNAL(clicked()), SLOT(slotReset()));

    QHBoxLayout* pHorizontalBoxLayout = new QHBoxLayout();
    pHorizontalBoxLayout->addWidget(m_pprg);
    pHorizontalBoxLayout->addWidget(pButtonStep);
    pHorizontalBoxLayout->addWidget(pButtonReset);

    setLayout(pHorizontalBoxLayout);
}

void Progress::slotStep()
{
    m_pprg->setValue(++m_nStep);
}

void Progress::slotReset()
{
    m_nStep = 0;
    m_pprg->reset();
}
