#ifndef KALMANDYNAMICTOPLEVEL_H
#define KALMANDYNAMICTOPLEVEL_H
#include "kalmandynamic.h"
#include "player.h"
#include <QObject>
#include <QList>
#include <QPoint>
#include <QVector>

class KalmanDynamicTopLevel:public QObject
{
    Q_OBJECT
public:
    KalmanDynamicTopLevel(QVector<QList<QPoint> > trapeziumCoordinate,double frameRate);
    ~KalmanDynamicTopLevel();

    QList<Player> predictorCam1;
    //QList<Player> predictorCam2;
    QVector<QList<Player> > predictor;

    QList<Player> previousCam1;
    //QList<Player> previousCam2;
    QVector<QList<Player> > previous;

    KalmanDynamic* kalmanprocessorCam1;
    //KalmanDynamic* kalmanprocessorCam2;

public slots:
    void getMappedData(QList<Player>);
signals:
	void sendtoKalman1(QList<Player>);
	//void sendtoKalman2(QList<Player>);
    void sendPredictor(QList<Player>);
    void sendPrevious (QList<Player>);

};

#endif // KALMANDYNAMICTOPLEVEL_H
