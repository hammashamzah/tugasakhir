#ifndef DYNAMIASSOCIATION_H
#define DYNAMIASSOCIATION_H
#include "unitdynamicassociate.h"
#include "kalmandynamic.h"
#include "player.h"
#include <QList>
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QDebug>

class DynamicAssociation: public QObject
{
    Q_OBJECT
public:
    DynamicAssociation(QVector<QList<QPoint> > trapeziumCoordinate, double thresholdAssociationCam1, double thresholdAssociationCam2, double thresholdOcclusionCam1, double thresholdOcclusionCam2, double frameRate);
    ~DynamicAssociation();
    int maximumIdOnList(QList<Player>);
    UnitDynamicAssociate *cam_1_Processor;
    UnitDynamicAssociate *cam_2_Processor;
    KalmanDynamic *kalmanProcessor_1;
    KalmanDynamic *kalmanProcessor_2;
    QList<Player> currentDataCam1;
    QList<Player> currentDataCam2;
    QList<Player> previousDataCam1;
    QList<Player> previousDataCam2;
    QList<Player> predictionDataCam1;
    QList<Player> predictionDataCam2;
    QVector<QList<Player> >dataAggregate;
    QList<Player> temp1;
    QList<Player> temp2;
    QList<Player> newData1;
    QList<Player> newData2;
    QList<Player> associateData1;
    QList<Player> associateData2;
    bool isIdAssigned;
    bool isSetPreviousData, isSetPredictionData;
    bool isSetNewCam1, isSetNewCam2, isSetAssociateCam1, isSetAssociateCam2;
private:

public slots:
    void getCurrentData(QVector<QList<Player> >);
    void getNewDataCam1(QList<Player>);
    void getNewDataCam2(QList<Player>);
    void getAssociatedDataCam1(QList<Player>);
    void getAssociatedDataCam2(QList<Player>);
    void processAssignedData(QVector<QList<Player> >);
signals:
    void sendDataAggregate(QVector<QList<Player> >);
};

#endif // DYNAMIASSOCIATION_H
