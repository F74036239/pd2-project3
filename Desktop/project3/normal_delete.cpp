#include "normal_delete.h"

normal_delete::normal_delete()
{

}

void normal_delete::produce(Blank *b[10][10], Blank *clicked, int mode)
{

}

void normal_delete::eliminate(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;
    int col=clicked->column;
    //delete left and right ---
    for(int i=col-1;i<=col+1;i++)
        b[row][i]->number=0;
    //delete up and down
    for(int i=row-1;i<=row+1;i++)
        b[i][row]->number=0;
}

int normal_delete::condition(Blank *b[10][10], Blank *clicked)
{

}

normal_delete::~normal_delete()
{

}



