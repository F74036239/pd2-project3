#ifndef TIMER_H
#define TIMER_H
#include <QTime>

class timer
{
public:
    QTime *time;
    int lefttime(int n);  //n:時間
    timer();
    ~timer();
};

#endif // TIMER_H
