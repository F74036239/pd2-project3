#ifndef NINEBOX_H
#define NINEBOX_H
#include"blank.h"
#include"delete_blank.h"
#include"vertical.h"
#include"horizontal.h"

class ninebox : public delete_blank
{
public:
    ninebox();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10],Blank *clicked);
    virtual int condition(Blank *b[10][10],Blank *clicked);
    virtual ~ninebox();
};


#endif // NINEBOX_H
