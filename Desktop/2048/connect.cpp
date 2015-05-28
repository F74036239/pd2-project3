#include "connect.h"

connect::connect(QWidget *parent,int Row ,int Col)
{
    row=Row;
    col=Col;
    label = new QLabel(parent);
    label->setGeometry(60+60*row,60+60*col,50,50);

}

connect::~connect()
{
    delete label;
}

