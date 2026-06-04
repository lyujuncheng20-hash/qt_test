#include "Counter.h"
#include "private/CounterWorkerPrivate.h"
#include <QThread>
#include <QDebug>

Counter::Counter(QObject *parent)
    : QObject(parent)
{
    m_workerThread = new QThread(this);
    m_d = new CounterWorkerPrivate();
    m_d->moveToThread(m_workerThread);

    connect(this, &Counter::requestCalculation, m_d, &CounterWorkerPrivate::doHeavyCalculation);

    connect(m_d, &CounterWorkerPrivate::calculationFinished, this, [this](int newCount) {
        setCount(newCount);
        m_isCalculating = false;
        emit isCalculatingChanged();
    });

    connect(m_workerThread, &QThread::finished, m_d, &QObject::deleteLater);
    m_workerThread->start();
}

Counter::~Counter()
{
    if (m_workerThread && m_workerThread->isRunning()) {
        m_workerThread->quit();
        m_workerThread->wait();
    }
}

int Counter::count() const
{
    return m_count;
}

bool Counter::isCalculating() const
{
    return m_isCalculating;
}

bool Counter::isHeavy() const
{
    return m_isHeavy;
}

void Counter::setIsHeavy(bool heavy)
{
    if (m_isHeavy != heavy) {
        m_isHeavy = heavy;
        emit isHeavyChanged();
    }
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
    if (m_isHeavy) {
        if (m_isCalculating) return;

        m_isCalculating = true;
        emit isCalculatingChanged();
        emit requestCalculation(m_count, "increment");
    } else {
        setCount(m_count + 1);
    }
}

void Counter::decrement()
{
    if (m_isHeavy) {
        if (m_isCalculating) return;

        m_isCalculating = true;
        emit isCalculatingChanged();
        emit requestCalculation(m_count, "decrement");
    } else {
        setCount(m_count - 1);
    }
}

void Counter::reset()
{
    if (m_isHeavy) {
        if (m_isCalculating) return;

        m_isCalculating = true;
        emit isCalculatingChanged();
        emit requestCalculation(m_count, "reset");
    } else {
        setCount(0);
    }
}
