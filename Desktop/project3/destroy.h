#ifndef DESTROY_H
#define DESTROY_H
#include "blank.h"

class destroy
{
public:
    destroy();
    virtual void spawn(Blank *b[10][10],Blank *clicked,int mode)=0;
    virtual void eliminate(Blank *b[10][10],Blank *clicked)=0;
    virtual int condition(Blank *b[10][10],Blank *clicked)=0;
    virtual ~destroy();
};

#endif // DESTROY_H
