#ifndef NORMAL_DELETE_H
#define NORMAL_DELETE_H
#include"blank.h"
#include"delete_blank.h"
#include"vertical.h"
#include"ninebox.h"
#include"horizontal.h"

class normal_delete : public delete_blank
{
public:
    normal_delete();
    virtual void produce(Blank *b[10][10],Blank *clicked,int mode);
    virtual void eliminate(Blank *b[10][10],Blank *clicked);
    virtual int condition(Blank *b[10][10],Blank *clicked);
    virtual ~normal_delete();
};

#endif // NORMAL_DELETE_H
