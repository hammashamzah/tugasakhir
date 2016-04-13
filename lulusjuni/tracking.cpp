#include "tracking.h"

Tracking::Tracking(int frameRate, QVector<QList<QPoint> > trapeziumCoordinate, QList<double> associationThresholds, QList<DataInputCam> playerDataInitial) {
    cameraObjectProcessor_1        = new CameraObjectProcessor(trapeziumCoordinate[0], associationThresholds[0]);
    cameraObjectProcessor_2        = new CameraObjectProcessor(trapeziumCoordinate[1], associationThresholds[1]);
    transformedObjectProcessor_1   = new TransformedObjectProcessor(associationThresholds[2]);
    transformedObjectProcessor_2   = new TransformedObjectProcessor(associationThresholds[3]);
    kalmanPredictor_1              = new KalmanPredictor (trapeziumCoordinate[0], frameRate);
    kalmanPredictor_2              = new KalmanPredictor (trapeziumCoordinate[1], frameRate);
    associate                      = new Associate();
    InputDataCurrent               = new DataSeparatorCam();
    InputDataOutlier               = new DataSeparatorCam();
    InputTransform                 = new DataSeparator();
    fusion                        = new FusionDataforTrans();

    unifiedInitialObject           = playerDataInitial;

    /**Keluaran generateMatCam**/

    QObject::connect(cameraObjectProcessor_1, SIGNAL(sendLostFound(QList<DataInputCam>)), fusion, SLOT(getDataLostFoundCam1(QList<DataInputCam>)));
    QObject::connect(cameraObjectProcessor_2, SIGNAL(sendLostFound(QList<DataInputCam>)), fusion, SLOT(getDataLostFoundCam2(QList<DataInputCam>)));
    QObject::connect(cameraObjectProcessor_1, SIGNAL(updateMatrices(Mat)), transformedObjectProcessor_1, SLOT(getAssociate(Mat)));
    QObject::connect(cameraObjectProcessor_2, SIGNAL(updateMatrices(Mat)), transformedObjectProcessor_2, SLOT(getAssociate(Mat)));
    QObject::connect(cameraObjectProcessor_1, SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)), associate, SLOT(UpdateOcclusionCam1(QList<QList<DataInputCam>>)));
    QObject::connect(cameraObjectProcessor_2, SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)), associate, SLOT(UpdateOcclusionCam2(QList<QList<DataInputCam>>)));

    /**Keluaran Generate mattrans**/
    QObject::connect(transformedObjectProcessor_1, SIGNAL(UpdateAssociate(Mat)), associate, SLOT(updateMatCam1(Mat)));
    QObject::connect(transformedObjectProcessor_2, SIGNAL(UpdateAssociate(Mat)), associate, SLOT(updateMatCam2(Mat)));
    QObject::connect(transformedObjectProcessor_1, SIGNAL(UpdateRemaindedData(QList<int>)), associate, SLOT(remaindedDataCam1(QList<int>)));
    QObject::connect(transformedObjectProcessor_2, SIGNAL(UpdateRemaindedData(QList<int>)), associate, SLOT(remaindedDataCam2(QList<int>)));

    /**Keluaran Object Associate berupa QList of Outlier dan Hasil Mapping dari masingmasing camera**/
    QObject::connect(associate, SIGNAL(sendDataFinal(QList<QList<DataInputCam> >)), this, SIGNAL(SendDataFinal(QList<QList<DataInputCam> >)));
    QObject::connect(fusion, SIGNAL(sendDatabeTransformed(QList<QList<DataInputCam> >)), SIGNAL(sendDataQFoundLost(QList<QList<DataInputCam> >)));

    IssetCurrent = false; IssetOutlier = false; IssetTransform = false;

}


Tracking::~Tracking() {

}

void Tracking::process(int frame) {
    currentFrame = frame;
}

void Tracking::getDataCamera(QVector<QList<DataInputCam> > currentData) {
    data1 = currentData.at(0);
    data2 = currentData.at(1);
    cameraObjectProcessor_1->camAssociate(0, currentFrame, kalmanPredictor_1->predictionData, kalmanPredictor_1->previousData);
    cameraObjectProcessor_2->camAssociate(data1.length(), currentFrame, kalmanPredictor_2->predictionData, kalmanPredictor_2->previousData);
    //emit sendDataQFoundLost(fusion->ReadyData);
}

void Tracking::getDataOutlier(QList<QList<DataInputCam> > dataOutlier) {
    InputDataOutlier->getDataTrans(dataOutlier);
    kalmanPredictor_1->accum_kalmanobj(, data1, Frames);
    kalmanPredictor_2->accum_kalmanobj(unifiedInitialObject, data2, Frames);
}

void Tracking::getTransformedData (QList<QList<DataInputTrans> > DataTransformed) {
    InputTransform->getDataTrans(DataTransformed);
    transformedObjectProcessor_1->camAssociate();
    transformedObjectProcessor_2->camAssociate();
    associate->accum_assoc(data1, data2);
    emit signalupdateAssociateMat(associate->association_agrr);
    //emit SendDataFinal(associate->DataFinal);
}


