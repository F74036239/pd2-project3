#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(pushbutton_2_clicked()));
}

result::~result()
{
    delete ui;
}

void result::setWord(QString S)
{
    ui->fail->setText(S);
}

void result::setStar(int sc,int R)
{
    if(R==3)
    {
        ui->star3->setPixmap(QPixmap(":/pic/click5.png"));
        ui->star2->setPixmap(QPixmap(":/pic/click5.png"));
        ui->star1->setPixmap(QPixmap(":/pic/click5.png"));
    }
    else if(R==2)
    {
        ui->star2->setPixmap(QPixmap(":/pic/click5.png"));
        ui->star1->setPixmap(QPixmap(":/pic/click5.png"));
    }
    else if(R==1)
    {
        ui->star1->setPixmap(QPixmap(":/pic/click5.png"));
    }
}

void result::setScore(const QString &sc)
{
    ui->score->setText(sc);
}

void result::pushbutton_2_clicked()
{
    this->close();
}
