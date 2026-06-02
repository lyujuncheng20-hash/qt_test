#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtPlugin> // 【必须】引入静态插件所需的头文件

#include "modules/counter/Counter.h"
#include "modules/logger/Logger.h"

// 【核心修复】精确匹配 Qt 基于目标名 "counter_module" 生成的静态插件符号
// 确保中间带有下划线，且末尾的 Plugin 的 P 是大写！
Q_IMPORT_QML_PLUGIN(countermodulePlugin)

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Logger logger;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    // 加载主程序模块
    engine.loadFromModule("app_target", "Main");

    // 获取由 QML 引擎自动创建的 Counter 单例指针
    Counter* counter = engine.singletonInstance<Counter*>("counter.module", "Counter");

    if (counter) {
        // 在 C++ 层建立信号槽连接
        QObject::connect(
            counter,
            &Counter::countChanged,
            &logger,
            &Logger::onCountChanged);
    } else {
        qWarning() << "Failed to find Counter singleton instance!";
    }

    return app.exec();
}
