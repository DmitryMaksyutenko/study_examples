#include "progressevent.h"

ProgressEvent::ProgressEvent()
    : QEvent((Type)ProgressType)
{

}

void ProgressEvent::setValue(int val)
{
    m_value = val;
}

int ProgressEvent::value() const
{
    return m_value;
}
