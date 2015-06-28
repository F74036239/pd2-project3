#ifndef FOUR_H
#define FOUR_H

#include<iostream>

#include "blank.h"
#include "move_success.h"
#include "star.h"
#include "bomb.h"
#include "three.h"

class four : public move_success
{
public:
    four();
    virtual void generate(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10], Blank *clicked ,int mode=1);
    virtual int whichType(Blank *b[10][10],Blank *clicked);
    virtual ~four();

    int scoreSum;
};

#endif // FOUR_H
