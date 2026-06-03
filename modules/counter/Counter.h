#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QtQml>
#include <QtQml/qqmlregistration.h>

class Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT // 保持这个宏
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;
    void setCount(int value);

    Q_INVOKABLE void increment();
    Q_INVOKABLE void decrement();

public slots:
    void reset();

signals:
    void countChanged(int value);

private:
    int m_count = 0;
};

#endif // COUNTER_H
