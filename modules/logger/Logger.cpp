#include "Logger.h"

Logger::Logger(QObject *parent)
    : QObject(parent)
{
}

void Logger::onCountChanged(int value)
{
    qDebug() << "Logger [C++バックエンド] -> カウントが変更されました:" << value;
}
