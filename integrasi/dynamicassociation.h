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
    DynamicAssociation();
    ~DynamicAssociation();
    void setParameters(QVector<QList<QPoint> > trapeziumCoordinate, double thresholdAssociationCam1,
                       double thresholdAssociationCam2, double thresholdOcclusionCam1,
                       double thresholdOcclusionCam2, float boundaryThreshold1,float boundaryThreshold2,
                       double frameRate);
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
    QList<Player> lostDataCam1;
    QList<Player> lostDataCam2;

    QVector<QList<Player> >dataAggregate;
    QVector<QList<Player> >dataLostFound;
    QVector<QList<Player> >TransformeddataLostFound;

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
    void extractDataLostCam1();
    void extractDataLostCam2();
    void boundaryHandler();
    void associatesDataLostFound();

    bool isMatchPrevioustoAssociated;
    QVector<QList<Player> > potentiallyInsideBoundary;
    QList<QPoint> associatedIdinBoundaryCam1;
    QList<QPoint> associatedIdinBoundaryCam2;
    float minimum_distance;
    float minimum_distanceCompare;
    int indexmatchNewandBoundaryHandlerAssociated;

    float boundaryTH1,boundaryTH2;
public slots:
    void getCurrentData(QVector<QList<Player> >);
    void getNewDataCam1(QList<Player>);
    void getNewDataCam2(QList<Player>);
    void getAssociatedDataCam1(QList<Player>);
    void getAssociatedDataCam2(QList<Player>);
    void processAssignedData(QVector<QList<Player> >);
    void getTransformedData(QVector<QList<Player> >);
signals:
    void sendDataAggregate(QVector<QList<Player> >);
    void sendDatatobeTransformed(QVector<QList<Player> >);
};

#endif // DYNAMIASSOCIATION_H
