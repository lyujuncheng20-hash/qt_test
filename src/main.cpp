// src/main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>
#include "Logger.h"
#include "Counter.h"

int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Basic");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.addImportPath(QCoreApplication::applicationDirPath());

    // リンカーによる最適化（C++クラスの削除）を防止するためのダミー呼び出し
    qDebug() << "Linking Counter Module..." << Counter::staticMetaObject.className();
    qDebug() << "Linking Logger Module..." << Logger::staticMetaObject.className();

    // LoggerをQMLからグローバルに呼び出せるようプロパティとして登録
    Logger logger;
    engine.rootContext()->setContextProperty("Logger", &logger);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.loadFromModule("app_ui", "Main");

    return app.exec();
}
