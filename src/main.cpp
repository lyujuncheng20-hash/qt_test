#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QDebug>
#include "Logger.h"
#include "Counter.h"

int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Basic");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // 强行激活 countermodule.dll 的符号绑定
    qDebug() << "Linking QML Module C++ Backend..." << Counter::staticMetaObject.className();

    // 注册 C++ Logger 供 QML 使用
    Logger logger;
    engine.rootContext()->setContextProperty("cppLogger", &logger);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    // 🔴 完美的标准加载方式
    engine.loadFromModule("app_ui", "Main");

    return app.exec();
}
