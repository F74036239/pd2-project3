#include "three.h"

three::three():scoreSum(0)
{

}

void three::generate(Blank *b[10][10], Blank *clicked, int mode)
{
    int row = clicked->row;
    int col = clicked->column;

    switch(mode)
    {
    case 1:
        for(int i=0;i<3;i++)
        {
            move_success *d;
            int temp_num = b[row-1+i][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row-1+i][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row-1+i][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row-1+i][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;
            }
        }
        break;

    case 2:
        for(int i=0;i<3;i++)
        {
            move_success *d;
            int temp_num = b[row-2+i][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row-2+i][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row-2+i][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row-2+i][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            }
        }
        break;

    case 3:
        for(int i=0;i<3;i++)
        {
            move_success *d;
            int temp_num = b[row+i][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row+i][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row+i][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row+i][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row+i][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row+i][col]);
                delete d;
                break;
            }
        }
        break;

    case 4:
        for(int i=0;i<3;i++)
        {
            move_success *d;
            int temp_num = b[row][col-1+i]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col-1+i]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col-1+i],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col-1+i],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;
            }
        }
        break;

    case 5:
        for(int i=0;i<3;i++)
        {
            move_success *d;
            int temp_num = b[row][col-2+i]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col-2+i]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col-2+i],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col-2+i],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;

    case 6:
        for(int i=0;i<3;i++)
        {
            move_success *d;
            int temp_num = b[row][col+i]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col+i]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col+i],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col+i],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;
            }
        }
        break;
    }
}

void three::eliminate(Blank *b[10][10],Blank *clicked,int mode)
{
}

int three::whichType(Blank *b[10][10], Blank *clicked)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;

    num = num % 10;
    if( num!=0 )   //再改
    {
        if(row<=8 && row>=1 && (b[row-1][col]->number%10==num) && (b[row+1][col]->number%10==num) )
            return 1;  //vertical  up1 down1
        if(row>=2 && (b[row-1][col]->number%10==num) && (b[row-2][col]->number%10==num) )
            return 2;  //vertical  up2
        if(row<=7 && (b[row+1][col]->number%10==num) && (b[row+2][col]->number%10==num) )
            return 3;  //vertical  down2
        if(col>=1 && col<=8 && (b[row][col-1]->number%10==num) && (b[row][col+1]->number%10==num) )
            return 4;  //horizontal left1 right1
        if(col>=2 && (b[row][col-1]->number%10==num) && (b[row][col-2]->number%10==num) )
            return 5;  //horizontal left2
        if(col<=7 && (b[row][col+1]->number%10==num) && (b[row][col+2]->number%10==num) )
            return 6;  //horizontal right2
    }
    return 0;
}

three::~three()
{

}

