#include "spinbox.h"

SpinBox::SpinBox(QSpinBox *parent)
    : QSpinBox(parent)
{
    setRange(1, 100);
    setSuffix(" Mb");
    setButtonSymbols(QSpinBox::PlusMinus);
    setWrapping(true);
    show();
    resize(100, 30);
}

SpinBox::~SpinBox()
{
}

