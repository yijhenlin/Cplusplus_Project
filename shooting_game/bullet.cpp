#include "bullet.h"
#include <QDebug>

bullet::bullet(QObject *parent) : QObject(parent)
{

}

void bullet::fly()
{
    setPos(x(), y() - 3);
    if(y() < 0) {
        miss();
        this->scene()->removeItem(this);
        delete this;
    }
    else if(!this->scene()->collidingItems(this).isEmpty()) {
        QGraphicsItem *enemy = this->scene()->collidingItems(this).first();
        if(this->scene()->collidingItems(this).size() >= 2 && enemy->boundingRect().width() == 200){
            hit_enemy();
            this->scene()->removeItem(this);
            delete this;
        }
    }
}

void bullet::fall()
{
    setPos(x(), y() + 3);
    if(y() > 730) {
        this->scene()->removeItem(this);
        delete this;
    }
    else if(!this->scene()->collidingItems(this).isEmpty()) {
        QGraphicsItem *player = this->scene()->collidingItems(this).first();
        if(this->scene()->collidingItems(this).size() >= 2 && player->boundingRect().width() == 223){
            hit_player();
            this->scene()->removeItem(this);
            delete this;
        }
    }
}
