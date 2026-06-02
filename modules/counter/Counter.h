#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>
#include <QtQml>

class Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON // 【新增】让这个类在导入模块时作为单例使用
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;

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
