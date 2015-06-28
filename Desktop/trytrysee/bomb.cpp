#include "bomb.h"

bomb::bomb():scoreSum(0)
{

}

void bomb::generate(Blank *b[10][10], Blank *clicked, int mode)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;
    int temp_num;
    num = num % 10;     //color

    switch (mode)
    {
    case 1:
        if(row>=1 && (b[row-1][col]->number%10==num) ) //1up same
        {
            //特殊效果 b[row-1][col]
            move_success *d;
            temp_num = b[row-1][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row-1][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row-1][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row-1][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row-1][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row-1][col]);
                delete d;
                break;
            }
        }

        if(col<=8 && (b[row][col+1]->number%10==num) ) //1right same
        {
            //特殊效果 b[row][col+1]
            move_success *d;
            temp_num = b[row][col+1]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col+1]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col+1],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col+1],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col+1]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col+1]);
                delete d;
                break;
            }
        }

        move_success *d11;
        temp_num = b[row][col-2]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-2]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d11 = new four;
            d11->eliminate(b,b[row][col-2],1);   //mode=1
            delete d11;
            break;

        case 2://horizontal
            d11 = new four;
            d11->eliminate(b,b[row][col-2],2);    //mode=2
            delete d11;
            break;

        case 3://bomb
            d11 = new bomb;
            d11->eliminate(b,b[row][col-2]);
            delete d11;
            break;

        case 5://star
            d11 = new star;
            d11->eliminate(b,b[row][col-2]);
            delete d11;
            break;
        }

        move_success *d12;
        temp_num = b[row][col-1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d12 = new four;
            d12->eliminate(b,b[row][col-1],1);   //mode=1
            delete d12;
            break;

        case 2://horizontal
            d12 = new four;
            d12->eliminate(b,b[row][col-1],2);    //mode=2
            delete d12;
            break;

        case 3://bomb
            d12 = new bomb;
            d12->eliminate(b,b[row][col-1]);
            delete d12;
            break;

        case 5://star
            d12 = new star;
            d12->eliminate(b,b[row][col-1]);
            delete d12;
            break;
        }

        move_success *d13;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d13 = new four;
            d13->eliminate(b,b[row][col],1);   //mode=1
            delete d13;
            break;

        case 2://horizontal
            d13 = new four;
            d13->eliminate(b,b[row][col],2);    //mode=2
            delete d13;
            break;

        case 3://bomb
            d13 = new bomb;
            d13->eliminate(b,b[row][col]);
            delete d13;
            break;

        case 5://star
            d13 = new star;
            d13->eliminate(b,b[row][col]);
            delete d13;
            break;
        }

        move_success *d14;
        temp_num = b[row+1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row+1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d14 = new four;
            d14->eliminate(b,b[row+1][col],1);   //mode=1
            delete d14;
            break;

        case 2://horizontal
            d14 = new four;
            d14->eliminate(b,b[row+1][col],2);    //mode=2
            delete d14;
            break;

        case 3://bomb
            d14 = new bomb;
            d14->eliminate(b,b[row+1][col]);
            delete d14;
            break;

        case 5://star
            d14 = new star;
            d14->eliminate(b,b[row+1][col]);
            delete d14;
            break;
        }

        move_success *d15;
        temp_num = b[row+2][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row+2][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d15 = new four;
            d15->eliminate(b,b[row+2][col],1);   //mode=1
            delete d15;
            break;

        case 2://horizontal
            d15 = new four;
            d15->eliminate(b,b[row+2][col],2);    //mode=2
            delete d15;
            break;

        case 3://bomb
            d15 = new bomb;
            d15->eliminate(b,b[row+2][col]);
            delete d15;
            break;

        case 5://star
            d15 = new star;
            d15->eliminate(b,b[row+2][col]);
            delete d15;
            break;
        }
        break;

    case 2:
        if(row<=8 && (b[row+1][col]->number%10==num) ) //1down same
        {
            //特殊效果 b[row+1][col]
            move_success *d;
            temp_num = b[row+1][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row+1][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row+1][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row+1][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row+1][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row+1][col]);
                delete d;
                break;
            }
        }

        if(col<=8 && (b[row][col+1]->number%10==num) ) //1right same
        {
            //特殊效果 b[row][col+1]
            move_success *d;
            temp_num = b[row][col+1]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col+1]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col+1],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col+1],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col+1]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col+1]);
                delete d;
                break;
            }
        }

        move_success *d21;
        temp_num = b[row][col-2]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-2]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d21 = new four;
            d21->eliminate(b,b[row][col-2],1);   //mode=1
            delete d21;
            break;

        case 2://horizontal
            d21 = new four;
            d21->eliminate(b,b[row][col-2],2);    //mode=2
            delete d21;
            break;

        case 3://bomb
            d21 = new bomb;
            d21->eliminate(b,b[row][col-2]);
            delete d21;
            break;

        case 5://star
            d21 = new star;
            d21->eliminate(b,b[row][col-2]);
            delete d21;
            break;
        }

        move_success *d22;
        temp_num = b[row][col-1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d22 = new four;
            d22->eliminate(b,b[row][col-1],1);   //mode=1
            delete d22;
            break;

        case 2://horizontal
            d22 = new four;
            d22->eliminate(b,b[row][col-1],2);    //mode=2
            delete d22;
            break;

        case 3://bomb
            d22 = new bomb;
            d22->eliminate(b,b[row][col-1]);
            delete d22;
            break;

        case 5://star
            d22 = new star;
            d22->eliminate(b,b[row][col-1]);
            delete d22;
            break;
        }

        move_success *d23;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d23 = new four;
            d23->eliminate(b,b[row][col],1);   //mode=1
            delete d23;
            break;

        case 2://horizontal
            d23 = new four;
            d23->eliminate(b,b[row][col],2);    //mode=2
            delete d23;
            break;

        case 3://bomb
            d23 = new bomb;
            d23->eliminate(b,b[row][col]);
            delete d23;
            break;

        case 5://star
            d23 = new star;
            d23->eliminate(b,b[row][col]);
            delete d23;
            break;
        }

        move_success *d24;
        temp_num = b[row-1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d24 = new four;
            d24->eliminate(b,b[row-1][col],1);   //mode=1
            delete d24;
            break;

        case 2://horizontal
            d24 = new four;
            d24->eliminate(b,b[row-1][col],2);    //mode=2
            delete d24;
            break;

        case 3://bomb
            d24 = new bomb;
            d24->eliminate(b,b[row-1][col]);
            delete d24;
            break;

        case 5://star
            d24 = new star;
            d24->eliminate(b,b[row-1][col]);
            delete d24;
            break;
        }

        move_success *d25;
        temp_num = b[row-2][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-2][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d25 = new four;
            d25->eliminate(b,b[row-2][col],1);   //mode=1
            delete d25;
            break;

        case 2://horizontal
            d25 = new four;
            d25->eliminate(b,b[row-2][col],2);    //mode=2
            delete d25;
            break;

        case 3://bomb
            d25 = new bomb;
            d25->eliminate(b,b[row-2][col]);
            delete d25;
            break;

        case 5://star
            d25 = new star;
            d25->eliminate(b,b[row-2][col]);
            delete d25;
            break;
        }
        break;

    case 3:
        if(row>=1 && (b[row-1][col]->number%10==num) ) //1up same
        {
            //特殊效果 b[row-1][col]
            move_success *d;
            temp_num = b[row-1][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row-1][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row-1][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row-1][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row-1][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row-1][col]);
                delete d;
                break;
            }
        }

        if(col>=1 && (b[row][col-1]->number%10==num) ) //1left same
        {
            //特殊效果 b[row][col-1]
            move_success *d;
            temp_num = b[row][col-1]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col-1]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col-1],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col-1],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col-1]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col-1]);
                delete d;
                break;
            }
        }

        move_success *d31;
        temp_num = b[row+2][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row+2][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d31 = new four;
            d31->eliminate(b,b[row+2][col],1);   //mode=1
            delete d31;
            break;

        case 2://horizontal
            d31 = new four;
            d31->eliminate(b,b[row+2][col],2);    //mode=2
            delete d31;
            break;

        case 3://bomb
            d31 = new bomb;
            d31->eliminate(b,b[row+2][col]);
            delete d31;
            break;

        case 5://star
            d31 = new star;
            d31->eliminate(b,b[row+2][col]);
            delete d31;
            break;
        }

        move_success *d32;
        temp_num = b[row+1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row+1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d32 = new four;
            d32->eliminate(b,b[row+1][col],1);   //mode=1
            delete d32;
            break;

        case 2://horizontal
            d32 = new four;
            d32->eliminate(b,b[row+1][col],2);    //mode=2
            delete d32;
            break;

        case 3://bomb
            d32 = new bomb;
            d32->eliminate(b,b[row+1][col]);
            delete d32;
            break;

        case 5://star
            d32 = new star;
            d32->eliminate(b,b[row+1][col]);
            delete d32;
            break;
        }

        move_success *d33;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d33 = new four;
            d33->eliminate(b,b[row][col],1);   //mode=1
            delete d33;
            break;

        case 2://horizontal
            d33 = new four;
            d33->eliminate(b,b[row][col],2);    //mode=2
            delete d33;
            break;

        case 3://bomb
            d33 = new bomb;
            d33->eliminate(b,b[row][col]);
            delete d33;
            break;

        case 5://star
            d33 = new star;
            d33->eliminate(b,b[row][col]);
            delete d33;
            break;
        }

        move_success *d34;
        temp_num = b[row][col+1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d34 = new four;
            d34->eliminate(b,b[row][col+1],1);   //mode=1
            delete d34;
            break;

        case 2://horizontal
            d34 = new four;
            d34->eliminate(b,b[row][col+1],2);    //mode=2
            delete d34;
            break;

        case 3://bomb
            d34 = new bomb;
            d34->eliminate(b,b[row][col+1]);
            delete d34;
            break;

        case 5://star
            d34 = new star;
            d34->eliminate(b,b[row][col+1]);
            delete d34;
            break;
        }

        move_success *d35;
        temp_num = b[row][col+2]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+2]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d35 = new four;
            d35->eliminate(b,b[row][col+2],1);   //mode=1
            delete d35;
            break;

        case 2://horizontal
            d35 = new four;
            d35->eliminate(b,b[row][col+2],2);    //mode=2
            delete d35;
            break;

        case 3://bomb
            d35 = new bomb;
            d35->eliminate(b,b[row][col+2]);
            delete d35;
            break;

        case 5://star
            d35 = new star;
            d35->eliminate(b,b[row][col+2]);
            delete d35;
            break;
        }
        break;

    case 4:
        if(row<=8 && (b[row+1][col]->number%10==num) ) //1down same
        {
            //特殊效果 b[row+1][col]
            move_success *d;
            temp_num = b[row+1][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row+1][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row+1][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row+1][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row+1][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row+1][col]);
                delete d;
                break;
            }
        }

        if(col>=1 && (b[row][col-1]->number%10==num) ) //1left same
        {
            //特殊效果 b[row][col-1]
            move_success *d;
            temp_num = b[row][col-1]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col-1]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col-1],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col-1],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col-1]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col-1]);
                delete d;
                break;
            }
        }

        move_success *d41;
        temp_num = b[row-2][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-2][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d41 = new four;
            d41->eliminate(b,b[row-2][col],1);   //mode=1
            delete d41;
            break;

        case 2://horizontal
            d41 = new four;
            d41->eliminate(b,b[row-2][col],2);    //mode=2
            delete d41;
            break;

        case 3://bomb
            d41 = new bomb;
            d41->eliminate(b,b[row-2][col]);
            delete d41;
            break;

        case 5://star
            d41 = new star;
            d41->eliminate(b,b[row-2][col]);
            delete d41;
            break;
        }

        move_success *d42;
        temp_num = b[row-1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d42 = new four;
            d42->eliminate(b,b[row-1][col],1);   //mode=1
            delete d42;
            break;

        case 2://horizontal
            d42 = new four;
            d42->eliminate(b,b[row-1][col],2);    //mode=2
            delete d42;
            break;

        case 3://bomb
            d42 = new bomb;
            d42->eliminate(b,b[row-1][col]);
            delete d42;
            break;

        case 5://star
            d42 = new star;
            d42->eliminate(b,b[row-1][col]);
            delete d42;
            break;
        }

        move_success *d43;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d43 = new four;
            d43->eliminate(b,b[row][col],1);   //mode=1
            delete d43;
            break;

        case 2://horizontal
            d43 = new four;
            d43->eliminate(b,b[row][col],2);    //mode=2
            delete d43;
            break;

        case 3://bomb
            d43 = new bomb;
            d43->eliminate(b,b[row][col]);
            delete d43;
            break;

        case 5://star
            d43 = new star;
            d43->eliminate(b,b[row][col]);
            delete d43;
            break;
        }

        move_success *d44;
        temp_num = b[row][col+1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d44 = new four;
            d44->eliminate(b,b[row][col+1],1);   //mode=1
            delete d44;
            break;

        case 2://horizontal
            d44 = new four;
            d44->eliminate(b,b[row][col+1],2);    //mode=2
            delete d44;
            break;

        case 3://bomb
            d44 = new bomb;
            d44->eliminate(b,b[row][col+1]);
            delete d44;
            break;

        case 5://star
            d44 = new star;
            d44->eliminate(b,b[row][col+1]);
            delete d44;
            break;
        }

        move_success *d45;
        temp_num = b[row][col+2]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+2]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d45 = new four;
            d45->eliminate(b,b[row][col+2],1);   //mode=1
            delete d45;
            break;

        case 2://horizontal
            d45 = new four;
            d45->eliminate(b,b[row][col+2],2);    //mode=2
            delete d45;
            break;

        case 3://bomb
            d45 = new bomb;
            d45->eliminate(b,b[row][col+2]);
            delete d45;
            break;

        case 5://star
            d45= new star;
            d45->eliminate(b,b[row][col+2]);
            delete d45;
            break;
        }
        break;

    case 5:
        if(col>=2 && (b[row][col-2]->number%10==num) ) //left left same
        {
            //特殊效果 b[row][col-2]
            move_success *d;
            temp_num = b[row][col-2]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col-2]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col-2],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col-2],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col-2]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col-2]);
                delete d;
                break;
            }
        }

        if(col<=7 && (b[row][col+2]->number%10==num) ) //right right same
        {
            //特殊效果 b[row][col+2]
            move_success *d;
            temp_num = b[row][col+2]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col+2]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col+2],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col+2],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col+2]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col+2]);
                delete d;
                break;
            }
        }

        move_success *d51;
        temp_num = b[row][col-1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d51 = new four;
            d51->eliminate(b,b[row][col-1],1);   //mode=1
            delete d51;
            break;

        case 2://horizontal
            d51 = new four;
            d51->eliminate(b,b[row][col-1],2);    //mode=2
            delete d51;
            break;

        case 3://bomb
            d51 = new bomb;
            d51->eliminate(b,b[row][col-1]);
            delete d51;
            break;

        case 5://star
            d51 = new star;
            d51->eliminate(b,b[row][col-1]);
            delete d51;
            break;
        }

        move_success *d52;
        temp_num = b[row][col+1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d52 = new four;
            d52->eliminate(b,b[row][col+1],1);   //mode=1
            delete d52;
            break;

        case 2://horizontal
            d52 = new four;
            d52->eliminate(b,b[row][col+1],2);    //mode=2
            delete d52;
            break;

        case 3://bomb
            d52 = new bomb;
            d52->eliminate(b,b[row][col+1]);
            delete d52;
            break;

        case 5://star
            d52 = new star;
            d52->eliminate(b,b[row][col+1]);
            delete d52;
            break;
        }

        move_success *d53;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d53 = new four;
            d53->eliminate(b,b[row][col],1);   //mode=1
            delete d53;
            break;

        case 2://horizontal
            d53 = new four;
            d53->eliminate(b,b[row][col],2);    //mode=2
            delete d53;
            break;

        case 3://bomb
            d53 = new bomb;
            d53->eliminate(b,b[row][col]);
            delete d53;
            break;

        case 5://star
            d53 = new star;
            d53->eliminate(b,b[row][col]);
            delete d53;
            break;
        }

        move_success *d54;
        temp_num = b[row+1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row+1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d54 = new four;
            d54->eliminate(b,b[row+1][col],1);   //mode=1
            delete d54;
            break;

        case 2://horizontal
            d54 = new four;
            d54->eliminate(b,b[row+1][col],2);    //mode=2
            delete d54;
            break;

        case 3://bomb
            d54 = new bomb;
            d54->eliminate(b,b[row+1][col]);
            delete d54;
            break;

        case 5://star
            d54 = new star;
            d54->eliminate(b,b[row+1][col]);
            delete d54;
            break;
        }

        move_success *d20;
        temp_num = b[row+2][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row+2][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d20 = new four;
            d20->eliminate(b,b[row+2][col],1);   //mode=1
            delete d20;
            break;

        case 2://horizontal
            d20 = new four;
            d20->eliminate(b,b[row+2][col],2);    //mode=2
            delete d20;
            break;

        case 3://bomb
            d20 = new bomb;
            d20->eliminate(b,b[row+2][col]);
            delete d20;
            break;

        case 5://star
            d20 = new star;
            d20->eliminate(b,b[row+2][col]);
            delete d20;
            break;
        }
        break;

    case 6:
        if(col>=2 && (b[row][col-2]->number%10==num) ) //left left same
        {
            //特殊效果 b[row][col-2]
            move_success *d;
            temp_num = b[row][col-2]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col-2]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col-2],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col-2],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col-2]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col-2]);
                delete d;
                break;
            }
        }

        if(col<=7 && (b[row][col+2]->number%10==num) ) //right right same
        {
            //特殊效果 b[row][col+2]
            move_success *d;
            temp_num = b[row][col+2]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row][col+2]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row][col+2],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row][col+2],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row][col+2]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row][col+2]);
                delete d;
                break;
            }
        }

        move_success *d61;
        temp_num = b[row][col-1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d61 = new four;
            d61->eliminate(b,b[row][col-1],1);   //mode=1
            delete d61;
            break;

        case 2://horizontal
            d61 = new four;
            d61->eliminate(b,b[row][col-1],2);    //mode=2
            delete d61;
            break;

        case 3://bomb
            d61 = new bomb;
            d61->eliminate(b,b[row][col-1]);
            delete d61;
            break;

        case 5://star
            d61 = new star;
            d61->eliminate(b,b[row][col-1]);
            delete d61;
            break;
        }

        move_success *d62;
        temp_num = b[row][col+1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d62 = new four;
            d62->eliminate(b,b[row][col+1],1);   //mode=1
            delete d62;
            break;

        case 2://horizontal
            d62 = new four;
            d62->eliminate(b,b[row][col+1],2);    //mode=2
            delete d62;
            break;

        case 3://bomb
            d62 = new bomb;
            d62->eliminate(b,b[row][col+1]);
            delete d62;
            break;

        case 5://star
            d62 = new star;
            d62->eliminate(b,b[row][col+1]);
            delete d62;
            break;
        }

        move_success *d63;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d63 = new four;
            d63->eliminate(b,b[row][col],1);   //mode=1
            delete d63;
            break;

        case 2://horizontal
            d63 = new four;
            d63->eliminate(b,b[row][col],2);    //mode=2
            delete d63;
            break;

        case 3://bomb
            d63 = new bomb;
            d63->eliminate(b,b[row][col]);
            delete d63;
            break;

        case 5://star
            d63 = new star;
            d63->eliminate(b,b[row][col]);
            delete d63;
            break;
        }

        move_success *d64;
        temp_num = b[row-1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d64 = new four;
            d64->eliminate(b,b[row-1][col],1);   //mode=1
            delete d64;
            break;

        case 2://horizontal
            d64 = new four;
            d64->eliminate(b,b[row-1][col],2);    //mode=2
            delete d64;
            break;

        case 3://bomb
            d64 = new bomb;
            d64->eliminate(b,b[row-1][col]);
            delete d64;
            break;

        case 5://star
            d64 = new star;
            d64->eliminate(b,b[row-1][col]);
            delete d64;
            break;
        }

        move_success *d65;
        temp_num = b[row-2][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-2][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d65 = new four;
            d65->eliminate(b,b[row-2][col],1);   //mode=1
            delete d65;
            break;

        case 2://horizontal
            d65 = new four;
            d65->eliminate(b,b[row-2][col],2);    //mode=2
            delete d65;
            break;

        case 3://bomb
            d65 = new bomb;
            d65->eliminate(b,b[row-2][col]);
            delete d65;
            break;

        case 5://star
            d65 = new star;
            d65->eliminate(b,b[row-2][col]);
            delete d65;
            break;
        }

        break;

    case 7:
        if(row>=2 && (b[row-2][col]->number%10==num) ) //up up same
        {
            //特殊效果 b[row-2][col]
            move_success *d;
            temp_num = b[row-2][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row-2][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row-2][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row-2][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row-2][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row-2][col]);
                delete d;
                break;
            }
        }

        if(row<=7 && (b[row+2][col]->number%10==num) ) //down down same
        {
            //特殊效果 b[row+2][col]
            move_success *d;
            temp_num = b[row+2][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row+2][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row+2][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row+2][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row+2][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row+2][col]);
                delete d;
                break;
            }
        }

        move_success *d71;
        temp_num = b[row][col-2]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-2]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d71 = new four;
            d71->eliminate(b,b[row][col-2],1);   //mode=1
            delete d71;
            break;

        case 2://horizontal
            d71 = new four;
            d71->eliminate(b,b[row][col-2],2);    //mode=2
            delete d71;
            break;

        case 3://bomb
            d71 = new bomb;
            d71->eliminate(b,b[row][col-2]);
            delete d71;
            break;

        case 5://star
            d71 = new star;
            d71->eliminate(b,b[row][col-2]);
            delete d71;
            break;
        }

        move_success *d72;
        temp_num = b[row][col-1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col-1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d72 = new four;
            d72->eliminate(b,b[row][col-1],1);   //mode=1
            delete d72;
            break;

        case 2://horizontal
            d72 = new four;
            d72->eliminate(b,b[row][col-1],2);    //mode=2
            delete d72;
            break;

        case 3://bomb
            d72 = new bomb;
            d72->eliminate(b,b[row][col-1]);
            delete d72;
            break;

        case 5://star
            d72 = new star;
            d72->eliminate(b,b[row][col-1]);
            delete d72;
            break;
        }

        move_success *d73;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d73 = new four;
            d73->eliminate(b,b[row][col],1);   //mode=1
            delete d73;
            break;

        case 2://horizontal
            d73 = new four;
            d73->eliminate(b,b[row][col],2);    //mode=2
            delete d73;
            break;

        case 3://bomb
            d73 = new bomb;
            d73->eliminate(b,b[row][col]);
            delete d73;
            break;

        case 5://star
            d73 = new star;
            d73->eliminate(b,b[row][col]);
            delete d73;
            break;
        }

        move_success *d74;
        temp_num = b[row+1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row+1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d74 = new four;
            d74->eliminate(b,b[row+1][col],1);   //mode=1
            delete d74;
            break;

        case 2://horizontal
            d74 = new four;
            d74->eliminate(b,b[row+1][col],2);    //mode=2
            delete d74;
            break;

        case 3://bomb
            d74 = new bomb;
            d74->eliminate(b,b[row+1][col]);
            delete d74;
            break;

        case 5://star
            d74 = new star;
            d74->eliminate(b,b[row+1][col]);
            delete d74;
            break;
        }

        move_success *d75;
        temp_num = b[row-1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d75 = new four;
            d75->eliminate(b,b[row-1][col],1);   //mode=1
            delete d75;
            break;

        case 2://horizontal
            d75 = new four;
            d75->eliminate(b,b[row-1][col],2);    //mode=2
            delete d75;
            break;

        case 3://bomb
            d75 = new bomb;
            d75->eliminate(b,b[row-1][col]);
            delete d75;
            break;

        case 5://star
            d75 = new star;
            d75->eliminate(b,b[row-1][col]);
            delete d75;
            break;
        }

        break;

    case 8:
        if(row>=2 && (b[row-2][col]->number%10==num) ) //up up same
        {
            //特殊效果 b[row-2][col]
            move_success *d;
            temp_num = b[row-2][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row-2][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row-2][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row-2][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row-2][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row-2][col]);
                delete d;
                break;
            }
        }
        if(row<=7 && (b[row+2][col]->number%10==num) ) //down down same
        {
            //特殊效果 b[row+2][col]
            move_success *d;
            temp_num = b[row+2][col]->number/10;
            switch(temp_num)
            {
            case 0://normal
                b[row+2][col]->number=0;
                scoreSum+=2;
                break;

            case 1://vertical
                d = new four;
                d->eliminate(b,b[row+2][col],1);   //mode=1
                delete d;
                break;

            case 2://horizontal
                d = new four;
                d->eliminate(b,b[row+2][col],2);    //mode=2
                delete d;
                break;

            case 3://bomb
                d = new bomb;
                d->eliminate(b,b[row+2][col]);
                delete d;
                break;

            case 5://star
                d = new star;
                d->eliminate(b,b[row+2][col]);
                delete d;
                break;
            }
        }

        move_success *d81;
        temp_num = b[row][col+2]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+2]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d81 = new four;
            d81->eliminate(b,b[row][col+2],1);   //mode=1
            delete d81;
            break;

        case 2://horizontal
            d81 = new four;
            d81->eliminate(b,b[row][col+2],2);    //mode=2
            delete d81;
            break;

        case 3://bomb
            d81 = new bomb;
            d81->eliminate(b,b[row][col+2]);
            delete d81;
            break;

        case 5://star
            d81 = new star;
            d81->eliminate(b,b[row][col+2]);
            delete d81;
            break;
       }

        move_success *d82;
        temp_num = b[row][col+1]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col+1]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d82 = new four;
            d82->eliminate(b,b[row][col+1],1);   //mode=1
            delete d82;
            break;

        case 2://horizontal
            d82 = new four;
            d82->eliminate(b,b[row][col+1],2);    //mode=2
            delete d82;
            break;

        case 3://bomb
            d82 = new bomb;
            d82->eliminate(b,b[row][col+1]);
            delete d82;
            break;

        case 5://star
            d82 = new star;
            d82->eliminate(b,b[row][col+1]);
            delete d82;
            break;
        }

        move_success *d83;
        temp_num = b[row][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row][col]->number+=30;
            scoreSum+=2;
            break;

        case 1://vertical
            d83 = new four;
            d83->eliminate(b,b[row][col],1);   //mode=1
            delete d83;
            break;

        case 2://horizontal
            d83 = new four;
            d83->eliminate(b,b[row][col],2);    //mode=2
            delete d83;
            break;

        case 3://bomb
            d83 = new bomb;
            d83->eliminate(b,b[row][col]);
            delete d83;
            break;

        case 5://star
            d83 = new star;
            d83->eliminate(b,b[row][col]);
            delete d83;
            break;
        }

        move_success *d84;
        temp_num = b[row+1][col]->number/10;
        switch(temp_num)
       {
        case 0://normal
            b[row+1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d84 = new four;
            d84->eliminate(b,b[row+1][col],1);   //mode=1
            delete d84;
            break;

        case 2://horizontal
            d84 = new four;
            d84->eliminate(b,b[row+1][col],2);    //mode=2
            delete d84;
            break;

        case 3://bomb
            d84 = new bomb;
            d84->eliminate(b,b[row+1][col]);
            delete d84;
            break;

        case 5://star
            d84 = new star;
            d84->eliminate(b,b[row+1][col]);
            delete d84;
            break;
        }

        move_success *d85;
        temp_num = b[row-1][col]->number/10;
        switch(temp_num)
        {
        case 0://normal
            b[row-1][col]->number=0;
            scoreSum+=2;
            break;

        case 1://vertical
            d85 = new four;
            d85->eliminate(b,b[row-1][col],1);   //mode=1
            delete d85;
            break;

        case 2://horizontal
            d85 = new four;
            d85->eliminate(b,b[row-1][col],2);    //mode=2
            delete d85;
            break;

        case 3://bomb
            d85 = new bomb;
            d85->eliminate(b,b[row-1][col]);
            delete d85;
            break;

        case 5://star
            d85 = new star;
            d85->eliminate(b,b[row-1][col]);
            delete d85;
            break;
        }

        break;
        }

}

