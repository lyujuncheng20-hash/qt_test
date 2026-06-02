#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "Logger.h" // 只需要引入 Logger

int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Basic");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // 注册 Logger 供 QML 使用，或者将它注册为全局上下文属性
    Logger logger;
    engine.rootContext()->setContextProperty("cppLogger", &logger);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.loadFromModule("app_target", "Main");

    return app.exec();
}
