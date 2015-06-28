#include "ninebox.h"

ninebox::ninebox()
{

}

void ninebox::produce(Blank *b[10][10], Blank *clicked, int mode)
{

}

void ninebox::eliminate(Blank *b[10][10], Blank *clicked)
{
    int row=clicked->row;
    int col=clicked->column;
    clicked->number=0;
    if(row>0 && col>0) b[row-1][col-1]->number=0;  //左上
    if(row>0) b[row-1][col]->number=0;             //上面
    if(col>0) b[row][col-1]->number=0;             //左邊

    if(row<9 && col<9) b[row+1][col+1]->number=0;  //右下
    if(row<9) b[row+1][col]->number=0;             //下面
    if(col<9) b[row][col+1]->number=0;             //右邊

    if(row<9 && col>0) b[row+1][col-1]->number=0;  //左下
    if(row>0 && col<9) b[row-1][col+1]->number=0;  //右上
}

int ninebox::condition(Blank *b[10][10], Blank *clicked)
{

}

ninebox::~ninebox()
{

}

