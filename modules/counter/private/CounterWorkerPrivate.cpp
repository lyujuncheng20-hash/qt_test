#include "CounterWorkerPrivate.h"
#include <QThread>
#include <QDebug>

CounterWorkerPrivate::CounterWorkerPrivate(QObject *parent)
    : QObject(parent)
{
    qDebug() << "CounterWorkerPrivate created in thread:" << QThread::currentThread();
}

CounterWorkerPrivate::~CounterWorkerPrivate()
{
    qDebug() << "CounterWorkerPrivate destroyed in thread:" << QThread::currentThread();
}

void CounterWorkerPrivate::doHeavyCalculation(int currentCount, const QString &operation)
{
    qDebug() << "Heavy calculation executing inside Private class in thread:" << QThread::currentThread();

    QThread::msleep(1200);

    int result = currentCount;
    if (operation == "increment") {
        result += 1;
    } else if (operation == "decrement") {
        result -= 1;
    } else if (operation == "reset") {
        result = 0;
    }

    emit calculationFinished(result);
}
