#include "Logger.h"

Logger::Logger(QObject *parent)
    : QObject(parent)
{
}

void Logger::onCountChanged(int value)
{
    qDebug() << "Count changed:" << value;
}
