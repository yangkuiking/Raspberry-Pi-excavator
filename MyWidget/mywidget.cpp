#include "mywidget.h"
#include <QDebug>
#include <QPixmap>

extern int angle_A;
extern int angle_B;
extern int angle_C;
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    group_control = new QGroupBox("机械臂的控制");
    group_run = new QGroupBox("前进左右");

    labelw = new QLabel();
    labelw->setPixmap(QPixmap("./w.jpg"));
    layout_run.addWidget(labelw,1,2);

    labela = new QLabel();
    labela->setPixmap(QPixmap("./a.jpg"));
    layout_run.addWidget(labela,2,1);

    labels = new QLabel();
    labels->setPixmap(QPixmap("./s.jpg"));
    layout_run.addWidget(labels,2,2);

    labeld = new QLabel();
    labeld->setPixmap(QPixmap("./d.jpg"));
    layout_run.addWidget(labeld,2,3);

    group_run->setMaximumWidth(200);
    group_run->setMinimumWidth(200);

    layout.addWidget(group_run);
    group_run->setLayout(&layout_run);

    //申请内存空间

    spin_a = new QSlider(Qt::Horizontal);
    spin_b = new QSlider(Qt::Horizontal);
    spin_c = new QSlider(Qt::Horizontal);
    spin_d = new QSlider(Qt::Horizontal);
    spin_e = new QSlider(Qt::Horizontal);
    spin_f = new QSlider(Qt::Horizontal);
    Dial = new QDial();

    //用QDial来操控底盘
    Dial->setNotchTarget(1.0);
    Dial->setNotchesVisible(true);
    Dial->setRange(0,2499);
    Dial->setPageStep(1);

    //用QSlider控件来操控机械臂
    spin_a->setRange(0,2499);
    spin_a->setPageStep(1);
    spin_b->setRange(0,2499);
    spin_b->setPageStep(1);
    spin_c->setRange(0,2499);
    spin_c->setPageStep(1);
    spin_d->setRange(0,2499);
    spin_d->setPageStep(1);
    spin_e->setRange(0,2499);
    spin_e->setPageStep(1);
    spin_f->setRange(0,2499);
    spin_f->setPageStep(1);

    //把QSlider控件加入到QVBoxLayout中
    vout.addWidget(spin_a);
    vout.addWidget(spin_b);
    vout.addWidget(spin_c);
    vout.addWidget(spin_d);
    vout.addWidget(spin_e);
    vout.addWidget(spin_f);
    vout.addWidget(Dial,1);

    layout.addWidget(group_control,1,1);
    group_control->setMaximumWidth(200);
    group_control->setMinimumWidth(200);
    group_control->setMaximumHeight(300);
    group_control->setMinimumHeight(300);
    group_control->setLayout(&vout);
    //信号与槽关系
    QObject::connect(Dial,SIGNAL(valueChanged(int)),this,SLOT(Spin_Q(int)));
    QObject::connect(spin_a,SIGNAL(valueChanged(int)),this,SLOT(Spin_A(int)));
    QObject::connect(spin_b,SIGNAL(valueChanged(int)),this,SLOT(Spin_B(int)));
    QObject::connect(spin_c,SIGNAL(valueChanged(int)),this,SLOT(Spin_C(int)));
    QObject::connect(spin_d,SIGNAL(valueChanged(int)),this,SLOT(Spin_D(int)));
    QObject::connect(spin_e,SIGNAL(valueChanged(int)),this,SLOT(Spin_E(int)));
    QObject::connect(spin_f,SIGNAL(valueChanged(int)),this,SLOT(Spin_F(int)));
