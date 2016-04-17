#include "kalmantoplevel.h"

KalmanTopLevel::KalmanTopLevel(QList<QList<QPoint> > trapeziumCoordinate,double frameRate)
{
	kalmanprocessorCam1 = new KalmanPredictor(trapeziumCoordinate.at(0),frameRate);
	kalmanprocessorCam2 = new KalmanPredictor(trapeziumCoordinate.at(1),frameRate);

	QObject::connect(this,SIGNAL(sendtoKalman1(QList<Player>)),kalmanprocessorCam1,SLOT(getDataCurr(QList<Player>)));
	QObject::connect(this,SIGNAL(sendtoKalman2(QList<Player>)),kalmanprocessorCam2,SLOT(getDataCurr(QList<Player>)));
}

KalmanTopLevel::~KalmanTopLevel(){

}


void KalmanTopLevel::getMappedData(QList<QList<Player> > MappedData){
	predictorCam1.clear();
	predictorCam2.clear();
	
	emit sendtoKalman1(MappedData.at(0));
	emit sendtoKalman2(MappedData.at(1));

		predictorCam1 = kalmanprocessorCam1->predictionData;
		predictorCam2 = kalmanprocessorCam2->predictionData;
		previousCam1 = kalmanprocessorCam1->previousData;
		previousCam2 = kalmanprocessorCam2->previousData;

	predictor.append(predictorCam1);
	predictor.append(predictorCam2);
	previous.append(predictorCam1);
	previous.append(predictorCam2);

	emit sendPredictor(predictor);
	emit sendPrevious(previous);

}