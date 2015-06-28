#include "vertical.h"

vertical::vertical()
{

}

void vertical::produce(Blank *b[10][10], Blank *clicked, int mode)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;
    int arrNum[5]={0};

}

void vertical::eliminate(Blank *b[10][10], Blank *clicked)
{
    //把垂直column消去
    int col=clicked->column;
    for(int i=0;i<10;i++)
        b[i][col]->number=0;
}

int vertical::condition(Blank *b[10][10], Blank *clicked)
{

}

vertical::~vertical()
{

}

