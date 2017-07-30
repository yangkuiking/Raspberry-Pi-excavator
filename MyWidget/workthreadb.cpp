#include "workthreadb.h"

extern int angle_B;
WorkThreadB::WorkThreadB(QObject *parent) :
    QThread(parent)
{
}

void WorkThreadB::run()
{
    while(1)
    {
        digitalWrite(27,HIGH);
        delayMicroseconds(500+angle_B);
        digitalWrite(27,LOW);
        delayMicroseconds(19500-angle_B);
    }

}
