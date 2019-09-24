#include "enemy.h"
#include <cstdlib>
#include <QDebug>
#define speed 10


Enemy::Enemy(object *parent) : object(parent)
{
    setPixmap(QPixmap("../Project3/picture/boss.png"));
    attack_timer = new QTimer;
    attack_timer->start(900);
    connect(attack_timer, SIGNAL(timeout()), this, SLOT(attack()));
    move_timer = new QTimer;
    move_timer->start(80);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    timer = new QTimer;
    timer->start(10);

}

void Enemy::reset()
{
    setPixmap(QPixmap("../Project3/picture/boss.png"));
    connect(attack_timer, SIGNAL(timeout()), this, SLOT(attack()));
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Enemy::move()
{
    int r = (rand()%9)+4;
    if(r % 2 == 0){
        for(;r >= 0;r--){
            if(x() - speed < 0) setPos(x() + speed, y());
            else setPos(x() - speed, y());
        }
    }
    else{
        for(;r >= 0;r--){
            if(x() + speed > 280) setPos(x() - speed, y());
            else setPos(x() + speed , y());
        }
    }
}



void Enemy::attack()
{
    bullet *b = new bullet;
    b->setPixmap(QPixmap("../Project3/picture/bigbullet.png"));
    b->setPos(x() + pixmap().width() / 2 - b->pixmap().width() / 2, y() + pixmap().height());
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fall()));
    this->scene()->addItem(static_cast<QGraphicsPixmapItem*>(b));
    connect(b, SIGNAL(hit_player()), this, SLOT(hit()));

}

void Enemy::hit()
{
    hit_player();
}

void Enemy::win()
{
    disconnect(attack_timer, SIGNAL(timeout()), this, SLOT(attack()));
    disconnect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    setPixmap(QPixmap("../Project3/picture/enemy_lose.png"));
}

void Enemy::lose()
{
    disconnect(attack_timer, SIGNAL(timeout()), this, SLOT(attack()));
    disconnect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    setPixmap(QPixmap("../Project3/picture/enemy_win.png"));
}
