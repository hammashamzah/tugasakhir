#include "kalmandynamictoplevel.h"

KalmanDynamicTopLevel::KalmanDynamicTopLevel(QVector<QList<QPoint> > trapeziumCoordinate,double frameRate)
{
	kalmanprocessorCam1 = new KalmanDynamic(trapeziumCoordinate.at(0),frameRate);
	kalmanprocessorCam2 = new KalmanDynamic(trapeziumCoordinate.at(1),frameRate);

	QObject::connect(this,SIGNAL(sendtoKalman1(QList<Player>)),kalmanprocessorCam1,SLOT(getDataCurr(QList<Player>)));
	QObject::connect(this,SIGNAL(sendtoKalman2(QList<Player>)),kalmanprocessorCam2,SLOT(getDataCurr(QList<Player>)));

}

KalmanDynamicTopLevel::~KalmanDynamicTopLevel(){

}

void KalmanDynamicTopLevel::getMappedData(QVector<QList<Player> > MappedData){
	emit sendtoKalman1(MappedData.at(0));
	emit sendtoKalman2(MappedData.at(1));

	predictorCam1 = kalmanprocessorCam1->predictionData;
	predictorCam2 = kalmanprocessorCam2->predictionData;
	previousCam1 = kalmanprocessorCam1->previousData;
	previousCam2 = kalmanprocessorCam2->previousData;

	predictor[0] = predictorCam1;
	predictor[1] = predictorCam2;
	previous[0]  = previousCam1;
	previous[1]  = previousCam2;
	emit sendPredictor(predictor);
	emit sendPrevious(previous);
}
