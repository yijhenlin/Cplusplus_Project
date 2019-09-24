#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "bullet.h"

class Player : public object
{
    Q_OBJECT
public:
    explicit Player(object *parent = nullptr);
    virtual void move_o(QKeyEvent *);
    virtual void attack_o(QMouseEvent *);
    virtual int get_c(){return count;}
    virtual int get_b(){return bomb;}
    virtual void reset();
signals:
    void hit_enemy_by_bomb();
    void hit_enemy();
    void player_miss();
public slots:
    void hit_by_bomb();
    void hit();
    void win();
    void lose();
    void miss();
private:
    QTimer *timer;
    QTimer *bomb_t;
    int count = 0;
    int bomb = 0;
};

#endif // PLAYER_H
