#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>
#include <QtQml>

// Windows環境用のシンボルエクスポート/インポート制御
#if defined(loggermodule_EXPORTS)
#  define LOGGER_EXPORT Q_DECL_EXPORT
#else
#  define LOGGER_EXPORT Q_DECL_IMPORT
#endif

class LOGGER_EXPORT Logger : public QObject
{
    Q_OBJECT
    QML_ELEMENT // QMLコンポーネントとして登録

public:
    explicit Logger(QObject *parent = nullptr);

public slots:
    void onCountChanged(int value);
};

#endif // LOGGER_H
