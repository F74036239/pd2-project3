#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),Result_star(0)
{
    ui->setupUi(this);

    resWindow=new result;

    isclicked=false;

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            b[i][j]=new Blank(i,j,this);
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));   //點按鈕觸發動作
            connect(b[i][j],SIGNAL(moveDone()),this,SLOT(zeroDisappear()));
        }
    srand((unsigned)time(NULL));
    timer = new QTimer();
    gameStart();

    ui->score->setText("0");

    connect(this->timer,SIGNAL(timeout()),this,SLOT(lefttime()));
    timer->start(1000);  // 1s
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(gameExit()));

}

void MainWindow::button_clicked(int R, int C)
{
    if(!isclicked)  //還沒點
    {
        setClickPicture(b[R][C]);
        isclicked=true;
        record_R=R;
        record_C=C;
    }
    else
    {
        if(record_R==R && C-1==record_C) //right
        {
            *b[record_R][record_C]-b[R][C];
             judge2Special(record_R,record_C,R,C);
             if(!judge(record_R,record_C,R,C))
             {
                *b[R][C]-b[record_R][record_C];
             }
        }
        else if(record_R==R && C+1==record_C) //left
        {
            *b[R][C]-b[record_R][record_C];
            judge2Special(record_R,record_C,R,C);
            if(!judge(record_R,record_C,R,C))
            {
                *b[record_R][record_C]-b[R][C];
            }
        }
        else if(R-1==record_R && C==record_C) //down
        {
            *b[record_R][record_C]|b[R][C];
            judge2Special(record_R,record_C,R,C);
            if(!judge(record_R,record_C,R,C))
            {
                *b[R][C]|b[record_R][record_C];
            }
        }
        else if(R+1==record_R && C==record_C) //up
        {
            *b[R][C]|b[record_R][record_C];
            judge2Special(record_R,record_C,R,C);
            if(!judge(record_R,record_C,R,C))
            {
                *b[record_R][record_C]|b[R][C];
            }
        }
        else
        {
            setClickPicture(b[record_R][record_C]);
        }
        isclicked=false;
    }

}

bool MainWindow::judge(int row1, int col1, int row2, int col2)
{
    judgeTime();
    if(judgeStar(row2,col2) || judgeBomb(row1,col1) || judgeBomb(row2,col2) || judgeFour(row2,col2) || judgeThree(row1,col1) || judgeThree(row2,col2) )
        return true;
    else
        return false;
}

