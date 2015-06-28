#ifndef THREE_H
#define THREE_H
#include "blank.h"
#include "move_success.h"
#include "star.h"
#include "bomb.h"
#include "four.h"

class three : public move_success
{
public:
    three();
    virtual void generate(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10], Blank *clicked ,int mode=1);
    virtual int whichType(Blank *b[10][10],Blank *clicked);
    virtual ~three();

    int scoreSum;
};

#endif // THREE_H
