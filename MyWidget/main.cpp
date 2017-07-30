#include<mywidget.h>
#include<QApplication>
#include"workthreada.h"
#include"workthreadb.h"
#include"workthreadc.h"
int angle_A=0;
int angle_B=0;
int angle_C=0;
int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    MyWidget w;
    w.show();
    //multi thread
    WorkThreadA *worka=new WorkThreadA();
    worka->start();
    WorkThreadB *workb=new WorkThreadB();
    workb->start();
    WorkThreadC *workc=new WorkThreadC();
    workc->start();
    //
    return app.exec();
}
