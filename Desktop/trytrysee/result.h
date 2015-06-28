#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class result;
}

class result : public QWidget
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();
    void setStar(int sc,int R);
    void setScore(const QString &sc);
    void setWord(QString S);

signals:
    void quit(int star,int score);

private slots:
    void pushbutton_2_clicked();

private:
    Ui::result *ui;
    QWidget *mainWindow;
};

#endif // RESULT_H
