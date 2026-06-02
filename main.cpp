#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "modules/counter/Counter.h"
#include "modules/logger/Logger.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Counter counter;
    Logger logger;

    QObject::connect(
        &counter,
        &Counter::countChanged,
        &logger,
        &Logger::onCountChanged);

    // 【修复】将 C++ 的这个 counter 注入给 QML 引擎
    engine.rootContext()->setContextProperty("counter_instance", &counter);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.loadFromModule("untitled", "Main");

    return app.exec();
}
