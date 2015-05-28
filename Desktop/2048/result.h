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
    void setWin(char win);
    void setScore(const QString &sc);

signals:
    void reset();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::result *ui;
    QWidget *mainWindow;
};

#endif // RESULT_H
