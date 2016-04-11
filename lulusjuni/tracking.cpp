#include "tracking.h"

Tracking::Tracking(int frameRate, QList<QList<QPoint> > trapeziumCoordinate, QList<QList<double> > associationThresholds, QList<DataInputCam> playerDataInitial){}
    cameraObjectProcessor_1        = new CameraObjectProcessor(trapeziumCoordinate[0], associationThresholds[0][0]);
    cameraObjectProcessor_2        = new CameraObjectProcessor(trapeziumCoordinate[1], associationThresholds[1][0]);
    transformedObjectProcessor_1   = new TransformedObjectProcessor(associationThresholds[0][1]);
    transformedObjectProcessor_2   = new TransformedObjectProcessor(associationThresholds[1][1]);
    kalmanPredictor_1              = new KalmanPredictor (trapeziumCoordinate[0],frameRate);
    kalmanPredictor_2              = new KalmanPredictor (trapeziumCoordinate[1],frameRate);
    Associe                        = new Associate(true);
    InputDataCurrent               = new DataSeparatorCam(true);
    InputDataOutlier               = new DataSeparatorCam(true);
    InputTransform                 = new DataSeparator(true);
    fussion                        = new FussionDataforTrans(true);

    initGab             = Init;

    /**Keluaran generateMatCam**/

    QObject::connect(cameraObjectProcessor_1,SIGNAL(sendLostFound(QList<DataInputCam>)),fussion,SLOT(getDataLostFoundCam1(QList<DataInputCam>)));
    QObject::connect(cameraObjectProcessor_2,SIGNAL(sendLostFound(QList<DataInputCam>)),fussion,SLOT(getDataLostFoundCam2(QList<DataInputCam>)));
    QObject::connect(cameraObjectProcessor_1,SIGNAL(updateMatrices(Mat)),transformedObjectProcessor_1,SLOT(getDataTrans(QList<DataInputTrans>)));
    QObject::connect(cameraObjectProcessor_2,SIGNAL(updateMatrices(Mat)),transformedObjectProcessor_2,SLOT(getDataTrans(QList<DataInputTrans>)));
    QObject::connect(cameraObjectProcessor_1,SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)),Associe,SLOT(UpdateOcclusionCam1(QList<QList<DataInputCam>>)));
    QObject::connect(cameraObjectProcessor_2,SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)),Associe,SLOT(UpdateOcclusionCam2(QList<QList<DataInputCam>>)));
    /**Keluaran Generate mattrans**/
    QObject::connect(transformedObjectProcessor_1,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam1(Mat)));
    QObject::connect(transformedObjectProcessor_2,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam2(Mat)));
    QObject::connect(transformedObjectProcessor_1,SIGNAL(UpdateremaindedData(QList<int>)),Associe,SLOT(remaindedDataCam1(QList<int>)));
    QObject::connect(transformedObjectProcessor_2,SIGNAL(UpdateremaindedData(QList<int>)),Associe,SLOT(remaindedDataCam2(QList<int>)));
    /**Keluaran Object Associate berupa QList of Outlier dan Hasil Mapping dari masingmasing camera**/
    QObject::connect(Associe,SIGNAL(sendDataFinal(QList<QList<DataInputCam> >)),this, SIGNAL(SendDataFinal(QList<QList<DataInputCam> >)));
    QObject::connect(fussion,SIGNAL(sendDatabeTransformed(QList<QList<DataInputCam> >)),SIGNAL(sendDataQFoundLost(QList<QList<DataInputCam> >)));

    IssetCurrent = false;IssetOutlier= false;IssetTransform = false;

}


Tracking::~Tracking(){

}

void Tracking::proc_Tracking(int frame){
    currentFrame = frame;
}

void Tracking::GetDataCamera(QList<QList<DataInputCam> > currentData){
    data1 = currentData.at(0);
    data2 = currentData.at(1);
    cameraObjectProcessor_1->camAssociate(0,currentFrame,kalmanPredictor_1->predictionData,kalmanPredictor_1->previousData);
    cameraObjectProcessor_2->camAssociate(data1.length(),Frames,kalmanPredictor_1->predictionData,kalmanPredictor_1->previousData);
    //emit sendDataQFoundLost(fussion->ReadyData);
}

void Tracking::GetDataOutlier(QList<QList<DataInputCam> > dataOutlier){
    InputDataOutlier->getDataTrans(dataOutlier);
    kalmanPredictor_1->accum_kalmanobj(initGab,data1,Frames);
    kalmanPredictor_1->accum_kalmanobj(initGab,data2,Frames);
}

void Tracking::GetTransformedData (QList<QList<DataInputTrans> > DataTransformed){
    InputTransform->getDataTrans(DataTransformed);
    transformedObjectProcessor_1->camAssociate();
    transformedObjectProcessor_2->camAssociate();
    Associe->accum_assoc(data1,data2);
    emit signalupdateAssociateMat(Associe->association_agrr);
    //emit SendDataFinal(Associe->DataFinal);
}


