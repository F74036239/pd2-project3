#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include"blank.h"
#include"delete_blank.h"
#include"vertical.h"
#include"ninebox.h"

class horizontal: public delete_blank
{
public:
    horizontal();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10],Blank *clicked);
    virtual int condition(Blank *b[10][10],Blank *clicked);
    virtual ~horizontal();
};

#endif // HORIZONTAL_H