void bomb::eliminate(Blank *b[10][10], Blank *clicked, int mode)
{
    int row = clicked->row;
    int col = clicked->column;

    clicked->number=0;

    if(row>0 && col>0)  //left up
    {
        move_success *d;
        switch(b[row-1][col-1]->number/10)
        {
        case 0: //normal
            b[row-1][col-1]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row-1][col-1],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row-1][col-1],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row-1][col-1]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row-1][col-1]);
            delete d;
            break;
        }
    }
    if(row>0)           //up
    {
        move_success *d;
        switch(b[row-1][col]->number/10)
        {
        case 0: //normal
            b[row-1][col]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row-1][col],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row-1][col],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row-1][col]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row-1][col]);
            delete d;
            break;
        }
    }
    if(col>0)           //left
    {
        move_success *d;
        switch(b[row][col-1]->number/10)
        {
        case 0: //normal
            b[row][col-1]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row][col-1],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row][col-1],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row][col-1]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row][col-1]);
            delete d;
            break;
        }
    }
    if(row<9 && col<9)  //right down
    {
        move_success *d;
        switch(b[row+1][col+1]->number/10)
        {
        case 0: //normal
            b[row+1][col+1]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row+1][col+1],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row+1][col+1],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row+1][col+1]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row+1][col+1]);
            delete d;
            break;
        }
    }
    if(row<9)           //down
    {
        move_success *d;
        switch(b[row+1][col]->number/10)
        {
        case 0: //normal
            b[row+1][col]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row+1][col],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row+1][col],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row+1][col]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row+1][col]);
            delete d;
            break;
        }
    }
    if(col<9)           //right
    {
        move_success *d;
        switch(b[row][col+1]->number/10)
        {
        case 0: //normal
            b[row][col+1]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row][col+1],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row][col+1],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row][col+1]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row][col+1]);
            delete d;
            break;
        }
    }
    if(row<9 && col>0)  //left down
    {
        move_success *d;
        switch(b[row+1][col-1]->number/10)
        {
        case 0: //normal
            b[row+1][col-1]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row+1][col-1],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row+1][col-1],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row+1][col-1]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row+1][col-1]);
            delete d;
            break;
        }
    }
    if(row>0 && col<9)  //right up
    {
        move_success *d;
        switch(b[row-1][col+1]->number/10)
        {
        case 0: //normal
            b[row-1][col+1]->number=0;
            scoreSum+=2;
            break;
        case 1: //vertical
            d = new four;
            d->eliminate(b,b[row-1][col+1],1);   //mode=1
            delete d;
            break;
        case 2: //horizontal
            d = new four;
            d->eliminate(b,b[row-1][col+1],2);    //mode=2
            delete d;
            break;
        case 3: //bomb
            d = new bomb;
            d->eliminate(b,b[row-1][col+1]);
            delete d;
            break;
        case 5: //star
            d = new star;
            d->eliminate(b,b[row-1][col+1]);
            delete d;
            break;
        }
    }
}

