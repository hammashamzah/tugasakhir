#ifndef PLAYERVISUAL_H
#define PLAYERVISUAL_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class PlayerVisual : public QGraphicsItem
{
public:
    PlayerVisual();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
    void DoCollision();
};

#endif // PLAYERVISUAL_H
