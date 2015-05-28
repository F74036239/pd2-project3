#include "start.h"
#include "ui_start.h"

start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    //start play
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(startclick()));
    //quit the game
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(exitclick()));
    gamewindow=NULL;
    resDialog=new result;
}

start::~start()
{
    delete ui;
}

void start::startclick()
{
    gamewindow=new game(this,resDialog);
    connect(resDialog,SIGNAL(reset()),this,SLOT(resetgame()));
    this->setCentralWidget(gamewindow);
}

void start::resetgame()
{
    resDialog->hide();
    if(gamewindow!=NULL)
    {
        delete gamewindow;
    }
    gamewindow = new game(this,resDialog);
    this->setCentralWidget(gamewindow);
}

void start::exitclick()
{
    QApplication::exit(0);
}
