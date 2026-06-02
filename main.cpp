#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Counter.h"
#include "Logger.h"

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
