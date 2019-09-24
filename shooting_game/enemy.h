#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"
#include "bullet.h"

class Enemy : public object
{
    Q_OBJECT

public:
    explicit Enemy(object *parent = nullptr);
    virtual void move_o(QKeyEvent *){}
    virtual void attack_o(QMouseEvent *){}
    virtual int get_c(){return 0;}
    virtual int get_b(){return 0;}
    virtual void reset();
signals:
    void hit_player();
public slots:
    void move();
    void hit();
    void attack();
    void win();
    void lose();
private:
    QTimer *attack_timer;
    QTimer *move_timer;
    QTimer *timer;
};

#endif // ENEMY_H
