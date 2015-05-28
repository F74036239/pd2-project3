#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent,result *res) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    mainwindow=parent;
    reswindow=res;
    //don't want to play
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(gameclick()));

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            square[i][j]=0;

    ui->score->setText("0");

    ui->label->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_2->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_3->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_4->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_5->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_6->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_7->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_8->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_9->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_10->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_11->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_12->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_13->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_14->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_15->setPixmap(QPixmap(":/pic/0.png"));
    ui->label_16->setPixmap(QPixmap(":/pic/0.png"));

    srand((unsigned)time(NULL));
    int x1=rand()%4;
    int y1=rand()%4;
    int x2=rand()%4;
    int y2=rand()%4;

    square[x1][y1]=2;
    square[x2][y2]=2;
    switch(x1*4+y1)
    {
    case 0:ui->label->setPixmap(QPixmap(":/pic/2.png"));break;
    case 1:ui->label_2->setPixmap(QPixmap(":/pic/2.png"));break;
    case 2:ui->label_3->setPixmap(QPixmap(":/pic/2.png"));break;
    case 3:ui->label_4->setPixmap(QPixmap(":/pic/2.png"));break;
    case 4:ui->label_5->setPixmap(QPixmap(":/pic/2.png"));break;
    case 5:ui->label_6->setPixmap(QPixmap(":/pic/2.png"));break;
    case 6:ui->label_7->setPixmap(QPixmap(":/pic/2.png"));break;
    case 7:ui->label_8->setPixmap(QPixmap(":/pic/2.png"));break;
    case 8:ui->label_9->setPixmap(QPixmap(":/pic/2.png"));break;
    case 9:ui->label_10->setPixmap(QPixmap(":/pic/2.png"));break;
    case 10:ui->label_11->setPixmap(QPixmap(":/pic/2.png"));break;
    case 11:ui->label_12->setPixmap(QPixmap(":/pic/2.png"));break;
    case 12:ui->label_13->setPixmap(QPixmap(":/pic/2.png"));break;
    case 13:ui->label_14->setPixmap(QPixmap(":/pic/2.png"));break;
    case 14:ui->label_15->setPixmap(QPixmap(":/pic/2.png"));break;
    case 15:ui->label_16->setPixmap(QPixmap(":/pic/2.png"));break;
    }
    switch(x2*4+y2)
    {
    case 0:ui->label->setPixmap(QPixmap(":/pic/2.png"));break;
    case 1:ui->label_2->setPixmap(QPixmap(":/pic/2.png"));break;
    case 2:ui->label_3->setPixmap(QPixmap(":/pic/2.png"));break;
    case 3:ui->label_4->setPixmap(QPixmap(":/pic/2.png"));break;
    case 4:ui->label_5->setPixmap(QPixmap(":/pic/2.png"));break;
    case 5:ui->label_6->setPixmap(QPixmap(":/pic/2.png"));break;
    case 6:ui->label_7->setPixmap(QPixmap(":/pic/2.png"));break;
    case 7:ui->label_8->setPixmap(QPixmap(":/pic/2.png"));break;
    case 8:ui->label_9->setPixmap(QPixmap(":/pic/2.png"));break;
    case 9:ui->label_10->setPixmap(QPixmap(":/pic/2.png"));break;
    case 10:ui->label_11->setPixmap(QPixmap(":/pic/2.png"));break;
    case 11:ui->label_12->setPixmap(QPixmap(":/pic/2.png"));break;
    case 12:ui->label_13->setPixmap(QPixmap(":/pic/2.png"));break;
    case 13:ui->label_14->setPixmap(QPixmap(":/pic/2.png"));break;
    case 14:ui->label_15->setPixmap(QPixmap(":/pic/2.png"));break;
    case 15:ui->label_16->setPixmap(QPixmap(":/pic/2.png"));break;}

}

game::~game()
{
    delete ui;
}

//don't want to play
void game::gameclick()
{
    QString str=ui->score->text();
    reswindow->setScore(str);
    reswindow->setWin('Q');
    reswindow->show();

}

