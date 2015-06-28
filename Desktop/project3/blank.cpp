#include "blank.h"

Blank::Blank(int R,int C,QWidget *parent):row(R),column(C),QObject(parent)
{
    button=new QPushButton(parent);  //連接
    button->setGeometry(column*50,row*50,50,50);  //設定位置
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
    shift=1;
    time=new QTimer();
}

void Blank::click()
{
   emit Click(row,column);
}


void Blank::moveright()
{
    button->setGeometry(column*50+shift*10,row*50,50,50);
    shift++;
    if(shift==5)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveright()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
        emit moveDone();
    }
}

void Blank::moveleft()
{
    button->setGeometry(column*50-shift*10,row*50,50,50);
    shift++;
    if(shift==5)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveleft()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
    }
}

void Blank::moveup()
{
    button->setGeometry(column*50,row*50-shift*10,50,50);
    shift++;
    if(shift==5)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveup()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
        emit moveDone();
    }
}

void Blank::movedown()
{
    button->setGeometry(column*50,row*50+shift*10,50,50);
    shift++;
    if(shift==5)
    {
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(movedown()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
    }
}

void Blank::operator -(Blank *b)
{
    int tmp_Num = b->number;
    b->number = number;
    number = tmp_Num;
    connect(time,SIGNAL(timeout()),this,SLOT(moveright()));  //左邊的右移
    connect(b->time,SIGNAL(timeout()),b,SLOT(moveleft()));   //右邊的左移
    time->start(50);
    b->time->start(50);
}

void Blank::operator |(Blank *b)
{
    int tmp_Num = b->number;
    b->number = number;
    number = tmp_Num;
    connect(time,SIGNAL(timeout()),this,SLOT(movedown()));  //上面的下移
    connect(b->time,SIGNAL(timeout()),b,SLOT(moveup()));   //下面的上移
    time->start(50);
    b->time->start(50);
}

void Blank::setNumber()  //設定最一般的圖片
{
    number=rand()%4+1;  // 1到4
}

void Blank::setButtonPicture()  //設定圖片
{
    switch(number)
    {
    //一般的 1:紅色 2:藍色 3:黃色 4:綠色
    case 1:
        button->setIcon(QIcon(QPixmap(":/1.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 2:
        button->setIcon(QIcon(QPixmap(":/2.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 3:
        button->setIcon(QIcon(QPixmap(":/3.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 4:
        button->setIcon(QIcon(QPixmap(":/4.png")));
        button->setIconSize(QSize(40,40));
        break;
    //星星
    case 5:
        button->setIcon(QIcon(QPixmap(":/5.png")));
        button->setIconSize(QSize(40,40));
        break;
    //垂直
    case 11:
        button->setIcon(QIcon(QPixmap(":/11.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 12:
        button->setIcon(QIcon(QPixmap(":/12.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 13:
        button->setIcon(QIcon(QPixmap(":/13.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 14:
        button->setIcon(QIcon(QPixmap(":/14.png")));
        button->setIconSize(QSize(40,40));
        break;
    //水平
    case 21:
        button->setIcon(QIcon(QPixmap(":/21.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 22:
        button->setIcon(QIcon(QPixmap(":/22.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 23:
        button->setIcon(QIcon(QPixmap(":/23.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 24:
        button->setIcon(QIcon(QPixmap(":/24.png")));
        button->setIconSize(QSize(40,40));
        break;
    //炸彈
    case 31:
        button->setIcon(QIcon(QPixmap(":/31.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 32:
        button->setIcon(QIcon(QPixmap(":/32.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 33:
        button->setIcon(QIcon(QPixmap(":/33.png")));
        button->setIconSize(QSize(40,40));
        break;
    case 34:
        button->setIcon(QIcon(QPixmap(":/34.png")));
        button->setIconSize(QSize(40,40));
        break;
    default:
        button->setIcon(QIcon(QPixmap("blank")));
    }
}

Blank::~Blank()
{

}

