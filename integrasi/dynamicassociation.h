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
    void setParameters(double thresholdAssociation,
                       double thresholdOcclusion,
                       double frameRate);
    int maximumIdOnList(QList<Player>);
    
    UnitDynamicAssociate* myUnitDynamicAssociate;
    KalmanDynamic* myKalmanProcessor;
    
    QList<Player> currentData;
    QList<Player> predictionData;
    QList<Player> associateData;
    bool isIdAssigned;
private:

public slots:
    void processTransformedData(QList<Player>);
    void getAssociatedData(QList<Player>);
    void processAssignedData(QList<Player>);
signals:
    void sendProcessedData(QList<Player>);
};

#endif // DYNAMIASSOCIATION_H
