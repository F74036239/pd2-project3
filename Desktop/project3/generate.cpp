#include "generate.h"

generate::generate()
{

}

void generate::produce(Blank *b[10][10],Blank *clicked,int mode)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;
    int arrNum[5]={0};
    switch (mode)
    {
    case 1:  //垂直生成星星
        clicked->number=5;  //中間變星星
        //如果左邊兩個相同
        if(col>=2 && ((num==b[row][col-2]->number) || (num==b[row][col-2]->number%10)) && ((num==b[row][col-1]->number) || (num==b[row][col-1]->number%10)))
        {
            //變空白
            b[row][col-2]->number=0;
            b[row][col-1]->number=0;
        }
        //如果右邊兩個相同
        else if(col<=7 && ((num==b[row][col+1]->number) || (num==b[row][col+1]->number%10)) && ((num==b[row][col+2]->number) || (num==b[row][col+2]->number%10)))
        {
            b[row][col+1]->number=0;
            b[row][col+2]->number=0;
        }
        //如果是特殊形態 arrNum存形態
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
            case 0://一般形態
                b[row-2+i][col]->number=0; //垂直的方向
                break;
            case 1://垂直
                d=new vertical;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 2://水平
                d=new horizontal;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 3://炸彈
                d=new ninebox;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            }
        }
        break;
    case 2:     //水平生成星星
        clicked->number=5;
        //如果上面兩個相同
        if(row>=2 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number%10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number%10)))
        {
            //變空白
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }
        //如果下面兩個相同
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
                b[row][col-2+i]->number=0;
                break;
            case 1://垂直
                d=new vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2://水平
                d=new horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3://炸彈
                d=new ninebox;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }
        break;
    case 3:
        clicked->number=5;
        break;
    case 4:
        clicked->number=5;
        break;
    default:
        break;
    }
}

void generate::eliminate(Blank *b[10][10],Blank *clicked)
{

}

int generate:: condition(Blank *b[10][10],Blank *clicked)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;
    if(num!=0 && num!=5)  //產生星星
    {
        if(num/10==0) //一般圖案
        {
            //上下方向 不能超過邊界 要可以往上找兩個 也可以往下找兩個  而且跟上面下面同顏色(有不同形態)
            if(row>=2 && row<=7 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number%10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number%10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number%10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number%10)))
                return 1;
            //左右方向 要可以往右找兩個 也可以往左找兩個  而且跟左右同顏色(有不同形態)
            if(col>=2 && col<=7 && ((num==b[row][col-2]->number)||(num==b[row][col-2]->number%10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number%10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number%10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number%10)))
                return 2;
        }
        else //特殊形態的圖案
        {
            num=num%10;     //得到顏色
            //上下
            if(row>=2 && row<=7 && ((num==b[row-2][col]->number) || (num==b[row-2][col]->number%10)) && ((num==b[row-1][col]->number) || (num==b[row-1][col]->number%10)) && ((num==b[row+1][col]->number) || (num==b[row+1][col]->number%10)) && ((num==b[row+2][col]->number) || (num==b[row+2][col]->number%10)))
                return 3;
            //左右
            if(col>=2 && col<=7 && ((num==b[row][col-2]->number)||(num==b[row][col-2]->number%10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number%10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number%10)))
                return 4;
        }

    }
    return 0;   //沒有星星
}

generate::~generate()
{

}

