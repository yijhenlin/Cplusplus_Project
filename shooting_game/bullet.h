#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit bullet(QObject *parent = nullptr);
signals:
    void hit_player();
    void hit_enemy();
    void miss();
public slots:
    void fly();
    void fall();
private:

};

#endif // BULLET_H
