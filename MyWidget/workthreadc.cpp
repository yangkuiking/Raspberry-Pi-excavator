#include "workthreadc.h"
extern int angle_C;
WorkThreadC::WorkThreadC(QObject *parent) :
    QThread(parent)
{
}
void WorkThreadC::run()
{
    while(1)
    {
        digitalWrite(28,HIGH);
        delayMicroseconds(500+angle_C);
        digitalWrite(28,LOW);
        delayMicroseconds(19500-angle_C);
    }

}