bool MainWindow::judge2Special(int row1, int col1, int row2 ,int col2)
{ 
    bool form=false;
    if(b[row1][col1]->number/10!=0 && b[row2][col2]->number/10!=0)
    {
        int type1 = b[row1][col1]->number/10;
        int type2 = b[row2][col2]->number/10;
        move_success *d;
        int n=rand()%2+1;   // 1 or 2  v or h
        int color_num = b[row1][col1]->number%10;
        switch(type1)
        {
        case 1://vertical
        {
            move_success *d1;
            switch(type2)
            {
            case 1: //vertical
                d = new four;
                d->eliminate(b,b[row2][col2],1);

                cout<<d->scoreSum<<endl;

                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 2://h
                d = new four;
                d->eliminate(b,b[row1][col1],1);

                d1 = new four;
                d1->eliminate(b,b[row2][col2],2);

                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 3://b
                d = new four;
                d->eliminate(b,b[row1][col1],1);

                d1 = new bomb;
                d1->eliminate(b,b[row2][col2]);

                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 5://s
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                        if(b[i][j]->number==color_num)
                            b[i][j]->number+=(10*n);
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                       if(b[i][j]->number%10==color_num && (b[i][j]->number/10==1 || b[i][j]->number/10==2))
                       {
                           if(b[i][j]->number/10==1)
                           {
                               d= new four;
                               d->eliminate(b,b[i][j],1);

                           }
                           if(b[i][j]->number/10==2)
                           {
                               d1 = new four;
                               d1->eliminate(b,b[i][j],2);

                           }
                       }
                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;
            }
            delete d1;
            break;
        }
        case 2://h
        {
            move_success *d2;
            switch(type2)
            {
            case 1://v
                d = new four;
                d->eliminate(b,b[row1][col1],2);


                d2 = new four;
                d2->eliminate(b,b[row2][col2],1);


                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 2: //horizontal
                d = new four;
                d->eliminate(b,b[row1][col1],2);

                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 3://b
                d = new four;
                d->eliminate(b,b[row1][col1],2);


                d2 = new bomb;
                d2->eliminate(b,b[row2][col2]);


                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 5://s
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                        if(b[i][j]->number%10==color_num)
                        {
                            b[i][j]->number+=(10*n);
                            newPicture();
                        }
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                       if(b[i][j]->number%10==color_num && (b[i][j]->number/10==1 || b[i][j]->number/10==2))
                       {
                           if(b[i][j]->number/10==1)
                           {
                               d= new four;
                               d->eliminate(b,b[i][j],1);

                           }
                           if(b[i][j]->number/10==2)
                           {
                               d2 = new four;
                               d2->eliminate(b,b[i][j],2);

                           }
                       }

                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;
            }
            delete d2;
            break;
        }
        case 3://b
        {
            move_success *d3;
            switch(type2)
            {
            case 1://v
                d = new bomb;
                d->eliminate(b,b[row1][col1]);


                d3 = new four;
                d3->eliminate(b,b[row2][col2],1);


                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 2://h
                d = new bomb;
                d->eliminate(b,b[row1][col1]);


                d3 = new four;
                d3->eliminate(b,b[row2][col2],2);


                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 3: //bomb
                d = new bomb;
                d->eliminate(b,b[row1][col1]);


                d3 = new bomb;
                d3->eliminate(b,b[row2][col2]);


                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 5:
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                    {
                        if(color_num>1)
                        {
                            int color_num2=color_num-1;
                            if(b[i][j]->number%10==color_num || b[i][j]->number%10==color_num2 )
                            {
                                b[i][j]->number=0;
                            }
                        }
                        if(color_num==1)
                        {
                            int color_num2=color_num+3;
                            if(b[i][j]->number%10==color_num || b[i][j]->number%10==color_num2 )
                            {
                                b[i][j]->number=0;
                            }
                        }
                    }

                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;
            }
            delete d3;
            break;
        }
        case 5://s
        {
            move_success *d5;
            color_num = b[row2][col2]->number%10;
            switch(type2)
            {
            case 1://v
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                        if(b[i][j]->number==color_num)
                            b[i][j]->number+=(10*n);
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                       if(b[i][j]->number%10==color_num && (b[i][j]->number/10==1 || b[i][j]->number/10==2))
                       {
                           if(b[i][j]->number/10==1)
                           {
                               d= new four;
                               d->eliminate(b,b[i][j],1);

                           }
                           if(b[i][j]->number/10==2)
                           {
                               d5 = new four;
                               d5->eliminate(b,b[i][j],2);

                           }
                       }
                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 2://h
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                        if(b[i][j]->number%10==color_num)
                            b[i][j]->number+=(10*n);
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                       if(b[i][j]->number%10==color_num && (b[i][j]->number/10==1 || b[i][j]->number/10==2))
                       {
                           if(b[i][j]->number/10==1)
                           {
                               d= new four;
                               d->eliminate(b,b[i][j],1);

                           }
                           if(b[i][j]->number/10==2)
                           {
                               d5 = new four;
                               d5->eliminate(b,b[i][j],2);

                           }
                       }
                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 3://b
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                    {
                        if(color_num>1)
                        {
                            int color_num2=color_num-1;
                            if(b[i][j]->number%10==color_num || b[i][j]->number%10==color_num2 )
                            {
                                b[i][j]->number=0;
                            }
                        }
                        if(color_num==1)
                        {
                            int color_num2=color_num+3;
                            if(b[i][j]->number%10==color_num || b[i][j]->number%10==color_num2 )
                            {
                                b[i][j]->number=0;
                            }
                        }
                    }
                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;

            case 5: //star
                for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                    {
                        b[i][j]->number=0;

                    }
                b[row1][col1]->number=0;
                b[row2][col2]->number=0;
                zeroDisappear();
                break;
            }
            delete d5;
            break;
        }
        }
        delete d;
        form=true;
    }
    if( (b[row1][col1]->number/10==0 && b[row2][col2]->number==55) || (b[row2][col2]->number/10==0 && b[row1][col1]->number==55) )
    {
        int color1 = b[row1][col1]->number%10;
        int color2 = b[row2][col2]->number%10;
        if(color1==5)
        {
            for(int i=0;i<10;i++)
                for(int j=0;j<10;j++)
                    if(b[i][j]->number%10==color2)
                        b[i][j]->number=0;
        }
        else
        {
            for(int i=0;i<10;i++)
                for(int j=0;j<10;j++)
                    if(b[i][j]->number%10==color1)
                        b[i][j]->number=0;
        }
        b[row1][col1]->number=0;
        b[row2][col2]->number=0;
        zeroDisappear();

        form=true;
    }

    return form;
}

