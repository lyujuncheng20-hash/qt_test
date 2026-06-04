#ifndef COUNTER_WORKER_PRIVATE_H
#define COUNTER_WORKER_PRIVATE_H

#include <QObject>

class CounterWorkerPrivate : public QObject
{
    Q_OBJECT
public:
    explicit CounterWorkerPrivate(QObject *parent = nullptr);
    ~CounterWorkerPrivate();

public slots:
    void doHeavyCalculation(int currentCount, const QString &operation);

signals:
    void calculationFinished(int newCount);
};

#endif // COUNTER_WORKER_PRIVATE_H
