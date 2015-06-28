#include "four.h"

using namespace std;

four::four():scoreSum(0)
{

}

void four::generate(Blank *b[10][10],Blank *clicked,int mode)
{
    int row = clicked->row;
    int col = clicked->column;

    switch(mode)
    {
    case 1:
        for(int i=0;i<4;i++)
        {
            move_success *d;
            int temp_num = b[row-2+i][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                if( (row-2+i)==row )b[row-2+i][col]->number+=10;
                else
                {
                    b[row-2+i][col]->number=0;
                    scoreSum+=2;
                }
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

    case 2:
        for(int i=0;i<4;i++)
        {
            move_success *d;
            int temp_num = b[row-1+i][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                if( (row-1+i)==row )b[row-1+i][col]->number+=10;
                else
                {
                    b[row-1+i][col]->number=0;
                    scoreSum+=2;
                }
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

    case 3:
        for(int i=0;i<4;i++)
        {
            move_success *d;
            int temp_num = b[row][col-2+i]->number/10;
            switch(temp_num)
            {
            case 0://normal
                if( (col-2+i)==col )b[row][col-2+i]->number+=20;
                else
                {
                    b[row][col-2+i]->number=0;
                    scoreSum+=2;
                }
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

    case 4:
        for(int i=0;i<4;i++)
        {
            move_success *d;
            int temp_num = b[row][col-1+i]->number/10;
            switch(temp_num)
            {
            case 0://normal
                if( (col-1+i)==col )b[row][col-1+i]->number+=20;
                else
                {
                    b[row][col-1+i]->number=0;
                    scoreSum+=2;
                }
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
    }
}

void four::eliminate(Blank *b[10][10],Blank *clicked,int mode)
{
    int row = clicked->row;
    int col = clicked->column;

    if(mode==1) //vertical
        for(int i=0;i<10;i++)
        {
            move_success *d;
            switch(b[i][col]->number/10)
            {
            case 0: //normal
                b[i][col]->number=0;
                scoreSum+=2;
                break;

            case 1: //vertical
                if(i==row)
                {
                    b[i][col]->number=0;
                    scoreSum+=2;
                }
                else
                {
                    d = new four;
                    d->eliminate(b,b[i][col],1);   //mode=1
                    delete d;
                }
                break;

            case 2: //horizontal
                d = new four;
                d->eliminate(b,b[i][col],2);    //mode=2
                delete d;
                break;

            case 3: //bomb
                d = new bomb;
                d->eliminate(b,b[i][col]);
                delete d;
                break;

            case 5: //star
                d = new star;
                d->eliminate(b,b[i][col]);
                delete d;
                break;
            }
        }


    else if(mode==2)  //horizontal
        for(int i=0;i<10;i++)
        {
            move_success *d;
            switch(b[row][i]->number/10)
            {
            case 0: //normal
                b[row][i]->number=0;
                scoreSum+=2;
                break;

            case 1: //vertical
                d = new four;
                d->eliminate(b,b[row][i],1);   //mode=1
                delete d;
                break;

            case 2: //horizontal
                if(i==col)
                {
                    b[row][i]->number=0;
                    scoreSum+=2;
                }
                else
                {
                    d = new four;
                    d->eliminate(b,b[row][i],2);    //mode=2
                    delete d;
                }
                break;

            case 3: //bomb
                d = new bomb;
                d->eliminate(b,b[row][i]);
                delete d;
                break;

            case 5: //star
                d = new star;
                d->eliminate(b,b[row][i]);
                delete d;
                break;
            }
        }
}

int four::whichType(Blank *b[10][10],Blank *clicked)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;

    num = num % 10;
    if( num!=0  )   //再改
    {
        if(row<=8 && row>=2 && (b[row+1][col]->number%10==num) && (b[row-1][col]->number%10==num) && (b[row-2][col]->number%10==num) )
            return 1;  //vertical  up2 down1
        if(row<=7 && row>=1 && (b[row+1][col]->number%10==num) && (b[row+2][col]->number%10==num) && (b[row-1][col]->number%10==num) )
            return 2;  //vertical  up1 down2
        if( col>=2 && col<=8 && (b[row][col-1]->number%10==num) && (b[row][col-2]->number%10==num) && (b[row][col+1]->number%10==num) )
            return 3;  //horizontal left2 right1
        if( col>=1 && col<=7 && (b[row][col-1]->number%10==num) && (b[row][col+1]->number%10==num) && (b[row][col+2]->number%10==num) )
            return 4;  //horizontal left1 right2
    }
    return 0;
}

four::~four()
{

}

