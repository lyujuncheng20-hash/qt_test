#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>
#include <QtQml>

// ==============================================================================
// 符号导出/导入控制（针对 Windows / MinGW 动态库环境）
// 当编译 loggermodule 自身时，CMake 会自动定义 loggermodule_EXPORTS，此时导出符号；
// 当主程序 app_target 编译时没有定义该宏，此时导入符号。
// ==============================================================================
#if defined(loggermodule_EXPORTS)
#  define LOGGER_EXPORT Q_DECL_EXPORT
#else
#  define LOGGER_EXPORT Q_DECL_IMPORT
#endif

/**
 * @brief 业务日志类，用于接收业务状态变化并输出调试信息
 */
class LOGGER_EXPORT Logger : public QObject
{
    Q_OBJECT
    QML_ELEMENT // 注册为 QML 元素，使其可在 QML 中作为组件使用

public:
    explicit Logger(QObject *parent = nullptr);

public slots:
    /**
     * @brief 响应计数器数值变化的槽函数
     * @param value 当前的计数值
     */
    void onCountChanged(int value);
};

#endif // LOGGER_H