bool MainWindow::judgeStar(int row , int col)
{
    int return_value;
    bool Any_form=false;    //看有沒有生成
    move_success *d = new star;     //執行多型
    return_value = d->whichType(b,b[row][col]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1: //vertical star
            d->generate(b,b[row][col],1);
            Any_form=true;
            ui->score->setText(QString::number(500  +ui->score->text().toInt()));
            break;
        case 2: //horizontal star
            d->generate(b,b[row][col],2);
            Any_form=true;
            ui->score->setText(QString::number(500  +ui->score->text().toInt()));
            break;
        }
    }
    delete d;
    return Any_form;
}

bool MainWindow::judgeBomb(int row , int col)
{
    int return_value;
    bool Any_form=false;    //看有沒有生成
    move_success *d = new bomb;     //執行多型
    return_value = d->whichType(b,b[row][col]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            d->generate(b,b[row][col],1);
            Any_form=true;
            ui->score->setText(QString::number(400  + ui->score->text().toInt()));
            break;
        case 2:
            d->generate(b,b[row][col],2);
            Any_form=true;
            ui->score->setText(QString::number(400  +ui->score->text().toInt()));
            break;
        case 3:
            d->generate(b,b[row][col],3);
            Any_form=true;
            ui->score->setText(QString::number(400  +ui->score->text().toInt()));
            break;
        case 4:
            d->generate(b,b[row][col],4);
            Any_form=true;
            ui->score->setText(QString::number(400  +ui->score->text().toInt()));
            break;
        case 5:
            d->generate(b,b[row][col],5);
            Any_form=true;
            ui->score->setText(QString::number(400  +ui->score->text().toInt()));
            break;
        case 6:
            d->generate(b,b[row][col],6);
            Any_form=true;
            ui->score->setText(QString::number(400  +ui->score->text().toInt()));
            break;
        case 7:
            d->generate(b,b[row][col],7);
            Any_form=true;
            ui->score->setText(QString::number(400  +ui->score->text().toInt()));
            break;
        case 8:
            d->generate(b,b[row][col],8);
            Any_form=true;
            ui->score->setText(QString::number(400  +ui->score->text().toInt()));
            break;
        }
    }
    delete d;
    return Any_form;
}

bool MainWindow::judgeFour(int row , int col)
{
    int return_value;
    bool Any_form=false;    //看有沒有生成
    move_success *d = new four;     //執行多型
    return_value = d->whichType(b,b[row][col]);

    if(return_value)
    {
        switch(return_value)
        {
        case 1: //vertical
            d->generate(b,b[row][col],1);
            Any_form=true;
            ui->score->setText(QString::number(300  +ui->score->text().toInt()));
            break;
        case 2: //vertical
            d->generate(b,b[row][col],2);
            Any_form=true;
            ui->score->setText(QString::number(300  +ui->score->text().toInt()));
            break;
        case 3: //horizontal
            d->generate(b,b[row][col],3);
            Any_form=true;
            ui->score->setText(QString::number(300  +ui->score->text().toInt()));
            break;
        case 4: //horizontal
            d->generate(b,b[row][col],4);
            Any_form=true;
            ui->score->setText(QString::number(300  +ui->score->text().toInt()));
            break;
        }
    }
    delete d;
    return Any_form;
}

bool MainWindow::judgeThree(int row, int col)
{
    int return_value;
    bool Any_form=false;    //看有沒有生成
    move_success *d = new three;     //執行多型
    return_value = d->whichType(b,b[row][col]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1: //vertical
            d->generate(b,b[row][col],1);
            Any_form=true;
            ui->score->setText(QString::number(200  +ui->score->text().toInt()));
            break;
        case 2: //vertical
            d->generate(b,b[row][col],2);
            Any_form=true;
            ui->score->setText(QString::number(200 +ui->score->text().toInt()));
            break;
        case 3: //vertical
            d->generate(b,b[row][col],3);
            Any_form=true;
            ui->score->setText(QString::number(200 +ui->score->text().toInt()));
            break;
        case 4: //horizontal
            d->generate(b,b[row][col],4);
            Any_form=true;
            ui->score->setText(QString::number(200 +ui->score->text().toInt()));
            break;
        case 5: //horizontal
            d->generate(b,b[row][col],5);
            Any_form=true;
            ui->score->setText(QString::number(200 +ui->score->text().toInt()));
            break;
        case 6: //horizontal
            d->generate(b,b[row][col],6);
            Any_form=true;
            ui->score->setText(QString::number(200 +ui->score->text().toInt()));
            break;
        }
    }
    delete d;
    return Any_form;
}

void MainWindow::zeroDisappear()
{
    while(true)
    {
        bool no_conti=false;
        fillzero();
        no_conti=!conti_judge();
        if(no_conti)
            break;
    }
    newPicture();
}

