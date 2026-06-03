#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>
#include <QDebug>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

public slots:
    void onCountChanged(int value);
};
#endif // LOGGER_H
