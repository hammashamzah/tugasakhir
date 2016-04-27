#include "playervisual.h"

PlayerVisual::PlayerVisual()
{
    //random start rotation
    angle = (qrand() % 360);
    setRotation(angle);

    //set the speed
    speed = 5;

    //random start position
    int StartX = 0;
    int StartY = 0;

    if((qrand() % 1))
    {
        StartX = (qrand() % 200);
        StartY = (qrand() % 200);
    }
    else
    {
        StartX = (qrand() % -100);
        StartY = (qrand() % -100);
    }

    setPos(mapToParent(StartX,StartY));
}

void PlayerVisual::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush;

    Brush.setColor(Qt::green);

    painter->setBrush(Brush);
    painter->drawEllipse(QPoint(10,10),10, 10);

}

QRectF PlayerVisual::boundingRect() const
{
    return QRect(0,0,20,20);
}


void PlayerVisual::advance(int phase)
{
    if(!phase) return;

    setPos(mapToParent(0,-(speed)));
}
