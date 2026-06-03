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
    // 设置 QML 全局样式样式为 Basic
    QQuickStyle::setStyle("Basic");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // 通知 QML 引擎去当前 exe 所在的 bin 目录下寻找 QML 扩展模块插件
    engine.addImportPath(QCoreApplication::applicationDirPath());

    // 强行激活 C++ 模块的符号绑定，防止编译器和链接器优化掉动态库中的 QML 注册逻辑
    qDebug() << "Linking Counter Module Backend..." << Counter::staticMetaObject.className();
    qDebug() << "Linking Logger Module Backend..." << Logger::staticMetaObject.className();

    // 实例化日志类并将其注册到 QML 的全局上下文属性中
    Logger logger;
    engine.rootContext()->setContextProperty("cppLogger", &logger);

    // 连接错误信号，如果 QML 加载失败则安全退出程序
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    // 通过标准的 Qt6 加载机制加载主界面
    engine.loadFromModule("app_ui", "Main");

    return app.exec();
}
