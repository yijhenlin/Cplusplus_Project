#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "object.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void show_bomb();

signals:
    void win();
    void lose();
public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    void player_HP();
    void enemy_HP();
    void enemy_HP_by_bomb();
    void miss();
    void reset();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    object *player;
    object *enemy;
    int HP_p = 100;
    int HP_e = 300;
    int score = 0;
    int num = 0;

};

#endif // MAINWINDOW_H
