#include "star.h"

star::star():scoreSum(0)
{

}

void star::generate(Blank *b[10][10],Blank *clicked,int mode)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;

    num = num % 10;     //color

    switch (mode)
    {
    case 1:
        //vertical
        if( (col>=2) && (b[row][col-1]->number%10==num) && (b[row][col-2]->number%10==num) )
        {
            //特殊效果 b[row][col-1]
            move_success *d1;
            int temp_num = b[row][col-1]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row][col-1]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical effect
                d1 = new four;
                d1->eliminate(b,b[row][col-1],1);   //mode=1
                delete d1;
                break;

            case 2://horizontal effect
                d1 = new four;
                d1->eliminate(b,b[row][col-1],2);    //mode=2
                delete d1;
                break;

            case 3://bomb effect
                d1 = new bomb;
                d1->eliminate(b,b[row][col-1]);
                delete d1;
                break;
            }

            //特殊效果 b[row][col-2]
            move_success *d2;
            temp_num = b[row][col-2]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row][col-2]->number=0;
                break;

            case 1://vertical effect
                d2 = new four;
                d2->eliminate(b,b[row][col-2],1);   //mode=1
                delete d2;
                break;

            case 2://horizontal effect
                d2 = new four;
                d2->eliminate(b,b[row][col-2],2);    //mode=2
                delete d2;
                break;

            case 3://bomb effect
                d2 = new bomb;
                d2->eliminate(b,b[row][col-2]);
                delete d2;
                break;
            }
        }

        if( (col<=7) && (b[row][col+1]->number%10==num) && (b[row][col+2]->number%10==num) )
        {
            //特殊效果 b[row][col+1]
            move_success *d1;
            int temp_num = b[row][col+1]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row][col+1]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical effect
                d1 = new four;
                d1->eliminate(b,b[row][col+1],1);   //mode=1
                delete d1;
                break;

            case 2://horizontal effect
                d1 = new four;
                d1->eliminate(b,b[row][col+1],2);    //mode=2
                delete d1;
                break;

            case 3://bomb effect
                d1 = new bomb;
                d1->eliminate(b,b[row][col+1]);
                delete d1;
                break;
            }

            //特殊效果 b[row][col+2]
            move_success *d2;
            temp_num = b[row][col+2]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row][col+2]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical effect
                d2 = new four;
                d2->eliminate(b,b[row][col+2],1);   //mode=1
                delete d2;
                break;

            case 2://horizontal effect
                d2 = new four;
                d2->eliminate(b,b[row][col+2],2);    //mode=2
                delete d2;
                break;

            case 3://bomb effect
                d2 = new bomb;
                d2->eliminate(b,b[row][col+2]);
                delete d2;
                break;
            }
        }

        for(int i=0;i<5;i++)
        {
            move_success *d;
            int temp_num = b[row-2+i][col]->number/10;

            switch(temp_num)
            {
            case 0://normal effect
                if( (row-2+i)==row) b[row-2+i][col]->number = 55;
                else
                {
                    b[row-2+i][col]->number=0;
                    scoreSum+=2;
                }

                break;

            case 1://vertical effect
                d = new four;
                d->eliminate(b,b[row-2+i][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal effect
                d = new four;
                d->eliminate(b,b[row-2+i][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb effect
                d = new bomb;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;

            case 5://star effect
                d = new star;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            }
        }
        break;

    case 2:
        //horizontal
        if( (row>=2) && (b[row-1][col]->number%10==num) && (b[row-2][col]->number%10==num) )
        {
            //特殊效果 b[row-1][col]
            move_success *d1;
            int temp_num = b[row-1][col]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row-1][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical effect
                d1 = new four;
                d1->eliminate(b,b[row-1][col],1);   //mode=1
                delete d1;
                break;

            case 2://horizontal effect
                d1 = new four;
                d1->eliminate(b,b[row-1][col],2);    //mode=2
                delete d1;
                break;

            case 3://bomb effect
                d1 = new bomb;
                d1->eliminate(b,b[row-1][col]);
                delete d1;
                break;
            }

            //特殊效果 b[row-2][col]
            move_success *d2;
            temp_num = b[row-2][col]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row-2][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical effect
                d2 = new four;
                d2->eliminate(b,b[row-2][col],1);   //mode=1
                delete d2;
                break;

            case 2://horizontal effect
                d2 = new four;
                d2->eliminate(b,b[row-2][col],2);    //mode=2
                delete d2;
                break;

            case 3://bomb effect
                d2 = new bomb;
                d2->eliminate(b,b[row-2][col]);
                delete d2;
                break;
            }
        }

        if( (row<=7) && (b[row+1][col]->number%10==num) && (b[row+2][col]->number%10==num) )
        {
            //特殊效果 b[row+1][col]
            move_success *d1;
            int temp_num = b[row+1][col]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row-1][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical effect
                d1 = new four;
                d1->eliminate(b,b[row+1][col],1);   //mode=1
                delete d1;
                break;

            case 2://horizontal effect
                d1 = new four;
                d1->eliminate(b,b[row+1][col],2);    //mode=2
                delete d1;
                break;

            case 3://bomb effect
                d1 = new bomb;
                d1->eliminate(b,b[row+1][col]);
                delete d1;
                break;
            }

            //特殊效果 b[row+2][col]
            move_success *d2;
            temp_num = b[row+2][col]->number/10;
            switch(temp_num)
            {
            case 0://normal effect
                b[row+2][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical effect
                d2 = new four;
                d2->eliminate(b,b[row+2][col],1);   //mode=1
                delete d2;
                break;

            case 2://horizontal effect
                d2 = new four;
                d2->eliminate(b,b[row+2][col],2);    //mode=2
                delete d2;
                break;

            case 3://bomb effect
                d2 = new bomb;
                d2->eliminate(b,b[row+2][col]);
                delete d2;
                break;
            }
        }

        for(int i=0;i<5;i++)
        {
            move_success *d;
            int temp_num = b[row][col-2+i]->number/10;

            switch(temp_num)
            {
            case 0://normal effect
                if( (col-2+i)==col) b[row][col-2+i]->number = 55;
                else
                {
                    b[row][col-2+i]->number=0;
                    scoreSum+=2;
                }
                break;

            case 1://vertical effect
                d = new four;
                d->eliminate(b,b[row][col-2+i],1);   //mode=1
                delete d;
                break;

            case 2://horizontal effect
                d = new four;
                d->eliminate(b,b[row][col-2+i],2);    //mode=2
                delete d;
                break;

            case 3://bomb effect
                d = new bomb;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;

            case 5://star effect
                d = new star;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
    }
}

void star::eliminate(Blank *b[10][10], Blank *clicked,int mode)
{
    int num = clicked->number;

    num = num % 10;   //color
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(b[i][j]->number%10==num)
            {
                move_success *d;
                switch(b[i][j]->number/10)
                {
                case 0: //normal
                    b[i][j]->number=0;
                    scoreSum+=2;
                    break;
                case 1: //vertical
                    d = new four;
                    d->eliminate(b,b[i][j],1);   //mode=1
                    delete d;
                    break;
                case 2: //horizontal
                    d = new four;
                    d->eliminate(b,b[i][j],2);    //mode=2
                    delete d;
                    break;
                case 3: //bomb
                    d = new bomb;
                    d->eliminate(b,b[i][j]);
                    delete d;
                    break;
                }

            }
}

int star::whichType(Blank *b[10][10],Blank *clicked)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;

    if( num!=0 && num!=55 )  //generate star
    {
            //vertical cannot over boundary 要可以往上找兩個 也可以往下找兩個  而且跟上面下面同顏色(有不同形態)
            if( row>=2 && row<=7 && (num==b[row-2][col]->number%10) && (num==b[row-1][col]->number%10) && (num==b[row+1][col]->number%10) && (num==b[row+2][col]->number%10))
                return 1;
            //horizontal 要可以往右找兩個 也可以往左找兩個  而且跟左右同顏色(有不同形態)
            if( col>=2 && col<=7 && (num==b[row][col-2]->number%10) && (num==b[row][col-1]->number%10) && (num==b[row][col+1]->number%10) && (num==b[row][col+2]->number%10))
                return 2;
    }
    return 0;   //no star

}

star::~star()
{

}


