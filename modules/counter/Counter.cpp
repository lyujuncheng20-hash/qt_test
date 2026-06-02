#include "Counter.h"

Counter::Counter(QObject *parent)
    : QObject(parent)
{
}

int Counter::count() const
{
    return m_count;
}

void Counter::setCount(int value)
{
    if (m_count != value) {
        m_count = value;
        emit countChanged(m_count);
    }
}

void Counter::increment()
{
    setCount(m_count + 1);
}

void Counter::decrement()
{
    setCount(m_count - 1);
}

void Counter::reset()
{
    setCount(0);
}
