#ifndef PLAYERVISUAL_H
#define PLAYERVISUAL_H
#define HEAT_MAP_RESOLUTION_X 20
#define HEAT_MAP_RESOLUTION_Y 10

#include <QObject>
#include <QPoint>
//#include "objectvariable.h"

class playerVisual : public QObject
{
    Q_OBJECT
public:
    explicit playerVisual(QObject *parent = 0);
    int id;
    char Name[20];
    char TeamSide;
    QPoint Position;
    int backNumber;
    double speed;
    bool signedFlag;
    int heatMapCounter[HEAT_MAP_RESOLUTION_X][HEAT_MAP_RESOLUTION_Y];

signals:

public slots:
private:
    QPoint PosHeatMap;
};

#endif // PLAYERVISUAL_H