/////////////////////////////////
//    angle_C=0;
//    timer = new QTimer(this);
//    timer->start(1);
//    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(KeepC()));
/////////////////////////////////

    this->setLayout(&layout);
    init();
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
       event->modifiers();
       int key = event->key();
       char a = key;
       if(a=='W')
       {
            labelw->setPixmap(QPixmap("./w1.jpg"));
          //  qDebug() << "前进";
            Go_ahead();
       }
       if(a=='A')
       {
            labela->setPixmap(QPixmap("./a1.jpg"));
           // qDebug() << "左转";
            Turn_left();
       }
       if(a=='S')
       {
            labels->setPixmap(QPixmap("./s1.jpg"));
           // qDebug() << "后退";
            Go_back();
       }
       if(a=='D')
       {
            labeld->setPixmap(QPixmap("./d1.jpg"));
           // qDebug() << "右转";
            Turn_right();
       }

}
void MyWidget::keyReleaseEvent(QKeyEvent *event)
{
   labelw->setPixmap(QPixmap("./w.jpg"));
   labela->setPixmap(QPixmap("./a.jpg"));
   labels->setPixmap(QPixmap("./s.jpg"));
   labeld->setPixmap(QPixmap("./d.jpg"));
   Stop();
}

void MyWidget::init()
{
    wiringPiSetup();
    for(int i=22;i<=29;i++)
          pinMode(i,OUTPUT);
    pinMode(15,OUTPUT);
    pinMode(16,OUTPUT);
}
/*
void MyWidget::KeepC()
{
    digitalWrite(26,HIGH);
    delayMicroseconds(500+angle_C);
    digitalWrite(26,LOW);
    delayMicroseconds(19500-angle_C);
}
*/

void MyWidget::Turn_right()
{
    digitalWrite(22,LOW);
    digitalWrite(23,HIGH);
    digitalWrite(24,LOW);
    digitalWrite(25,HIGH);

}

void MyWidget::Turn_left()
{

    digitalWrite(22,HIGH);
    digitalWrite(23,LOW);
    digitalWrite(24,HIGH);
    digitalWrite(25,LOW);
}

void MyWidget::Go_ahead()
{
    digitalWrite(22,LOW);
    digitalWrite(23,HIGH);
    digitalWrite(24,HIGH);
    digitalWrite(25,LOW);
}

void MyWidget::Go_back()
{
    digitalWrite(22,HIGH);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
    digitalWrite(25,HIGH);
}

void MyWidget::Stop()
{
    digitalWrite(22,LOW);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
    digitalWrite(25,LOW);
}


void MyWidget::Spin_A(int angle)
{
  //  qDebug() << "a";
    digitalWrite(15,HIGH);
    delayMicroseconds(500+angle);
    digitalWrite(15,LOW);
    delayMicroseconds(19500-angle);

}
void MyWidget::Spin_B(int angle)
{
   // qDebug() << "b";
    digitalWrite(16,HIGH);
    delayMicroseconds(500+angle);
    digitalWrite(16,LOW);
    delayMicroseconds(19500-angle);

}
void MyWidget::Spin_C(int angle)
{
    //qDebug() << "c";
    digitalWrite(26,HIGH);
    delayMicroseconds(500+angle);
    digitalWrite(26,LOW);
    delayMicroseconds(19500-angle);
    angle_A = angle;

}
void MyWidget::Spin_D(int angle)
{
    //qDebug() << "d";
    digitalWrite(27,HIGH);
    delayMicroseconds(500+angle);
    digitalWrite(27,LOW);
    delayMicroseconds(19500-angle);
    angle_B = angle;
}
void MyWidget::Spin_E(int angle)
{
   // qDebug() << "e";
    digitalWrite(28,HIGH);
    delayMicroseconds(500+angle);
    digitalWrite(28,LOW);
    delayMicroseconds(19500-angle);
    angle_C = angle;
}
void MyWidget::Spin_F(int angle)
{
    //qDebug() << "f";
    digitalWrite(29,HIGH);
    delayMicroseconds(500+angle);
    digitalWrite(29,LOW);
    delayMicroseconds(19500-angle);
}
void MyWidget::Spin_Q(int angle)
{
    //qDebug() << "q";
    digitalWrite(15,HIGH);
    delayMicroseconds(500+angle);
    digitalWrite(15,LOW);
    delayMicroseconds(19500-angle);
}
