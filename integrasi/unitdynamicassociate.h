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
    UnitDynamicAssociate(QList<QPoint> trapeziumCoordinate, double associationThreshold, double occlusionThreshold);
    ~UnitDynamicAssociate();
    void dataCameraAssociation(QList<Player> previous,QList<Player> current,QList<Player> prediction,int firstID);
    int lastID;
private:
    SearchPlayerData* searchingdata;
	double Euclid_x,Euclid_y;
    double th_y;
    double th_xka,th_xki;

	int first_ID;
    double xo,yo;
    double XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR;
    double occlusionTh;
    double associationTh;
    QList <Player> curr;
    QList <Player> previous;
    QList <Player> pred;
    QList <int> potentially_Lost;
    QList <Player> potentially_New;

    double threshold_coef(double y);
    void find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m);
    double find_threshold_y(double y);
    void find_threshold_xocc(double &x_kanan,double &x_kiri,double y,double x,double y_m);
    double find_threshold_yocc(double y);
	void  dataAssociating();
	void  occlusionHandler();	
signals:
    void sendAssociatedData(QList<Player>);
	void sendNewData(QList<Player>);
};

#endif // UNITDYNAMICASSOCIATE_H
