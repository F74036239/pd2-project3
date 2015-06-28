#ifndef BOMB_H
#define BOMB_H
#include "blank.h"
#include "move_success.h"
#include "star.h"
#include "four.h"
#include "three.h"

class bomb : public move_success
{
public:
    bomb();
    virtual void generate(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10], Blank *clicked ,int mode=1);
    virtual int whichType(Blank *b[10][10],Blank *clicked);
    virtual ~bomb();

    int scoreSum;
};

#endif // BOMB_H
