#ifndef WORKTHREADB_H
#define WORKTHREADB_H

#include <QThread>
#include <wiringPi.h>
class WorkThreadB : public QThread
{
    Q_OBJECT
public:
    explicit WorkThreadB(QObject *parent = 0);
protected:
    void run();
signals:

public slots:

};

#endif // WORKTHREADB_H
