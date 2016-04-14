#include "tracking.h"

Tracking::Tracking() {

}

Tracking::~Tracking() {

}

void Tracking::setParameters(int frameRate, QVector<QList<QPoint> > trapeziumCoordinate, QList<double> associationThresholds, QVector<QList<DataInputCam> > playerDataInitial) {
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
    fusion                         = new FusionDataforTrans();

    unifiedInitialObject           = playerDataInitial;

    /**Keluaran generateMatCam**/

    QObject::connect(cameraObjectProcessor_1, SIGNAL(sendLostFound(QList<QList<DataInputCam> >)), this, SIGNAL(SendLostFoundCam1(QList<QList<DataInputCam> >)));
    QObject::connect(cameraObjectProcessor_2,  SIGNAL(sendLostFound(QList<QList<DataInputCam> >)), this, SIGNAL(SendLostFoundCam2(QList<QList<DataInputCam> >)));
    QObject::connect(cameraObjectProcessor_1, SIGNAL(updateMatrices(Mat)), transformedObjectProcessor_1, SLOT(getAssociate(Mat)));
    QObject::connect(cameraObjectProcessor_2, SIGNAL(updateMatrices(Mat)), transformedObjectProcessor_2, SLOT(getAssociate(Mat)));
    QObject::connect(cameraObjectProcessor_1, SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)), associate, SLOT(UpdateOcclusionCam1(QList<QList<DataInputCam>>)));
    QObject::connect(cameraObjectProcessor_2, SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)), associate, SLOT(UpdateOcclusionCam2(QList<QList<DataInputCam>>)));


    /**Hasil transformasi di bypass ke dataseparator**/
    QObject::connect(this, SIGNAL(toDataSeparatorCam_1(QList<QList<DataInputTrans> >)), InputTransform, SLOT(updateDataTrans_1(QList<QList<DataInputTrans> >)));
    QObject::connect(this, SIGNAL(toDataSeparatorCam_2(QList<QList<DataInputTrans> >)), InputTransform, SLOT(updateDataTrans_2(QList<QList<DataInputTrans> >)));

    /**Keluaran Generate mattrans**/
    QObject::connect(transformedObjectProcessor_1, SIGNAL(UpdateAssociate(Mat)), associate, SLOT(updateMatCam1(Mat)));
    QObject::connect(transformedObjectProcessor_2, SIGNAL(UpdateAssociate(Mat)), associate, SLOT(updateMatCam2(Mat)));
    QObject::connect(transformedObjectProcessor_1, SIGNAL(UpdateRemaindedData(QList<int>)), associate, SLOT(remaindedDataCam1(QList<int>)));
    QObject::connect(transformedObjectProcessor_2, SIGNAL(UpdateRemaindedData(QList<int>)), associate, SLOT(remaindedDataCam2(QList<int>)));
    QObject::connect(inputTransform, SIGNAL(sendCamera1(QList<DataInputTrans>)), transformedObjectProcessor_1, SLOT(getDataTrans(QList<DataInputTrans> > )));
    QObject::connect(inputTransform, SIGNAL(sendCamera2(QList<DataInputTrans>)), transformedObjectProcessor_2, SLOT(getDataTrans(QList<DataInputTrans> > )));

    /*keluaran associate menuju kalman */
    QObject::connect(associate, SIGNAL(sendDataFinalCam1(QList<DataInputCam>)), kalmanPredictor_1, SLOT(getDataCurr(QList<DataInputCam>)));
    QObject::connect(associate, SIGNAL(sendDataFinalCam2(QList<DataInputCam>)), kalmanPredictor_2, SLOT(getDataCurr(QList<DataInputCam>)));

    /**Keluaran Object Associate berupa QList of Outlier dan Hasil Mapping dari masingmasing camera**/
    QObject::connect(associate, SIGNAL(sendDataFinal(QList<QList<DataInputCam> >)), this, SIGNAL(SendDataFinal(QList<QList<DataInputCam> >)));
    QObject::connect(associate, SIGNAL(sendDataOutlier(QList<QList<QList<DataInputCam> > >)), this, SIGNAL(sendOutlier(QList<QList<QList<DataInputCam> > >)));

    /** QObject::connect(fusion, SIGNAL(sendDatabeTransformed(QList<QList<DataInputCam> >)), SIGNAL(sendDataQFoundLost(QList<QList<DataInputCam> >)));**/

}

void Tracking::updateDataTransformedCam1(QList<QList<DataInputCam> > TransformCamera1) {

    QList<QList<DataInputCam> > buffer = TransformCamera1;
    emit todataseparatorcam1(buffer);
}

void Tracking::updateDataTransformedCam2(QList<QList<DataInputCam> > TransformCamera2) {

    QList<QList<DataInputCam> > buffer = TransformCamera1;
    emit todataseparatorcam2(buffer);

}

void Tracking::process(int frame) {
    currentFrame = frame;

}

void Tracking::getDataCamera(QVector<QList<DataInputCam> > currentData) {
    data1 = currentData.at(0);
    data2 = currentData.at(1);
    cameraObjectProcessor_1->camAssociate(0, currentFrame, kalmanPredictor_1->predictionData, kalmanPredictor_1->previousData);
    cameraObjectProcessor_2->camAssociate(data1.length(), currentFrame, kalmanPredictor_2->predictionData, kalmanPredictor_2->previousData);
    associate->accum_assoc(data1, data2, associationThresholds[0]);
}

void Tracking::getDataOutlier(QList<QList<DataInputCam> > dataOutlier) {
    inputOutlierCam1 = dataOutlier.at(0);
    inputOutlierCam2 = dataOutlier.at(1);
    kalmanPredictor_1->accum_kalmanobj(unifiedInitialObject[0], inputOutlierCam1, currentFrame);
    kalmanPredictor_2->accum_kalmanobj(unifiedInitialObject[1], inputOutlierCam2, currentFrame);
}




