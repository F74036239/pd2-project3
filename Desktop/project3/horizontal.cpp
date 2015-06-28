#include "horizontal.h"

horizontal::horizontal()
{

}

void horizontal::produce(Blank *b[10][10], Blank *clicked, int mode)
{

}

void horizontal::eliminate(Blank *b[10][10], Blank *clicked)
{
    //把水平row消去 ------
    int row=clicked->row;
    for(int i=0;i<10;i++)
        b[row][i]->number=0;
}

int horizontal::condition(Blank *b[10][10], Blank *clicked)
{

}

horizontal::~horizontal()
{

}

