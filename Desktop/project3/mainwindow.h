#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<ctime>
#include<cstdlib>
#include"blank.h"
#include"delete_blank.h"
#include"star.h"
#include"cancel.h"
#include"vertical.h"
#include"ninebox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Blank *b[10][10];
    bool isclicked;
    int record_R;
    int record_C;

    explicit MainWindow(QWidget *parent = 0);
    void gamestart();
    void setClickPicture(Blank *b);
    bool judge(int row1,int col1,int row2,int col2);

    bool judgeDoubleStar(int row,int col);
    bool judgeStaradd(int row,int col);
    bool judgeStar(int row,int col);
    bool judgeBomb(int row,int col);
    bool judge4V(int row,int col);
    bool judge4H(int row,int col);
    bool judge3V(int row,int col);
    bool judge3H(int row,int col);

    void newPicture();      //合併以後出現新圖案
    ~MainWindow();

public slots:
    void button_clicked(int R,int C);
    void zeroDisappear();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
