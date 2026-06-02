#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>
#include <QDebug>

class Logger : public QObject
{
    Q_OBJECT

public slots:
    void onCountChanged(int value)
    {
        qDebug() << "Count changed:" << value;
    }
};
#endif // LOGGER_H
