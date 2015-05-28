#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include "game.h"
#include "result.h"

namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private:
    Ui::start *ui;
    game *gamewindow;
    result *resDialog;

private slots:
    void startclick();
    void resetgame();
    void exitclick();
};

#endif // START_H
