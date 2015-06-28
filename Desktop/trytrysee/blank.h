#ifndef BLANK_H
#define BLANK_H
#include <QPushButton>
#include <QObject>
#include <QTimer>

class Blank : public QObject
{
    Q_OBJECT

public:
    const int row;
    const int column;
    int number;
    QPushButton *button;
    QTimer *time;
    int shift;

    Blank(int R , int C , QWidget *parent);
    void setNumber();
    void setButtonPicture();
    void operator -(Blank *b);
    void operator |(Blank *b);
    ~Blank();

public slots:
    void click();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

signals:
    void Click(int R , int C);
    void moveDone();

};

#endif // BLANK_H
