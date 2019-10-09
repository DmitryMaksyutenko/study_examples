#include "counter.h"

// Use initialization list for call base constructor of parent class
Counter::Counter() : QObject(), m_nValue(0) {}

void Counter::slotIncrement()
{
    // Send signal with incremented parameter.
    emit counterIncrement(++m_nValue);

    if (m_nValue == 5)
    {
        // Send signal of quit.
        emit goodbye();
    }
}
