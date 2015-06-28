#ifndef BLANK_H
#define BLANK_H
#include<QPushButton>
#include<QObject>
#include<QTimer>

class Blank :public QObject
{
    Q_OBJECT
public:
    const int row;
    const int column;
    int number;         //圖案的編號
    QPushButton *button;
    QTimer *time;       //動畫
    int shift;          //動畫

    Blank(int R , int C, QWidget *parent);
    void setNumber();
    void setButtonPicture();
    void operator -(Blank *b);  //左右
    void operator |(Blank *b);  //上下
    ~Blank();

public slots:           //接收端
    void click();
    //移動的動畫
    void moveright();
    void moveleft();
    void moveup();
    void movedown();


signals:                //發送
    void Click(int R ,int C);
    void moveDone();

};

#endif // BLANK_H
