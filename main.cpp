#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "modules/counter/Counter.h"
#include "modules/logger/Logger.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Logger logger;

    // 错误处理连接
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    // 加载 untitled 模块和 Main.qml
    engine.loadFromModule("untitled", "Main");

    // 【核心修复】在引擎加载完模块后，获取 QML 自动创建的 Counter 单例实例
    // 注意：这里的路径是 "模块URI/类名"，也就是 "counter/module/Counter"
    Counter* counter = engine.singletonInstance<Counter*>("counter.module", "Counter");

    if (counter) {
        // 在 C++ 层将单例与 Logger 连起来
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
