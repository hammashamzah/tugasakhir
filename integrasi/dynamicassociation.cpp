#include "dynamicassociation.h"

DynamicAssociation::DynamicAssociation() {
	cam_1_Processor = new UnitDynamicAssociate();
	cam_2_Processor = new UnitDynamicAssociate();
	kalmanProcessor_1 = new KalmanDynamic();
	kalmanProcessor_2 = new KalmanDynamic();

	QObject::connect(cam_1_Processor, SIGNAL(sendAssociatedData(QList<Player>)), this, SLOT(getAssociatedDataCam1(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_1_Processor, SIGNAL(sendNewData(QList<Player>)), this, SLOT(getNewDataCam1(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_1_Processor, SIGNAL(sendDataLost(QList<Player>)), this, SLOT(getLostDataCam1(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_2_Processor, SIGNAL(sendAssociatedData(QList<Player>)), this, SLOT(getAssociatedDataCam2(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_2_Processor, SIGNAL(sendNewData(QList<Player>)), this, SLOT(getNewDataCam2(QList<Player>)), Qt::UniqueConnection);
	QObject::connect(cam_2_Processor, SIGNAL(sendDataLost(QList<Player>)), this, SLOT(getLostDataCam1(QList<Player>)), Qt::UniqueConnection);
	
	isSetPreviousData = false;
	isSetPredictionData = false;
	isSetNewCam1 = false; isSetNewCam2 = false; isSetAssociateCam1 = false; isSetAssociateCam2 = false;
	isIdAssigned = false;
}
DynamicAssociation::~DynamicAssociation() {

}

void DynamicAssociation::setParameters(QVector<QList<QPoint> > trapeziumCoordinate, double thresholdAssociationCam1,
                                       double thresholdAssociationCam2, double thresholdOcclusionCam1,
                                       double thresholdOcclusionCam2, float boundaryThreshold1,float boundaryThreshold2,
                                       double frameRate) {
	cam_1_Processor->setParameters(trapeziumCoordinate[0], thresholdAssociationCam1, thresholdOcclusionCam1);
    cam_2_Processor->setParameters(trapeziumCoordinate[1], thresholdAssociationCam2, thresholdOcclusionCam2);
	kalmanProcessor_1->setParameters(frameRate);
	kalmanProcessor_2->setParameters(frameRate);
	boundaryTH1 = boundaryThreshold1;
	boundaryTH2 = boundaryThreshold2;
    qDebug()<<"xo1c1 "<<cam_1_Processor->xo_1<<"yo1c1 "<<cam_1_Processor->yo_1;
    qDebug()<<"xo2c1 "<<cam_1_Processor->xo_2<<"yo2c1 "<<cam_1_Processor->yo_2;
    qDebug()<<"xo1c2 "<<cam_2_Processor->xo_1<<"yo1c2 "<<cam_2_Processor->yo_1;
    qDebug()<<"xo2c2 "<<cam_2_Processor->xo_2<<"yo2c2 "<<cam_2_Processor->yo_2;
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
        //qDebug() << "Besar data previous untuk diasosiasi: " << previousDataCam1.size() << " " << previousDataCam2.size();
        //qDebug() << "Besar data current untuk diasosiasi: " << currentDataCam1.size() << " " << currentDataCam2.size();
        //qDebug() << "Besar data prediction untuk diasosiasi: " << predictionDataCam1.size() << " " << previousDataCam2.size();
        //qDebug() << "Maksimum id: " << maximumIdOnList(temp);
		cam_1_Processor->dataCameraAssociation(previousDataCam1, currentDataCam1, predictionDataCam1, maximumIdOnList(temp) + 1);
		cam_2_Processor->dataCameraAssociation(previousDataCam2, currentDataCam2, predictionDataCam2, cam_1_Processor->lastID + 1);
	}
	if (isSetNewCam1 && isSetAssociateCam2 && isSetAssociateCam1 && isSetNewCam2) {
		//for display
        extractDataLostCam1();
		extractDataLostCam2();

		dataLostFound[0]=lostDataCam2;
        dataLostFound[1]=newData1;
		dataLostFound[2]=lostDataCam1;
        dataLostFound[3]=newData2;
		emit sendDatatobeTransformed(dataLostFound);	
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
void DynamicAssociation::getTransformedData(QVector<QList<Player> > transformedDataLostFound){
	TransformeddataLostFound =transformedDataLostFound;
	boundaryHandler();
	associatesDataLostFound();
	
	if(!associatedIdinBoundaryCam1.isEmpty()){
		for(int i =0;i<associatedIdinBoundaryCam1.size();i++){
			for(int j =0;j<newData1.size();j++){
				if(newData1.at(j).id == associatedIdinBoundaryCam1.at(i).y()){
					indexmatchNewandBoundaryHandlerAssociated  = j;
					break;
				}
			}
            newData1[indexmatchNewandBoundaryHandlerAssociated].id = associatedIdinBoundaryCam1.at(i).x();
		}	
	}
	if(!associatedIdinBoundaryCam2.isEmpty()){
		for(int i =0;i<associatedIdinBoundaryCam2.size();i++){
			for(int j =0;j<newData1.size();j++){
				if(newData2.at(j).id == associatedIdinBoundaryCam2.at(i).y()){
					indexmatchNewandBoundaryHandlerAssociated  = j;
					break;
				}
			}
            newData2[indexmatchNewandBoundaryHandlerAssociated].id = associatedIdinBoundaryCam2.at(i).x();
		}	
	}
	dataAggregate.clear();
	dataAggregate.resize(2);
	dataAggregate[0].append(associateData1);
	dataAggregate[1].append(associateData2);
	dataAggregate[2].append(newData1);
	dataAggregate[3].append(newData2);
	emit sendDataAggregate(dataAggregate);
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
    //////qDebug() << "Size of previous 1: " << associatedDataCam1.size();
	associateData1.append(associatedDataCam1);
	isSetAssociateCam1 = true;
}
void DynamicAssociation::getAssociatedDataCam2(QList<Player>associatedDataCam2) {
    //////qDebug() << "Size of previous 2: " << associatedDataCam2.size();
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
    //qDebug() << "process assigned finished";
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
void DynamicAssociation::extractDataLostCam1(){
	lostDataCam1.clear();
	for(int i=0;i< previousDataCam1.size();i++){
		isMatchPrevioustoAssociated = false;
		for(int j=0;j<associateData1.size();j++){
			if(previousDataCam1.at(i).id==associateData1.at(j).id){
				isMatchPrevioustoAssociated = true;
				break;
			}
		}
		if(!isMatchPrevioustoAssociated){
			lostDataCam1.append(previousDataCam1.at(i));
		}
	}
}

void DynamicAssociation::extractDataLostCam2(){
	lostDataCam2.clear();
	for(int i=0;i< previousDataCam2.size();i++){
		isMatchPrevioustoAssociated = false;
		for(int j=0;j<associateData2.size();j++){
			if(previousDataCam2.at(i).id==associateData2.at(j).id){
				isMatchPrevioustoAssociated = true;
				break;
			}
		}
		if(!isMatchPrevioustoAssociated){
			lostDataCam2.append(previousDataCam2.at(i));
		}
	}
}



void DynamicAssociation::boundaryHandler(){
	for(int i=0;i<4;i++){
		if(!TransformeddataLostFound[i].isEmpty()){
            for(int j=0;j<(TransformeddataLostFound[i].size())&&(!TransformeddataLostFound[i].isEmpty());j++){
                if((TransformeddataLostFound[i].at(j).transformedPos.x < boundaryTH1)||(TransformeddataLostFound[i].at(j).transformedPos.x > boundaryTH2)){
                    TransformeddataLostFound[i].removeAt(j);
				}
			}
		}
	}
}

void DynamicAssociation::associatesDataLostFound(){
    associatedIdinBoundaryCam1.clear();
    if((!TransformeddataLostFound.at(0).isEmpty())&&(!TransformeddataLostFound.at(1).isEmpty())){
		for(int i =0;i<TransformeddataLostFound[1].size();i++){
			minimum_distance = sqrt((((TransformeddataLostFound.at(0).at(i).transformedPos.x)-(TransformeddataLostFound.at(1).at(0).transformedPos.x))*((TransformeddataLostFound.at(0).at(i).transformedPos.x)-(TransformeddataLostFound.at(1).at(0).transformedPos.x)))+(((TransformeddataLostFound.at(0).at(i).transformedPos.y)-(TransformeddataLostFound.at(1).at(0).transformedPos.y))*((TransformeddataLostFound.at(0).at(i).transformedPos.y)-(TransformeddataLostFound.at(1).at(0).transformedPos.y))));
            for(int j =0;j<TransformeddataLostFound[0].size();j++){
				minimum_distanceCompare =sqrt((((TransformeddataLostFound.at(0).at(i).transformedPos.x)-(TransformeddataLostFound.at(1).at(j).transformedPos.x))*((TransformeddataLostFound.at(0).at(i).transformedPos.x)-(TransformeddataLostFound.at(1).at(j).transformedPos.x)))+(((TransformeddataLostFound.at(0).at(i).transformedPos.y)-(TransformeddataLostFound.at(1).at(j).transformedPos.y))*((TransformeddataLostFound.at(0).at(i).transformedPos.y)-(TransformeddataLostFound.at(1).at(j).transformedPos.y))));
                if(minimum_distanceCompare  <= minimum_distance){
					associatedIdinBoundaryCam1.append(QPoint(TransformeddataLostFound.at(0).at(j).id,TransformeddataLostFound.at(1).at(j).id));
				}
			}
		}
	}
	associatedIdinBoundaryCam2.clear();
	if((!TransformeddataLostFound[2].isEmpty())&&(!TransformeddataLostFound[3].isEmpty())){
		for(int i =0;i<TransformeddataLostFound[3].size();i++){
			minimum_distance = sqrt((((TransformeddataLostFound.at(2).at(i).transformedPos.x)-(TransformeddataLostFound.at(3).at(0).transformedPos.x))*((TransformeddataLostFound.at(2).at(i).transformedPos.x)-(TransformeddataLostFound.at(3).at(0).transformedPos.x)))+(((TransformeddataLostFound.at(2).at(i).transformedPos.y)-(TransformeddataLostFound.at(3).at(0).transformedPos.y))*((TransformeddataLostFound.at(2).at(i).transformedPos.y)-(TransformeddataLostFound.at(3).at(0).transformedPos.y))));
            for(int j =0;j<TransformeddataLostFound[2].size();j++){
				minimum_distanceCompare =sqrt((((TransformeddataLostFound.at(2).at(i).transformedPos.x)-(TransformeddataLostFound.at(3).at(j).transformedPos.x))*((TransformeddataLostFound.at(2).at(i).transformedPos.x)-(TransformeddataLostFound.at(3).at(j).transformedPos.x)))+(((TransformeddataLostFound.at(2).at(i).transformedPos.y)-(TransformeddataLostFound.at(3).at(j).transformedPos.y))*((TransformeddataLostFound.at(2).at(i).transformedPos.y)-(TransformeddataLostFound.at(3).at(j).transformedPos.y))));
                if(minimum_distanceCompare  <= minimum_distance){
					associatedIdinBoundaryCam2.append(QPoint(TransformeddataLostFound.at(2).at(j).id,TransformeddataLostFound.at(3).at(j).id));
				}
			}
		}
	}
}
