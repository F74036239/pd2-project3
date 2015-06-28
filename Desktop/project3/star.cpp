#include "star.h"

star::star()
{

}

void star::produce(Blank *b[10][10],Blank *clicked,int mode)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;
    int arrNum[5]={0};
    switch (mode)
    {
    case 1:  //vertical generate star
        clicked->number=5;  //middle become star
        //left left are same
        if(col>=2 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number%10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number%10)))
        {
            //be deleted
            b[row][col-2]->number=0;
            b[row][col-1]->number=0;
        }
        //right right are same
        else if(col<=7 && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number%10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number%10)))
        {
            b[row][col+1]->number=0;
            b[row][col+2]->number=0;
        }
        //special form arrNum存形態
        if(b[row-2][col]->number/10!=0)
            arrNum[0]=b[row-2][col]->number/10;

        if(b[row-1][col]->number/10!=0)
            arrNum[1]=b[row-1][col]->number/10;

        arrNum[2]=b[row][col]->number;

        if(b[row+1][col]->number/10!=0)
            arrNum[3]=b[row+1][col]->number/10;

        if(b[row+2][col]->number/10!=0)
            arrNum[4]=b[row+2][col]->number/10;

        for(int i=0;i<5;i++)
        {
            delete_blank *d;
            switch (arrNum[i])
            {
            case 0://normal form
                b[row-2+i][col]->number=0; //up or down normal form be deleted
                break;
            case 1://vertical
                d=new vertical;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 2://horizontal
                d=new horizontal;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 3://bomb
                d=new ninebox;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            }
        }
        break;
    case 2:     //horizontal generate star
        clicked->number=5;
        //up are same
        if(row>=2 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number%10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number%10)))
        {
            //變空白
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }
        //down are same
        else if(row<=7 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number%10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number%10)))
        {
            b[row+1][col]->number=0;
            b[row+2][col]->number=0;
        }

        if(b[row][col-2]->number/10!=0)
            arrNum[0]=b[row][col-2]->number/10;

        if(b[row][col-1]->number/10!=0)
            arrNum[1]=b[row][col-1]->number/10;

        arrNum[2]=b[row][col]->number;

        if(b[row][col+1]->number/10!=0)
            arrNum[3]=b[row][col+1]->number/10;

        if(b[row][col+2]->number/10!=0)
            arrNum[4]=b[row][col+2]->number/10;

        for(int i=0;i<5;i++)
        {
            delete_blank *d;
            switch (arrNum[i])
            {
            case 0:
                b[row][col-2+i]->number=0;  //horizontal direction normal form be deleted
                break;
            case 1://vertical
                d=new vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2://horizontal
                d=new horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3://bomb
                d=new ninebox;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
    case 3:  //vertical star + special form
        num=num%10;     //get color
        //left left are same
        if(col>=2 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number%10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number%10)))
        {
            //be deleted
            b[row][col-2]->number=0;
            b[row][col-1]->number=0;
        }
        //right right are same
        else if(col<=7 && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number%10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number%10)))
        {
            b[row][col+1]->number=0;
            b[row][col+2]->number=0;
        }
        //special form arrNum存形態
        if(b[row-2][col]->number/10!=0)
            arrNum[0]=b[row-2][col]->number/10;

        if(b[row-1][col]->number/10!=0)
            arrNum[1]=b[row-1][col]->number/10;

        arrNum[2]=b[row][col]->number/10;

        if(b[row+1][col]->number/10!=0)
            arrNum[3]=b[row+1][col]->number/10;

        if(b[row+2][col]->number/10!=0)
            arrNum[4]=b[row+2][col]->number/10;

        for(int i=0;i<5;i++)
        {
            delete_blank *d;
            switch (arrNum[i])
            {
            case 0://normal form
                b[row-2+i][col]->number=0; //up or down normal form be deleted
                break;
            case 1://vertical
                d=new vertical;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 2://horizontal
                d=new horizontal;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 3://bomb
                d=new ninebox;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            }
        }
        break;
    case 4:// horizontal star + special form
        num=num%10;
        //up are same
        if(row>=2 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number%10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number%10)))
        {
            //變空白
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }
        //down are same
        else if(row<=7 && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number%10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number%10)))
        {
            b[row+1][col]->number=0;
            b[row+2][col]->number=0;
        }

        if(b[row][col-2]->number/10!=0)
            arrNum[0]=b[row][col-2]->number/10;

        if(b[row][col-1]->number/10!=0)
            arrNum[1]=b[row][col-1]->number/10;

        arrNum[2]=b[row][col]->number/10;

        if(b[row][col+1]->number/10!=0)
            arrNum[3]=b[row][col+1]->number/10;

        if(b[row][col+2]->number/10!=0)
            arrNum[4]=b[row][col+2]->number/10;

        for(int i=0;i<5;i++)
        {
            delete_blank *d;
            switch (arrNum[i])
            {
            case 0:
                b[row][col-2+i]->number=0;  //horizontal direction normal form be deleted
                break;
            case 1://vertical
                d=new vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2://horizontal
                d=new horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3://bomb
                d=new ninebox;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
    }
}

void star::eliminate(Blank *b[10][10],Blank *clicked)
{

}

int star:: condition(Blank *b[10][10],Blank *clicked)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;
    if(num!=0 && num!=5)  //generate star
    {
        if(num/10==0) //normal form
        {
            //vertical cannot over boundary 要可以往上找兩個 也可以往下找兩個  而且跟上面下面同顏色(有不同形態)
            if(row>=2 && row<=7 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number%10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number%10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number%10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number%10)))
                return 1;
            //horizontal 要可以往右找兩個 也可以往左找兩個  而且跟左右同顏色(有不同形態)
            if(col>=2 && col<=7 && ((num==b[row][col-2]->number)||(num==b[row][col-2]->number%10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number%10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number%10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number%10)))
                return 2;
        }
        else //special form
        {
            num=num%10;     //get color
            //vertical
            if(row>=2 && row<=7 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number%10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number%10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number%10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number%10)))
                return 3;
            //horizontal
            if(col>=2 && col<=7 && ((num==b[row][col-2]->number)||(num==b[row][col-2]->number%10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number%10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number%10)))
                return 4;
        }

    }
    return 0;   //no star
}


star::~star()
{

}

