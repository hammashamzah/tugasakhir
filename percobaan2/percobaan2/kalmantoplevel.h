#ifndef KALMANTOPLEVEL_H
#define KALMANTOPLEVEL_H
#include "kalmanpredictor.h"
#include <QObject>
#include <QList>
#include <QPoint>
#include "player.h"
 


class KalmanTopLevel:public QObject
{
	Q_OBJECT
public:
	QList<Player> predictorCam1;
	QList<Player> predictorCam2;
	QList<QList<Player> > predictor;

	QList<Player> previousCam1;
	QList<Player> previousCam2;
	QList<QList<Player> > previous;	
	
	KalmanPredictor* kalmanprocessorCam1;
	KalmanPredictor* kalmanprocessorCam2;

    KalmanTopLevel(QList<QList<QPoint> > trapeziumCoordinate,double frameRate);
    ~KalmanTopLevel();
public slots:
	void getMappedData(QList<QList<Player> >);
signals:
	void sendtoKalman1(QList<Player>);
	void sendtoKalman2(QList<Player>);
    void sendPredictor(QList<QList<Player> >);
    void sendPrevious (QList<QList<Player> >);

};

#endif // KALMANHIGHLEVEL_H
