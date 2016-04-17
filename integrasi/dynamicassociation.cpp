#include "dynamicassociation.h"

DynamicAssociation::DynamicAssociation(QVector<QList<QPoint> > trapeziumCoordinate, double thresholdAssociationCam1, double thresholdAssociationCam2, double thresholdOcclusionCam1, double thresholdOcclusionCam2, double frameRate) {
    qDebug() << thresholdAssociationCam1 << " " << thresholdAssociationCam2 << " " << thresholdOcclusionCam1 << " " << thresholdOcclusionCam2;
	cam_1_Processor = new UnitDynamicAssociate(trapeziumCoordinate[0], thresholdAssociationCam1, thresholdOcclusionCam1);
	cam_2_Processor = new UnitDynamicAssociate(trapeziumCoordinate[0], thresholdAssociationCam2, thresholdOcclusionCam2);
	kalmanProcessor_1 = new KalmanDynamic(trapeziumCoordinate[0], frameRate);
	kalmanProcessor_2 = new KalmanDynamic(trapeziumCoordinate[1], frameRate);

	QObject::connect(cam_1_Processor, SIGNAL(sendAssociatedData(QList<Player>)), this, SLOT(getAssociatedDataCam1(QList<Player>)));
	QObject::connect(cam_1_Processor, SIGNAL(sendNewData(QList<Player>)), this, SLOT(getNewDataCam1(QList<Player>)));
	QObject::connect(cam_2_Processor, SIGNAL(sendAssociatedData(QList<Player>)), this, SLOT(getAssociatedDataCam2(QList<Player>)));
	QObject::connect(cam_2_Processor, SIGNAL(sendNewData(QList<Player>)), this, SLOT(getNewDataCam2(QList<Player>)));
	isSetPreviousData = false;
	isSetPredictionData = false;
	isSetNewCam1 = false; isSetNewCam2 = false; isSetAssociateCam1 = false; isSetAssociateCam2 = false;

}
DynamicAssociation::~DynamicAssociation() {

}

void DynamicAssociation::getCurrentData(QVector<QList<Player> > currentData) {
    qDebug() << "before associating: " << currentData.at(0).size() << currentData.at(1).size();
	currentDataCam1 = currentData.at(0);
    currentDataCam2 = currentData.at(1);
	cam_1_Processor->dataCameraAssociation(previousDataCam1, currentDataCam1, predictionDataCam1, (previousDataCam1.size() + previousDataCam2.size()));
	cam_2_Processor->dataCameraAssociation(previousDataCam2, currentDataCam2, predictionDataCam2, cam_1_Processor->lastID);
	if (isSetNewCam1 && isSetAssociateCam2 && isSetAssociateCam1 && isSetNewCam2) {
		dataAggregate.clear();
		dataAggregate.resize(2);
		dataAggregate[0].append(associateData1);
		dataAggregate[1].append(associateData2);
		dataAggregate[0].append(newData1);
		dataAggregate[1].append(newData2);
        qDebug() << "size aggregate: " << dataAggregate.at(0).size() << dataAggregate.at(1).size();
		emit sendDataAggregate(dataAggregate);
	}
}

void DynamicAssociation::getNewDataCam1(QList<Player> newDataCam1) {
    newData1.clear();
    newData1.append(newDataCam1);
	isSetNewCam1 = true;
}
void DynamicAssociation::getNewDataCam2(QList<Player> newDataCam2) {
    newData2.clear();
    newData2.append(newDataCam2);
	isSetNewCam2 = true;
}
void DynamicAssociation::getAssociatedDataCam1(QList<Player>associatedDataCam1) {
    associateData1.clear();
    associateData1.append(associatedDataCam1);
	isSetAssociateCam1 = true;
}
void DynamicAssociation::getAssociatedDataCam2(QList<Player>associatedDataCam2) {
    associateData2.clear();
    associateData2.append(associatedDataCam2);
	isSetAssociateCam2 = true;
}

void DynamicAssociation::processAssignedData(QVector<QList<Player> > assignedData)  {
	kalmanProcessor_1->processDataCurrent(assignedData.at(0));
	kalmanProcessor_1->processDataCurrent(assignedData.at(1));

	previousDataCam1.clear();
	previousDataCam1 = kalmanProcessor_1->previousData;
	previousDataCam2.clear();
	previousDataCam2 = kalmanProcessor_2->previousData;
	predictionDataCam1.clear();
	predictionDataCam1 = kalmanProcessor_1->predictionData;
	predictionDataCam2.clear();
	predictionDataCam2 = kalmanProcessor_2->predictionData;

	//proses selesai
}
