#ifndef DELETE_H
#define DELETE_H
#include "blank.h"

class delete
{
public:
    delete();
    virtual void spawn(Blank *b[10][10],Blank *clicked,int mode)=0;
    virtual void eliminate(Blank *b[10][10],Blank *clicked)=0;
    virtual int condition(Blank *b[10][10],Blank *clicked)=0;
    virtual ~delete();
};

#endif // DELETE_H
