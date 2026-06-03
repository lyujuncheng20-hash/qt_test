// src/main.cpp
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

    // 通知 QML 引擎，去当前 exe 所在的同级目录（即 bin 目录）下寻找 QML 模块
    engine.addImportPath(QCoreApplication::applicationDirPath());

    // 强行激活 c++ 模块的符号绑定，防止编译器优化掉动态库链接
    qDebug() << "Linking QML Module C++ Backend..." << Counter::staticMetaObject.className();

    Logger logger;
    engine.rootContext()->setContextProperty("cppLogger", &logger);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    // 标准加载方式
    engine.loadFromModule("app_ui", "Main");

    return app.exec();
}
