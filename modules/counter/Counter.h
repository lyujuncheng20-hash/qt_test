#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QtQml>

// Windows環境用のシンボルエクスポート/インポート制御
#if defined(countermodule_EXPORTS)
#  define COUNTER_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_EXPORT Q_DECL_IMPORT
#endif

class COUNTER_EXPORT Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT
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
