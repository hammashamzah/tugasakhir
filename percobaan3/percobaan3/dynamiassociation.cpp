#include "dynamiassociation.h"

DynamiAssociation::DynamiAssociation(QVector<QList<QPoint> > trapeziumCoordinate, double thresholdAssociationCam1,double thresholdAssociationCam2,double thresholdOcclusionCam1,double thresholdOcclusionCam2){
    cam_1_Processor = new 	UnitDynamicAssociate(trapeziumCoordinate[0],thresholdAssociationCam1,thresholdOcclusionCam1);
    cam_2_Processor = new 	UnitDynamicAssociate(trapeziumCoordinate[0],thresholdAssociationCam2,thresholdOcclusionCam2);
    QObject::connect(cam_1_Processor,SIGNAL(sendAssociatedData(QList<Player>)),this,SLOT(getAssociatedDataCam1(QList<Player>)));
    QObject::connect(cam_1_Processor,SIGNAL(sendNewData(QList<Player>)),this,SLOT(getNewDataCam1(QList<Player>)));
    QObject::connect(cam_2_Processor,SIGNAL(sendAssociatedData(QList<Player>)),this,SLOT(getAssociatedDataCam2(QList<Player>)));
    QObject::connect(cam_2_Processor,SIGNAL(sendNewData(QList<Player>)),this,SLOT(getNewDataCam2(QList<Player>)));
	isSetPreviousData=false;
	isSetPredictionData=false;
	isSetNewCam1=false;isSetNewCam2=false;isSetAssociateCam1=false;isSetAssociateCam2=false;
}
DynamiAssociation::~DynamiAssociation(){

}
void DynamiAssociation::getPreviousData(QVector<QList<Player> > previous){
	previousDataCam1 = previous.at(0);
	previousDataCam2 = previous.at(1);
	isSetPreviousData = true;		
}
void DynamiAssociation::getCurrentData(QVector<QList<Player> > currentData){
	if(isSetPredictionData && isSetPreviousData){
		currentDataCam1 = currentData.at(0);
		currentDataCam2 = currentData.at(1);
        cam_1_Processor->dataCameraAssociation(previousDataCam1,currentDataCam1,predictionDataCam1,(previousDataCam1.length())+(previousDataCam2.length()));
        cam_2_Processor->dataCameraAssociation(previousDataCam2,currentDataCam2,predictionDataCam2,cam_1_Processor->lastID);
		if(isSetNewCam1 && isSetAssociateCam2 && isSetAssociateCam1 && isSetNewCam1){
			dataAggregate.append(associateData1);
			dataAggregate.append(associateData2);
			dataAggregate.append(newData1);
			dataAggregate.append(newData2);
			emit sendDataAgrregate(dataAggregate);
		}
	}
}
void DynamiAssociation::getPredictionData(QVector<QList<Player> > prediction){
	predictionDataCam1 = prediction.at(0); 
	predictionDataCam2 = prediction.at(1);
	isSetPredictionData = true;
}

void DynamiAssociation::getNewDataCam1(QList<Player> newDataCam1){
	newData1 = newDataCam1;
	isSetNewCam1 = true;
}
void DynamiAssociation::getNewDataCam2(QList<Player> newDataCam2){
	newData2 = newDataCam2;
	isSetNewCam2 = true;
}
void DynamiAssociation::getAssociatedDataCam1(QList<Player>associatedDataCam1){
	associateData1 = associatedDataCam1;
	isSetAssociateCam1 = true;
}
void DynamiAssociation::getAssociatedDataCam2(QList<Player>associatedDataCam2){
	associateData2 = associatedDataCam2;
	isSetAssociateCam2 = true;
}
