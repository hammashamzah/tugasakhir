#ifndef KALMANDYNAMIC_H
#define KALMANDYNAMIC_H

#include <opencv2/core/core.hpp>

#include <opencv2/video/tracking.hpp>
#include <stdio.h>
#include <cmath>
#include <string>
#include <QList>
#include <QObject>
#include <QPoint>
#include <QDebug>
#include "player.h"
#include "searchplayerdata.h"
#include "kalmanobject.h"

using namespace std;
using namespace cv;

class KalmanDynamic: public QObject
{
    Q_OBJECT
public:
    Player* player;
    SearchPlayerData* searchingdata;
    KalmanDynamic(double frameRate);
    ~KalmanDynamic();
    void setInitialData(QList<Player> initialData);
    void processDataCurrent(QList<Player>);
    QList <Player> previousData;
    QList <Player> predictionData;
private:
    double interval;
    QList <Player> currentData;
    QList <KalmanObject> kalmanProcessor;
signals:
    void sendPrediction(QList<Player>);
    void sendPrevious(QList<Player>);
};

#endif // KALMANDYNAMIC_H

