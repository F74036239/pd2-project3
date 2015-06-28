#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QTimer>
#include <ctime>
#include <cstdlib>
#include <blank.h>
#include "move_success.h"
#include "star.h"
#include "bomb.h"
#include "four.h"
#include "three.h"
#include "result.h"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    Blank *b[10][10];
    bool isclicked;
    int record_R;
    int record_C;
    int Result_star;
    QTimer *timer;

    explicit MainWindow(QWidget *parent = 0);
    void gameStart();
    void gameover(QString S);
    void setClickPicture(Blank *b);
    void newPicture();
    void fillzero();
    void judgeTime();

    bool conti_judge();
    bool judge(int row1 , int col1 , int row2 , int col2);
    bool judge2Special(int row1,int col1,int row2 , int col2);
    bool judgeStar(int row,int col);
    bool judgeBomb(int row,int col);
    bool judgeFour(int row,int col);
    bool judgeThree(int row,int col);

    ~MainWindow();
signals:
    void quit(int star , int score);

public slots:
    void button_clicked(int R,int C);
    void zeroDisappear();
    void lefttime();
    void gameExit();

private:
    Ui::MainWindow *ui;
    result *resWindow;
};

#endif // MAINWINDOW_H
