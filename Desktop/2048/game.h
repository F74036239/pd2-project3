#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QMainWindow>
#include "result.h"
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QObject>
#include <QLabel>


using namespace std;
namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent , result *res);
    ~game();

private:
    Ui::game *ui;
    QWidget *mainwindow;
    result *reswindow;
    int square[4][4];
    QLabel *score;
    QLabel *label,*label_2,*label_3,*label_4,*label_5,*label_6,*label_7,*label_8,*label_9,*label_10,*label_11,*label_12,*label_13,*label_14,*label_15,*label_16;
    void gameover();
    void picture(int i,int j);
    void addNum();
    void upmove();
    void downmove();
    void leftmove();
    void rightmove();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void gameclick();
};

#endif // GAME_H
