#include "Logger.h"

Logger::Logger(QObject *parent)
    : QObject(parent)
{
}

void Logger::onCountChanged(int value)
{
    qDebug() << "Logger [C++ Backend] -> Count changed to:" << value;
}
