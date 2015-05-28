#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}

void result::setWin(char win)
{
    if(win=='W')
    {
        ui->label->setText("You Win");
    }
    else
    {
        ui->label->setText("Game Over");
    }
}

void result::on_pushButton_2_clicked()
{
    QApplication::exit(0);      //quit
}

void result::on_pushButton_clicked()
{
    emit reset();               //restart
}

void result::setScore(const QString &sc)
{
    ui->final_score->setText(sc);
}
