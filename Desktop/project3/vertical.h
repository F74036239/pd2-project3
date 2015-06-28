#ifndef VERTICAL_H
#define VERTICAL_H
#include"blank.h"
#include"delete_blank.h"
#include"horizontal.h"
#include"ninebox.h"

class vertical: public delete_blank
{
public:
    vertical();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10],Blank *clicked);
    virtual int condition(Blank *b[10][10],Blank *clicked);
    virtual ~vertical();
};

#endif // VERTICAL_H