int bomb::whichType(Blank *b[10][10], Blank *clicked)
{
    int row = clicked->row;
    int col = clicked->column;
    int num = clicked->number;

    num = num % 10 ;
    if( num!=0 )
    {
        if(col>=2 && (b[row][col-1]->number%10==num) && (b[row][col-2]->number%10==num) )  //left
        {
            if(row<=7 && (b[row+1][col]->number%10==num) && (b[row+2][col]->number%10==num) ) //down
                return 1;

            else if(row>=2 && (b[row-1][col]->number%10==num) && (b[row-2][col]->number%10==num) ) //up
                return 2;
        }

        if(col<=7 && (b[row][col+1]->number%10==num) && (b[row][col+2]->number%10==num) )  //right
        {
            if(row<=7 && (b[row+1][col]->number%10==num) && (b[row+2][col]->number%10==num) )  //down
                return 3;
            else if(row>=2 && (b[row-1][col]->number%10==num) && (b[row-2][col]->number%10==num) ) //up
                return 4;
        }

        if( col>=1 && col<=8 && (b[row][col-1]->number%10==num) && (b[row][col+1]->number%10==num) )  // 1 left 1 right
        {
            if(row<=7 && (b[row+1][col]->number%10==num) && (b[row+2][col]->number%10==num) ) //down
                return 5;
            else if(row>=2 && (b[row-1][col]->number%10==num) && (b[row-2][col]->number%10==num) ) //up
                return 6;
        }

        if( row>=1 && row<=8 && (b[row-1][col]->number%10==num) && (b[row+1][col]->number%10==num))   // 1 up 1 down
        {
            if(col>=2 && (b[row][col-1]->number%10==num) && (b[row][col-2]->number%10==num) ) //left
                return 7;
            else if(col<=7 && (b[row][col+1]->number%10==num) && (b[row][col+2]->number%10==num) ) //right
                return 8;
        }
    }
    return 0;
}

bomb::~bomb()
{

}
