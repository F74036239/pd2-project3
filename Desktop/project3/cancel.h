#ifndef CANCEL_H
#define CANCEL_H
#include "blank.h"

class cancel
{
public:
    cancel();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode)=0;
    virtual void eliminate(Blank *b[10][10],Blank *clicked)=0;
    virtual int condition(Blank *b[10][10],Blank *clicked)=0;
    virtual ~cancel();
};

#endif // CANCEL_H
