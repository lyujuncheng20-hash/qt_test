#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>
#include <QtQml>

// ==============================================================================
// 【核心新增】：控制 Logger 模块 DLL 符号的导出与导入
// 当编译 loggermodule 自身时，CMake 会自动定义 loggermodule_EXPORTS，此时导出符号；
// 当主程序 app_target 编译时，没有定义该宏，此时导入符号。
// ==============================================================================
#if defined(loggermodule_EXPORTS)
#  define LOGGER_EXPORT Q_DECL_EXPORT
#else
#  define LOGGER_EXPORT Q_DECL_IMPORT
#endif

// 在 class 关键字后面加上 LOGGER_EXPORT 宏
class LOGGER_EXPORT Logger : public QObject
{
    Q_OBJECT
    QML_ELEMENT // 保持这个宏，使其支持 QML 声明
public:
    explicit Logger(QObject *parent = nullptr);

public slots:
    void onCountChanged(int value);
};

#endif // LOGGER_H