void game::gameover()
{
    bool over=true;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)  //有空格   左右相同  上下相同
            if( (square[i][j]==0) || (i>0&&square[i][j]==square[i-1][j]) || (i<3&&square[i][j]==square[i+1][j]) || (j>0&&square[i][j]==square[i][j-1]) || (j<3&&square[i][j]==square[i][j+1]))
            {
                   over=false;
                   break;
            }
    for(int i=0;i<4;i++)     //贏了
        for(int j=0;j<4;j++)
            if(square[i][j]==2048)
            {
                QString str=ui->score->text();
                reswindow->setScore(str);
                reswindow->setWin('W');
                reswindow->show();
            }
    if(over)    //如果都沒有 -> 結束
    {
        QString str=ui->score->text();
        reswindow->setScore(str);
        reswindow->setWin('L');
        reswindow->show();
    }
}

void game::picture(int i,int j)
{
    switch(square[i][j])    //那個位置的數字
    {
    case 0:
        switch(i*4+j)       //看哪個位置要放
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/0.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/0.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/0.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/0.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/0.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/0.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/0.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/0.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/0.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/0.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/0.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/0.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/0.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/0.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/0.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/0.png"));break;
        }break;
    case 2:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/2.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/2.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/2.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/2.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/2.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/2.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/2.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/2.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/2.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/2.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/2.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/2.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/2.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/2.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/2.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/2.png"));break;
        }break;
    case 4:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/4.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/4.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/4.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/4.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/4.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/4.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/4.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/4.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/4.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/4.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/4.png"));break;
        }break;
    case 8:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/8.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/8.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/8.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/8.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/8.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/8.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/8.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/8.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/8.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/8.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/8.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/8.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/qu.png"));break;
        }break;
    case 16:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/16.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/16.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/16.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/16.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/16.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/16.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/16.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/16.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/16.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/16.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/16.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/16.png"));break;
        }break;
    case 32:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/32.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/32.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/32.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/32.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/32.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/32.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/32.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/32.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/32.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/32.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/32.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/32.png"));break;
        }break;
    case 64:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/64.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/64.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/64.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/64.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/64.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/64.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/64.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/64.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/64.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/64.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/64.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/64.png"));break;
        }break;
    case 128:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/128.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/128.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/128.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/128.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/128.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/128.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/128.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/128.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/128.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/128.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/128.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/128.png"));break;
        }break;
    case 256:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/256.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/256.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/256.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/256.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/256.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/256.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/256.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/256.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/256.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/256.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/256.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/256.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/256.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/256.png"));break;
        }break;
    case 512:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/512.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/512.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/512.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/512.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/512.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/512.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/512.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/512.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/512.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/512.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/512.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/512.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/512.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/512.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/512.png"));break;
        }break;
    case 1024:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/qu.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/1024.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/1024.png"));break;
        }break;
    case 2048:
        switch(i*4+j)
        {
        case 0:ui->label->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 1:ui->label_2->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 2:ui->label_3->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 3:ui->label_4->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 4:ui->label_5->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 5:ui->label_6->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 6:ui->label_7->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 7:ui->label_8->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 8:ui->label_9->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 9:ui->label_10->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 10:ui->label_11->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 11:ui->label_12->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 12:ui->label_13->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 13:ui->label_14->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 14:ui->label_15->setPixmap(QPixmap(":/pic/2048.png"));break;
        case 15:ui->label_16->setPixmap(QPixmap(":/pic/2048.png"));break;
        }break;
    }

}

void game::addNum()
{
    int add[16];
    int k=0;
    for(int i=0;i<16;i++)
        add[i]=16;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(square[i][j]==0)
            {
                add[k]=i*4+j;   //存下空格
                k++;            //計算有幾個
            }
        }
    int num = (rand()%(k+1));
    int i=add[num]/4;
    int j=add[num]%4;
    if(rand()%10==4)
    {
        square[i][j]=4;
        picture(i,j);
    }
    else
    {
        square[i][j]=2;
        picture(i,j);
    }
}

