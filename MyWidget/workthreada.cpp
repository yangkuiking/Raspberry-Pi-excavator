#include "workthreada.h"
#include <qdebug.h>

extern int angle_A;
WorkThreadA::WorkThreadA(QObject *parent) :
    QThread(parent)
{
}

void WorkThreadA::run()
{
    while(1)
    {
        digitalWrite(26,HIGH);
        delayMicroseconds(500+angle_A);
        digitalWrite(26,LOW);
        delayMicroseconds(19500-angle_A);
    }

}
