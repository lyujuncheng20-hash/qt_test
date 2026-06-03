// src/main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QDebug>
#include "Logger.h"
#include "Counter.h"

// 🔴 注意：动态库模式下，这里绝对不能写 Q_IMPORT_PLUGIN 宏，请删掉它。

int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Basic");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // 告诉引擎去应用程序同级目录下寻找导出的模块（包含 cpp_logic 相关的 QML 插件目录）
    engine.addImportPath(QCoreApplication::applicationDirPath());

    // 强行激活符号绑定
    qDebug() << "Linking QML Module C++ Logic..." << Counter::staticMetaObject.className();

    Logger logger;
    engine.rootContext()->setContextProperty("cppLogger", &logger);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.loadFromModule("app_ui", "Main");

    return app.exec();
}
