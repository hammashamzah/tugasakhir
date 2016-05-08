#ifndef UNITDYNAMICASSOCIATE_H
#define UNITDYNAMICASSOCIATE_H
#include "searchplayerdata.h"
#include "player.h"
#include <QList>
#include <QObject>
#include <QPoint>
#include <QDebug>

#define BOBOT_PREDICTIONS 0.3

class UnitDynamicAssociate:public QObject
{
	Q_OBJECT
public:
    UnitDynamicAssociate();
    ~UnitDynamicAssociate();
    void setParameters(float associationThreshold, float occlusionThreshold);
    void dataCameraAssociation(QList<Player> current,QList<Player> prediction);
    int lastID;
private:

    int currentDataInitialSize;
    float euclideanDistance;
	int first_ID;
    float threshold;
    float occlusionTh;
    float associationTh;
    QList <Player> currentData;
    QList <Player> predictionData;

	void  dataAssociating();
	void  occlusionHandler();	
    int maximumIdOnList(QList<Player>);
signals:    
    void sendAssociatedData(QList<Player>);
};

#endif // UNITDYNAMICASSOCIATE_H
