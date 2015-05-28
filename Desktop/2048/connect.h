#ifndef CONNECT_H
#define CONNECT_H

#include <QObject>
#include <QLabel>

class connect : public QObject
{
    Q_OBJECT
public:
    explicit connect(QWidget *parent,int Row ,int Col);
    ~connect();

signals:

public slots:

private:
    QLabel *label;
    int row,col;
};

#endif // CONNECT_H
