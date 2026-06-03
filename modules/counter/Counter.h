#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QtQml>

// ==============================================================================
// 【核心新增】：控制 DLL 符号的导出与导入
// 当编译 countermodule 自身时，CMake 会自动定义 countermodule_EXPORTS，此时导出符号；
// 当主程序 app_target 编译时，没有定义该宏，此时导入符号。
// ==============================================================================
#if defined(countermodule_EXPORTS)
#  define COUNTER_EXPORT Q_DECL_EXPORT
#else
#  define COUNTER_EXPORT Q_DECL_IMPORT
#endif

// 在 class 关键字后面加上 COUNTER_EXPORT 宏
class COUNTER_EXPORT Counter : public QObject
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
