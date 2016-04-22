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
    void setParameters(QList<QPoint> trapeziumCoordinate, float associationThreshold, float occlusionThreshold);
    void dataCameraAssociation(QList<Player> previous,QList<Player> current,QList<Player> prediction,int firstID);
    int lastID;
    float xo_1,yo_1;
    float xo_2,yo_2;
    float Euclid_r;
private:
    SearchPlayerData* searchingdata;
    float sub_proc_varx;
    float sub_proc_vary;
	float Euclid_x,Euclid_y;
    float th_y;
    float th_xka,th_xki;

	int first_ID;

    float XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR;
    float occlusionTh;
    float associationTh;
    QList <Player> current;
    QList <Player> previous;
    QList <Player> prediction;
    QList <int> potentially_Lost;
    QList <Player> potentially_New;
    QList <Player> lostData;
    bool isPreviousObjectAssociated;
    bool isCurrentObjectOccluded;
    int indexMatchedPrevious;
    int indexMatchedPrediction;

    float threshold_coef(float y);
    void find_threshold_x(float &x_kanan,float &x_kiri,float y,float x,float y_m);
    float find_threshold_y(float y);
    void find_threshold_xocc(float &x_kanan,float &x_kiri,float y,float x,float y_m);
    float find_threshold_yocc(float y);
	void  dataAssociating();
	void  occlusionHandler();	
signals:
    void sendAssociatedData(QList<Player>);
	void sendNewData(QList<Player>);
};

#endif // UNITDYNAMICASSOCIATE_H