#include "dynamicassociation.h"

DynamicAssociation::DynamicAssociation() {
	myUnitDynamicAssociate = new UnitDynamicAssociate();
	myKalmanProcessor = new KalmanDynamic();

    QObject::connect(myUnitDynamicAssociate, SIGNAL(sendAssociatedData(QList<Player>)), this, SLOT(getAssociatedData(QList<Player>)));

	isIdAssigned = false;
 }
DynamicAssociation::~DynamicAssociation() {

}

void DynamicAssociation::setParameters(double thresholdAssociation, double thresholdOcclusion,
                                       double frameRate) {
	myUnitDynamicAssociate->setParameters(thresholdAssociation, thresholdOcclusion);
	myKalmanProcessor->setParameters(frameRate);
}
void DynamicAssociation::processTransformedData(QList<Player> current) {
	currentData = current;
	if (isIdAssigned) {
		myUnitDynamicAssociate->dataCameraAssociation(currentData, predictionData);
		//get prediction from kalman filter using associated data
		myKalmanProcessor->processDataCurrent(associateData);
		predictionData.clear();
		predictionData = myKalmanProcessor->predictionData;
		emit sendToDataWindowAssociated(associateData);
		emit sendToDataWindow(predictionData);
		emit sendProcessedData(predictionData);
	} else {
		emit sendProcessedData(current);
	}
}

void DynamicAssociation::getAssociatedData(QList<Player>associatedDataInput) {
	associateData.clear();
	//////////qDebug() << "Size of previous 1: " << associatedDataCam1.size();
	associateData.append(associatedDataInput);
}

void DynamicAssociation::processAssignedData(QList<Player> assigned)  {

	QList<Player> temp;
	temp.append(assigned);
	isIdAssigned = true;
	myKalmanProcessor->setInitialData(temp);
	predictionData.clear();
	predictionData.append(myKalmanProcessor->predictionData);
	////qDebug() << "Debug assigned data: " << predictionData.size();
	emit sendToDataWindow(assigned);
}

