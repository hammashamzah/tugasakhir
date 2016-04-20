#include "dynamicassociation.h"

DynamicAssociation::DynamicAssociation() {
	cam_1_Processor = new UnitDynamicAssociate();
	cam_2_Processor = new UnitDynamicAssociate();
	kalmanProcessor_1 = new KalmanDynamic();
	kalmanProcessor_2 = new KalmanDynamic();

	QObject::connect(cam_1_Processor, SIGNAL(sendAssociatedData(QList<Player>)), this, SLOT(getAssociatedDataCam1(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_1_Processor, SIGNAL(sendNewData(QList<Player>)), this, SLOT(getNewDataCam1(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_2_Processor, SIGNAL(sendAssociatedData(QList<Player>)), this, SLOT(getAssociatedDataCam2(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_2_Processor, SIGNAL(sendNewData(QList<Player>)), this, SLOT(getNewDataCam2(QList<Player>)), Qt::UniqueConnection);

	isSetPreviousData = false;
	isSetPredictionData = false;
	isSetNewCam1 = false; isSetNewCam2 = false; isSetAssociateCam1 = false; isSetAssociateCam2 = false;
	isIdAssigned = false;
}
DynamicAssociation::~DynamicAssociation() {

}

void DynamicAssociation::setParameters(QVector<QList<QPoint> > trapeziumCoordinate, double thresholdAssociationCam1,
                                       double thresholdAssociationCam2, double thresholdOcclusionCam1,
                                       double thresholdOcclusionCam2, double frameRate) {
	cam_1_Processor->setParameters(trapeziumCoordinate[0], thresholdAssociationCam1, thresholdOcclusionCam1);
	cam_2_Processor->setParameters(trapeziumCoordinate[0], thresholdAssociationCam2, thresholdOcclusionCam2);
	kalmanProcessor_1->setParameters(frameRate);
	kalmanProcessor_2->setParameters(frameRate);
}
void DynamicAssociation::getCurrentData(QVector<QList<Player> > currentData) {

	currentDataCam1 = currentData.at(0);
	currentDataCam2 = currentData.at(1);
	QList<Player> temp;
	if (!isIdAssigned) {
		cam_1_Processor->dataCameraAssociation(previousDataCam1, currentDataCam1, predictionDataCam1, 0);
		cam_2_Processor->dataCameraAssociation(previousDataCam2, currentDataCam2, predictionDataCam2, 0);
	} else {
		temp.append(previousDataCam1);
		temp.append(previousDataCam2);
		qDebug() << "Besar data previous untuk diasosiasi: " << previousDataCam1.size() << " " << previousDataCam2.size();
		qDebug() << "Besar data current untuk diasosiasi: " << currentDataCam1.size() << " " << currentDataCam2.size();
		qDebug() << "Besar data prediction untuk diasosiasi: " << predictionDataCam1.size() << " " << previousDataCam2.size();
		qDebug() << "Maksimum id: " << maximumIdOnList(temp);


		cam_1_Processor->dataCameraAssociation(previousDataCam1, currentDataCam1, predictionDataCam1, maximumIdOnList(temp) + 1);
		cam_2_Processor->dataCameraAssociation(previousDataCam2, currentDataCam2, predictionDataCam2, cam_1_Processor->lastID + 1);
	}
	if (isSetNewCam1 && isSetAssociateCam2 && isSetAssociateCam1 && isSetNewCam2) {
		//for display
		dataAggregate.clear();
		dataAggregate.resize(2);
		dataAggregate[0].append(associateData1);
		dataAggregate[1].append(associateData2);
		dataAggregate[0].append(newData1);
		dataAggregate[1].append(newData2);
		emit sendDataAggregate(dataAggregate);

		if (isIdAssigned) {
			//get prediction from kalman filter using associated data
			kalmanProcessor_1->processDataCurrent(dataAggregate[0]);
			kalmanProcessor_2->processDataCurrent(dataAggregate[1]);
			previousDataCam1 = dataAggregate[0];
			previousDataCam2 = dataAggregate[1];
			predictionDataCam1 = kalmanProcessor_1->predictionData;
			predictionDataCam2 = kalmanProcessor_2->predictionData;
		}
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
	////qDebug() << "Size of previous 1: " << associatedDataCam1.size();
	associateData1.append(associatedDataCam1);
	isSetAssociateCam1 = true;
}
void DynamicAssociation::getAssociatedDataCam2(QList<Player>associatedDataCam2) {
	////qDebug() << "Size of previous 2: " << associatedDataCam2.size();
	associateData2.clear();
	associateData2.append(associatedDataCam2);
	isSetAssociateCam2 = true;
}

void DynamicAssociation::processAssignedData(QVector<QList<Player> > assignedData)  {

	isIdAssigned = true;
	kalmanProcessor_1->setInitialData(assignedData.at(0));
	kalmanProcessor_2->setInitialData(assignedData.at(1));
	previousDataCam1.clear();
	previousDataCam2.clear();
	previousDataCam1 = kalmanProcessor_1->previousData;
	previousDataCam2 = kalmanProcessor_2->previousData;
	predictionDataCam1.clear();
	predictionDataCam2.clear();
	predictionDataCam1 = kalmanProcessor_1->predictionData;
	predictionDataCam2 = kalmanProcessor_2->predictionData;;
	qDebug() << "process assigned finished";
}

int DynamicAssociation::maximumIdOnList(QList<Player> listOfPlayer) {
	int max  = listOfPlayer.at(0).id;
	for (int i = 1; i < listOfPlayer.size(); i++) {
		if (listOfPlayer.at(i).id > max) {
			max = listOfPlayer.at(i).id;
		}
	}
	return max;
}
