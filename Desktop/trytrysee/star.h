#ifndef STAR_H
#define STAR_H
#include "blank.h"
#include "move_success.h"
#include "bomb.h"
#include "four.h"
#include "three.h"

class star : public move_success
{
public:
    star();
    virtual void generate(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10], Blank *clicked ,int mode=1);
    virtual int whichType(Blank *b[10][10],Blank *clicked);
    virtual ~star();

    int scoreSum;
};

#endif // STAR_H
