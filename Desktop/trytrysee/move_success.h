#ifndef MOVE_SUCCESS_H
#define MOVE_SUCCESS_H
#include "blank.h"

class move_success
{
public:
    move_success();
    virtual void generate(Blank *b[10][10],Blank *clicked,int mode)=0;
    virtual void eliminate(Blank *b[10][10], Blank *clicked ,int mode=1)=0;
    virtual int whichType(Blank *b[10][10],Blank *clicked)=0;
    virtual ~move_success();

    int scoreSum;
};

#endif // MOVE_SUCCESS_H
