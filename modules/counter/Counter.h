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

class CounterWorkerPrivate;
class QThread;

class COUNTER_EXPORT Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(bool isCalculating READ isCalculating NOTIFY isCalculatingChanged)
    Q_PROPERTY(bool isHeavy READ isHeavy WRITE setIsHeavy NOTIFY isHeavyChanged)

public:
    explicit Counter(QObject *parent = nullptr);
    ~Counter();

    int count() const;
    void setCount(int value);
    bool isCalculating() const;

    bool isHeavy() const;
    void setIsHeavy(bool heavy);

    Q_INVOKABLE void increment();
    Q_INVOKABLE void decrement();

public slots:
    void reset();

signals:
    void countChanged(int value);
    void isCalculatingChanged();
    void isHeavyChanged();

    void requestCalculation(int currentCount, const QString &operation);

private:
    int m_count = 0;
    bool m_isCalculating = false;
    bool m_isHeavy = false;

    QThread* m_workerThread = nullptr;
    CounterWorkerPrivate* m_d = nullptr;
};

#endif // COUNTER_H
