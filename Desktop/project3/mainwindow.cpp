#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isclicked=false;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            b[i][j]=new Blank(i,j,this);
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));   //點按鈕觸發動作
            connect(b[i][j],SIGNAL(moveDone()),this,SLOT(zeroDisappear()));
        }
    srand((unsigned)time(NULL));
    gamestart();
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
        if(record_R==R && C-1==record_C) //點左邊
        {
            *b[record_R][record_C]-b[R][C];
            if(!judge(record_R,record_C,R,C)){}
        }
        else if(record_R==R && C+1==record_C) //右邊
        {
            *b[R][C]-b[record_R][record_C];
            if(!judge(record_R,record_C,R,C)){}
        }
        else if(R-1==record_R && C==record_C) //上面
        {
            *b[record_R][record_C]|b[R][C];
            if(!judge(record_R,record_C,R,C)){}
        }
        else if(R+1==record_R && C==record_C) //下面
        {
            *b[R][C]|b[record_R][record_C];
            if(!judge(record_R,record_C,R,C)){}
        }
        else
        {
            setClickPicture(b[record_R][record_C]);
        }
        isclicked=false;
    }

}

void MainWindow::zeroDisappear()
{
    newPicture();
}

bool MainWindow::judge(int row1, int col1, int row2, int col2)
{
    judgeDoubleStar(row1,col1);
    judgeDoubleStar(row2,col2);

    judgeStaradd(row1,col1);
    judgeStaradd(row2,col2);

    judgeStar(row1,col1);
    judgeStar(row2,col2);

    judgeBomb(row1,col1);
    judgeBomb(row2,col2);

    judge4V(row1,col1);
    judge4V(row2,col2);

    judge4H(row1,col1);
    judge4H(row2,col2);

    judge3V(row1,col1);
    judge3V(row2,col2);

    judge3H(row1,col1);
    judge3H(row2,col2);

}


bool MainWindow::judgeStar(int row , int col)
{
    int return_value;
    bool Any_form=false;    //看有沒有生成
    delete_blank *d = new star;     //執行多型
    return_value = d->condition(b,b[row][col]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1: //vertical star
            d->produce(b,b[row][col],1);
            Any_form=true;
            break;
        case 2: //horizontal star
            d->produce(b,b[row][col],2);
            Any_form=true;
            break;
        case 3: //special vertical star
            d->produce(b,b[row][col],3);
            Any_form=true;
            break;
        case 4: //special horizontal star
            d->produce(b,b[row][col],4);
            Any_form=true;
            break;
        }
    }
    delete d;
    return Any_form;
}

bool MainWindow::judgeDoubleStar(int row, int col)
{

}

bool MainWindow::judgeStaradd(int row, int col)
{

}

bool MainWindow::judgeBomb(int row, int col)
{

}

bool MainWindow::judge4H(int row, int col)  //horizontal 0000
{
    int return_value;
    bool Any_form=false;    //看有沒有生成
    delete_blank *d = new horizontal;     //執行多型
    return_value = d->condition(b,b[row][col]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1: //vertical
            d->produce(b,b[row][col],1);
            Any_form=true;
            break;
        case 2: //horizontal
            d->produce(b,b[row][col],2);
            Any_form=true;
            break;
        case 3: //special vertical
            d->produce(b,b[row][col],3);
            Any_form=true;
            break;
        case 4: //special horizontal
            d->produce(b,b[row][col],4);
            Any_form=true;
            break;
        }
    }
    delete d;
    return Any_form;
}

bool MainWindow::judge4V(int row, int col)  //vertical
{

}

bool MainWindow::judge3H(int row, int col)   //horizontal 000
{

}

bool MainWindow::judge3V(int row, int col)   //vertical
{

}

void MainWindow::newPicture()   //更新圖案
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            b[i][j]->setButtonPicture();
}

void MainWindow::setClickPicture(Blank *b)
{
    if(!isclicked)   //沒點過 就變成有點擊的樣子
    {
        switch(b->number)
        {
        //一般的 1:紅色 2:藍色 3:黃色 4:綠色
        case 1:
            b->button->setIcon(QIcon(QPixmap(":/click1.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 2:
            b->button->setIcon(QIcon(QPixmap(":/click2.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 3:
            b->button->setIcon(QIcon(QPixmap(":/click3.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 4:
            b->button->setIcon(QIcon(QPixmap(":/click4.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //星星
        case 5:
            b->button->setIcon(QIcon(QPixmap(":/click5.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //垂直
        case 11:
            b->button->setIcon(QIcon(QPixmap(":/click11.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 12:
            b->button->setIcon(QIcon(QPixmap(":/click12.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 13:
            b->button->setIcon(QIcon(QPixmap(":/click13.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 14:
            b->button->setIcon(QIcon(QPixmap(":/click14.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //水平
        case 21:
            b->button->setIcon(QIcon(QPixmap(":/click21.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 22:
            b->button->setIcon(QIcon(QPixmap(":/click22.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 23:
            b->button->setIcon(QIcon(QPixmap(":/click23.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 24:
            b->button->setIcon(QIcon(QPixmap(":/click24.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        //炸彈
        case 31:
            b->button->setIcon(QIcon(QPixmap(":/click31.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 32:
            b->button->setIcon(QIcon(QPixmap(":/click32.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 33:
            b->button->setIcon(QIcon(QPixmap(":/click33.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        case 34:
            b->button->setIcon(QIcon(QPixmap(":/click34.png")));
            b->button->setIconSize(QSize(40,40));
            break;
        }
    }
    else             //點過了再點一次變成沒點過的樣子
    {
        b->setButtonPicture();
    }
}

void MainWindow::gamestart()
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
MainWindow::~MainWindow()
{
    delete ui;
}
