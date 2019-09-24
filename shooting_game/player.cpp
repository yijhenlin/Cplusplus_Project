#include "player.h"
#include <QDebug>
#define speed 20

Player::Player(object *parent) : object(parent)
{
    setPixmap(QPixmap("../Project3/picture/player.png"));
    setPos(0, 730 - pixmap().height());
    timer = new QTimer;
    bomb_t = new QTimer;
    timer->start(10);
    bomb_t->start(5);

}
void Player::reset(){
    setPixmap(QPixmap("../Project3/picture/player.png"));
    setPos(0, 730 - pixmap().height());
    count = 0;
    bomb = 0;
}
void Player::move_o(QKeyEvent *e)
{

    switch(e->key()) {
        case Qt::Key_Up:
        case Qt::Key_W:
            if(pos().y() < 0);
            else setPos(x(), y() - speed);
        break;
        case Qt::Key_Down:
        case Qt::Key_S:
            if(pos().y() + pixmap().height() > 730);
            else setPos(x(), y() + speed);
        break;
        case Qt::Key_Left:
        case Qt::Key_A:
            if(pos().x() < 0);
            else setPos(x() - speed, y());
        break;
        case Qt::Key_Right:
        case Qt::Key_D:
            if(pos().x() + pixmap().width() > 520);
            else setPos(x() + speed, y());
        break;
        }
}

void Player::attack_o(QMouseEvent *event)
{

    bullet *b = new bullet;
    if(event->button() == Qt::RightButton){
        if(bomb < 3);
        else{
            bomb = bomb - 3;
            b->setPixmap(QPixmap("../Project3/picture/bomb.png"));
            b->setPos(x() + pixmap().width() / 2 - b->pixmap().width() / 2, y() - b->pixmap().height());
            b->connect(bomb_t, SIGNAL(timeout()), b, SLOT(fly()));
            this->scene()->addItem(static_cast<QGraphicsPixmapItem*>(b));
            connect(b, SIGNAL(hit_enemy()), this, SLOT(hit_by_bomb()));
        }
    }
    else{
        b->setPixmap(QPixmap("../Project3/picture/bullet.png"));
        b->setPos(x() + pixmap().width() / 2 - b->pixmap().width() / 2, y() - b->pixmap().height());
        b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
        this->scene()->addItem(static_cast<QGraphicsPixmapItem*>(b));
        connect(b, SIGNAL(hit_enemy()), this, SLOT(hit()));
    }
    connect(b, SIGNAL(miss()), this, SLOT(miss()));
}

void Player::hit()
{
    count++;
    if(bomb < 9)bomb++;
    qDebug() << bomb;
    hit_enemy();
}

void Player::hit_by_bomb()
{
    count++;
    hit_enemy_by_bomb();
}

void Player::win()
{
    setPixmap(QPixmap("../Project3/picture/player_win.png"));
}

void Player::lose()
{
    setPixmap(QPixmap("../Project3/picture/player_lose.png"));
}

void Player::miss()
{
    player_miss();
    count = 0;
    if(bomb >= 9) bomb = 9;
    else if (bomb >= 6)bomb = 6;
    else if (bomb >= 3)bomb = 3;
    else bomb = 0;
}
