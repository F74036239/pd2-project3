#ifndef DELETE_BLANK_H
#define DELETE_BLANK_H
#include"blank.h"

class delete_blank
{
public:
    delete_blank();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode)=0;
    virtual void eliminate(Blank *b[10][10],Blank *clicked)=0;
    virtual int condition(Blank *b[10][10],Blank *clicked)=0;
    virtual ~delete_blank();
};

#endif // DELETE_BLANK_H
