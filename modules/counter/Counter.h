#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>
#include <QtQml>

class Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int count READ count NOTIFY countChanged) //countプロパティをQMLへ公開しています。

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;

    Q_INVOKABLE void increment(); //QMLから直接呼び出せる関数です。
    Q_INVOKABLE void decrement();
    //Q_INVOKABLE void reset();

public slots:
    void reset();

signals:
    void countChanged(int value); //値が変更されたことを通知しています。

private:
    int m_count = 0;
};
#endif // COUNTER_H