void game::upmove()
{
    bool check=false;
    for(int y=0;y<4;y++)
        for(int x=0;x<4;x++)            //上面的
            for(int x1=x+1;x1<4;x1++)   //下面的
            {
                if(square[x1][y]>0)    //下面的有數字->要動
                {
                    if(square[x][y]==0)  //上面是空格
                    {
                        square[x][y]=square[x1][y]; //數字往上跑
                        picture(x,y);
                        square[x1][y]=0;
                        picture(x1,y);
                        x--;
                        check=true;
                        break;
                    }
                    if(square[x1][y]==square[x][y])   //數字一樣
                    {
                        square[x][y]=square[x][y]*2;
                        picture(x,y);
                        square[x1][y]=0;
                        picture(x1,y);
                        ui->score->setText(QString::number(square[x][y]+ui->score->text().toInt()));
                        check=true;
                        break;
                    }
                    else{break;}
                }
            }
    if(check)
        addNum();
    gameover();
}

void game::downmove()
{
    bool check=false;
    for(int y=0;y<4;y++)
        for(int x=3;x>=0;x--)            //下面的
            for(int x1=x-1;x1>=0;x1--)   //上面的
            {
                if(square[x1][y]>0)    //上面的有數字->要動
                {
                    if(square[x][y]==0)  //下面是空格
                    {
                        square[x][y]=square[x1][y]; //數字往下跑
                        picture(x,y);
                        square[x1][y]=0;
                        picture(x1,y);
                        x++;
                        check=true;
                        break;
                    }
                    if(square[x1][y]==square[x][y])   //數字一樣
                    {
                        square[x][y]=square[x][y]*2;
                        picture(x,y);
                        square[x1][y]=0;
                        picture(x1,y);
                        ui->score->setText(QString::number(square[x][y]+ui->score->text().toInt()));
                        check=true;
                        break;
                    }
                    else{break;}
                }
            }
    if(check)
        addNum();
    gameover();
}

void game::leftmove()
{
    bool check=false;
    for(int x=0;x<4;x++)
        for(int y=0;y<4;y++)            //左邊的
            for(int y1=y+1;y1<4;y1++)    //右邊的
            {
                if(square[x][y1]>0)    //右邊有數字->要動
                {
                    if(square[x][y]==0)  //左邊是空格
                    {
                        square[x][y]=square[x][y1]; //數字往左跑
                        picture(x,y);
                        square[x][y1]=0;
                        picture(x,y1);
                        y--;
                        check=true;
                        break;
                    }
                    if(square[x][y1]==square[x][y])   //數字一樣
                    {
                        square[x][y]=square[x][y]*2;
                        picture(x,y);
                        square[x][y1]=0;
                        picture(x,y1);
                        ui->score ->setText(QString::number(square[x][y]+ui->score->text().toInt()));
                        check=true;
                        break;
                    }
                    else{break;}
                }
            }
    if(check)
        addNum();
    gameover();
}

void game::rightmove()
{
    bool check=false;
    for(int x=0;x<4;x++)
        for(int y=3;y>=0;y--)            //右邊的
            for(int y1=y-1;y1>=0;y1--)    //左邊的
            {
                if(square[x][y1]>0)    //左邊有數字->要動
                {
                    if(square[x][y]==0)  //右邊是空格
                    {
                        square[x][y]=square[x][y1]; //數字往右跑
                        picture(x,y);
                        square[x][y1]=0;
                        picture(x,y1);
                        y++;
                        check=true;
                        break;
                    }
                    if(square[x][y1]==square[x][y])   //數字一樣
                    {
                        square[x][y]=square[x][y]*2;
                        picture(x,y);
                        square[x][y1]=0;
                        picture(x,y1);
                        ui->score ->setText(QString::number(square[x][y]+ui->score->text().toInt()));
                        check=true;
                        break;
                    }
                    else{break;}
                }
            }
    if(check)
        addNum();
    gameover();
}

void game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) //<-
    {
        leftmove();
        event->accept();
    }
    if(event->key() == Qt::Key_Up)  // ^
    {
        upmove();
        event->accept();
    }
    if(event->key() == Qt::Key_Down) // v
    {
        downmove();
        event->accept();
    }
    if(event->key() == Qt::Key_Right) //->
    {
        rightmove();
        event->accept();
    }
}

