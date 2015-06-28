#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QTimer>
#include <QTime>

class countdown: public QTimer
{
    Q_OBJECT

public:
    countdown(QWidget *parent=0);
    ~countdown();
    void start();
    int lefttime();

private slots:
    void resettime();

private:
    QTime m_time;
};

#endif // COUNTDOWN_H