void MainWindow::newPicture()   //更新圖案
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            b[i][j]->setButtonPicture();
}

void MainWindow::fillzero()
{
    for(int col=0;col<10;col++)  //column
        for(int row=9;row>=0;row--)
            if(b[row][col]->number ==0)
            {
                for(int i=row-1;i>=0;i--)
                    if(b[i][col]->number!=0)
                    {
                        b[row][col]->number = b[i][col]->number;
                        b[i][col]->number = 0;
                        break;
                    }
            }

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(b[i][j]->number==0)
            {
                b[i][j]->setNumber();
            }
    newPicture();
}

void MainWindow::lefttime()
{
    ui->timeleft->setText(QString::number(ui->timeleft->text().toInt()-1));
}

void MainWindow::gameExit()
{
    int score = ui->score->text().toInt();
    QString str = ui->score->text();
    emit quit(Result_star,score);
    resWindow->setWord("Quit the game");
    resWindow->setScore(str);
    resWindow->setStar(score,Result_star);
    resWindow->show();
    this->close();
}

bool MainWindow::conti_judge()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            if( judgeStar(i,j) || judgeBomb(i,j) || judgeFour(i,j) || judgeThree(i,j) )
                return true;  //有消掉東西
        }
    return false;
}

void MainWindow::setClickPicture(Blank *b)
{
    if(!isclicked)   //沒點過 就變成有點擊的樣子
    {
        switch(b->number)
        {
        //一般的 1:紅色 2:藍色 3:黃色 4:綠色
        case 1:
            b->button->setIcon(QIcon(QPixmap(":/pic/click1.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 2:
            b->button->setIcon(QIcon(QPixmap(":/pic/click2.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 3:
            b->button->setIcon(QIcon(QPixmap(":/pic/click3.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 4:
            b->button->setIcon(QIcon(QPixmap(":/pic/click4.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //星星
        case 55:
            b->button->setIcon(QIcon(QPixmap(":/pic/click5.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //垂直
        case 11:
            b->button->setIcon(QIcon(QPixmap(":/pic/click11.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 12:
            b->button->setIcon(QIcon(QPixmap(":/pic/click12.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 13:
            b->button->setIcon(QIcon(QPixmap(":/pic/click13.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 14:
            b->button->setIcon(QIcon(QPixmap(":/pic/click14.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //水平
        case 21:
            b->button->setIcon(QIcon(QPixmap(":/pic/click21.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 22:
            b->button->setIcon(QIcon(QPixmap(":/pic/click22.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 23:
            b->button->setIcon(QIcon(QPixmap(":/pic/click23.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 24:
            b->button->setIcon(QIcon(QPixmap(":/pic/click24.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //炸彈
        case 31:
            b->button->setIcon(QIcon(QPixmap(":/pic/click31.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 32:
            b->button->setIcon(QIcon(QPixmap(":/pic/click32.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 33:
            b->button->setIcon(QIcon(QPixmap(":/pic/click33.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 34:
            b->button->setIcon(QIcon(QPixmap(":/pic/click34.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        }
    }
    else             //點過了再點一次變成沒點過的樣子
    {
        b->setButtonPicture();
    }
}

void MainWindow::gameStart()
{
    //產生圖片
    for(int i=0;i<10;i++)   //row
        for(int j=0;j<10;j++)   //column
        {
            b[i][j]->setNumber();
            b[i][j]->setButtonPicture();
            if( j>=2 && b[i][j]->number == b[i][j-2]->number && b[i][j]->number==b[i][j-1]->number)
                j--;
            if(i>=2 && b[i][j]->number == b[i-2][j]->number && b[i][j]->number==b[i-1][j]->number)
                j--;
        }
}

void MainWindow::judgeTime()
{
    QString str_time = ui->timeleft->text();
    QString str_score = ui->score->text();
    if(str_time.toInt()<=0)
    {
        if(str_score.toInt()>=25000)
            gameover("WIN!");
        else
            gameover("FAIL!Time is out.");
    }
}

void MainWindow::gameover(QString S)
{
    int score = ui->score->text().toInt();
    QString str = ui->score->text();

    if(score>=100000)
        Result_star=3;
    else if(score>=50000)
        Result_star=2;
    else if(score>=25000)
        Result_star=1;

    emit quit(Result_star,score);
    resWindow->setWord(S);
    resWindow->setScore(str);
    resWindow->setStar(score,Result_star);
    resWindow->show();
    this->close();

}

MainWindow::~MainWindow()
{
    emit quit(Result_star,ui->score->text().toInt());
    delete ui;

}

