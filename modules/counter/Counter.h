#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>
#include <QtQml>

class Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT // 保持这个宏，让 QML 可以直接实例化它
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;
    void setCount(int value); // 新增设置函数

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
