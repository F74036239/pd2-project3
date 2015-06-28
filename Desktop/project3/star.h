#ifndef STAR_H
#define STAR_H
#include "blank.h"
#include "delete_blank.h"
#include"horizontal.h"
#include"ninebox.h"
#include"vertical.h"

class star : public delete_blank  //繼承自delete_blank 有多型

{
public:
    star();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10],Blank *clicked);
    virtual int condition(Blank *b[10][10],Blank *clicked);
    virtual~star();
};

#endif // STAR_H
