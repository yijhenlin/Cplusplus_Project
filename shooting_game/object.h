#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

class object : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit object(QObject *parent = nullptr);
    virtual void move_o(QKeyEvent *) = 0;
    virtual void attack_o(QMouseEvent *) = 0;
    virtual int get_c() = 0;
    virtual int get_b() = 0;
    virtual void reset() = 0;
signals:

public slots:

private:

};

#endif // OBJECT_H
