#include "Counter.h"

Counter::Counter(QObject *parent)
    : QObject(parent)
{
}

int Counter::count() const
{
    return m_count;
}

void Counter::increment()
{
    ++m_count;
    emit countChanged(m_count);
}

void Counter::decrement()
{
    --m_count;
    emit countChanged(m_count);
}

void Counter::reset()
{
    m_count = 0;
    emit countChanged(m_count);
}
