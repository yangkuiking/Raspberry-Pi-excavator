#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <wiringPi.h>

class WorkThreadA : public QThread
{
    Q_OBJECT
public:
    explicit WorkThreadA(QObject *parent = 0);
protected:
    void run();
signals:

public slots:

};

#endif // WORKTHREAD_H
