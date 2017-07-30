#ifndef MYWIDGT_H
#define MYWIDGT_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QImage>
#include <QPainter>
#include <QSlider>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDial>
#include <wiringPi.h>
//#include <QTimer>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
signals:

public slots:
    void Spin_A(int angle);
    void Spin_B(int angle);
    void Spin_C(int angle);
    void Spin_D(int angle);
    void Spin_E(int angle);
    void Spin_F(int angle);
    void Spin_Q(int angle);
    //void KeepC();
private:

    QLabel *labelw;
    QLabel *labela;
    QLabel *labels;
    QLabel *labeld;
    QGridLayout layout;
    QGridLayout layout_run;
    QVBoxLayout vout;
    QGroupBox *group_control;
    QGroupBox *group_run;
    QSlider *spin_a;
    QSlider *spin_b;
    QSlider *spin_c;
    QSlider *spin_d;
    QSlider *spin_e;
    QSlider *spin_f;
    QDial   *Dial;
/////////////////////////
//    QTimer  *timer;
 //   int     angle_C;
///////////////////////
public:
    void init();
    void Turn_right();
    void Turn_left();
    void Go_ahead();
    void Go_back();
    void Stop();

};

#endif // MYWIDGRT_H
