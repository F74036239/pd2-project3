#ifndef GENERATE_H
#define GENERATE_H
#include "blank.h"
#include "delete_blank.h"
#include"horizontal.h"
#include"ninebox.h"
#include"vertical.h"

class generate : public delete_blank  //繼承自delete_blank 有多型
{
public:
    generate();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10],Blank *clicked);
    virtual int condition(Blank *b[10][10],Blank *clicked);
    virtual~generate();
};

#endif // GENERATE_H
