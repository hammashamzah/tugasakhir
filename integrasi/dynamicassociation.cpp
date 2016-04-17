#include "dynamicassociation.h"

DynamicAssociation::DynamicAssociation(QVector<QList<QPoint> > trapeziumCoordinate, double thresholdAssociationCam1,double thresholdAssociationCam2,double thresholdOcclusionCam1,double thresholdOcclusionCam2, double frameRate){
    cam_1_Processor = new UnitDynamicAssociate(trapeziumCoordinate[0],thresholdAssociationCam1,thresholdOcclusionCam1);
    cam_2_Processor = new UnitDynamicAssociate(trapeziumCoordinate[0],thresholdAssociationCam2,thresholdOcclusionCam2);
    kalmanProcessor_1 = new KalmanDynamic(trapeziumCoordinate[0], frameRate);
    kalmanProcessor_2 = new KalmanDynamic(trapeziumCoordinate[1], frameRate);

    QObject::connect(cam_1_Processor,SIGNAL(sendAssociatedData(QList<Player>)),this,SLOT(getAssociatedDataCam1(QList<Player>)));
    QObject::connect(cam_1_Processor,SIGNAL(sendNewData(QList<Player>)),this,SLOT(getNewDataCam1(QList<Player>)));
    QObject::connect(cam_2_Processor,SIGNAL(sendAssociatedData(QList<Player>)),this,SLOT(getAssociatedDataCam2(QList<Player>)));
    QObject::connect(cam_2_Processor,SIGNAL(sendNewData(QList<Player>)),this,SLOT(getNewDataCam2(QList<Player>)));
	QObject::connect(this, SIGNAL(sendDataAssociatedCamera_1(QList<Player)), kalmanProcessor_1, SLOT(getDataCurr(QList<Player>)));
	QObject::connect(this, SIGNAL(sendDataAssociatedCamera_2(QList<Player)), kalmanProcessor_2, SLOT(getDataCurr(QList<Player>)));
	isSetPreviousData=false;
	isSetPredictionData=false;
	isSetNewCam1=false;isSetNewCam2=false;isSetAssociateCam1=false;isSetAssociateCam2=false;

}
DynamicAssociation::~DynamicAssociation(){

}

void DynamicAssociation::getCurrentData(QVector<QList<Player> > currentData){
        associateData1.clear();
		currentDataCam1 = currentData.at(0);
		currentDataCam2 = currentData.at(1);
        cam_1_Processor->dataCameraAssociation(previousDataCam1,currentDataCam1,predictionDataCam1,(previousDataCam1.length())+(previousDataCam2.length()));
        cam_2_Processor->dataCameraAssociation(previousDataCam2,currentDataCam2,predictionDataCam2,cam_1_Processor->lastID);
        temp1.clear();
        temp1.append(associateData1);
        temp1.append(newData1);
        temp2.clear();
        temp2.append(associateData2);
        temp2.append(newData2);
        emit sendDataAssociatedCamera_1(temp1);
		emit sendDataAssociatedCamera_2(temp2);
		previousDataCam1.clear();
		previousDataCam1 = kalmanProcessor_1->previousData;
		previousDataCam2.clear();
		previousDataCam2 = kalmanProcessor_2->previousData;
		predictionDataCam1.clear();
        predictionDataCam1 = kalmanProcessor_1->predictionData;
		predictionDataCam2.clear();
        predictionDataCam2 = kalmanProcessor_2->predictionData;
		if(isSetNewCam1 && isSetAssociateCam2 && isSetAssociateCam1 && isSetNewCam1){
			dataAggregate.clear();
            dataAggregate.append(associateData1);
            dataAggregate.append(associateData2);
            dataAggregate.append(newData1);
            dataAggregate.append(newData2);
            dataAggregate.append(dataAggregate);
			emit sendDataAgrregate(dataAggregate);
		}
}

void DynamicAssociation::getNewDataCam1(QList<Player> newDataCam1){
	newData1 = newDataCam1;
	isSetNewCam1 = true;
}
void DynamicAssociation::getNewDataCam2(QList<Player> newDataCam2){
	newData2 = newDataCam2;
	isSetNewCam2 = true;
}
void DynamicAssociation::getAssociatedDataCam1(QList<Player>associatedDataCam1){
	associateData1 = associatedDataCam1;
	isSetAssociateCam1 = true;
}
void DynamicAssociation::getAssociatedDataCam2(QList<Player>associatedDataCam2){
	associateData2 = associatedDataCam2;
	isSetAssociateCam2 = true;
}
