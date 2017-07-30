#ifndef WORKTHREADC_H
#define WORKTHREADC_H

#include <QThread>
#include <wiringPi.h>
class WorkThreadC : public QThread
{
    Q_OBJECT
public:
    explicit WorkThreadC(QObject *parent = 0);
protected:
    void run();
signals:

public slots:

};

#endif // WORKTHREADC_H
