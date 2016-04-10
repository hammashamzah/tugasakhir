#include "Tracking.h"

Tracking::        Tracking(int FR,double x_down_left1,double x_down_right1,double x_upper_left1,double x_upper_right1,double y_down_left1,double y_down_right1,double y_upper_left1,double y_upper_right1,double pixel_th1,
                           double x_down_left2,double x_down_right2,double x_upper_left2,double x_upper_right2,double y_down_left2,double y_down_right2,double y_upper_left2,double y_upper_right2,double pixel_th2,
                           double TdataCamera1,double TdataCamera2, QList <DataInputCam>Init){

    generateCam1        = new GenerateMatCam(1,x_down_left1,x_down_right1,x_upper_left1,x_upper_right1,y_down_left1,y_down_right1,y_upper_left1,y_upper_right1,pixel_th1);
    generateCam2        = new GenerateMatCam(2,x_down_left2,x_down_right2,x_upper_left2,x_upper_right2,y_down_left2,y_down_right2,y_upper_left2,y_upper_right2,pixel_th2);
    generateCamTrans1   = new GenerateMatTrans (TdataCamera1);
    generateCamTrans2   = new GenerateMatTrans (TdataCamera2);
    kalmancam1          = new Kalmanobj (x_down_left1,x_down_right1,x_upper_left1,x_upper_right1,y_down_left1,y_down_right1,y_upper_left1,y_upper_right1,FR);
    kalmancam2          = new Kalmanobj (x_down_left2,x_down_right2,x_upper_left2,x_upper_right2,y_down_left2,y_down_right2,y_upper_left2,y_upper_right2,FR);
    Associe             = new Associate(true);

    thread1 = new QThread();
    thread2 = new QThread();
    thread3 = new QThread();

    InputDataCurrent    = new DataSeparatorCam(true);
    InputDataOutlier    = new DataSeparatorCam(true);
    InputTransform      = new DataSeparator(true);
    fussion             = new FussionDataforTrans(true);

    initGab             = Init;

    InputDataCurrent->moveToThread(thread1);
    InputTransform->moveToThread(thread2);
    InputDataOutlier->moveToThread(thread3);

    /**Keluaran generateMatCam**/

    QObject::connect(generateCam1,SIGNAL(sendLostFound(QList<DataInputCam>)),fussion,SLOT(getDataLostFoundCam1(QList<DataInputCam>)));
    QObject::connect(generateCam2,SIGNAL(sendLostFound(QList<DataInputCam>)),fussion,SLOT(getDataLostFoundCam2(QList<DataInputCam>)));
    QObject::connect(generateCam1,SIGNAL(updateMatrices(Mat)),generateCamTrans1,SLOT(getDataTrans(QList<DataInputTrans>)));
    QObject::connect(generateCam2,SIGNAL(updateMatrices(Mat)),generateCamTrans2,SLOT(getDataTrans(QList<DataInputTrans>)));
    QObject::connect(generateCam1,SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)),Associe,SLOT(UpdateOcclusionCam1(QList<QList<DataInputCam>>)));
    QObject::connect(generateCam2,SIGNAL(sendOcclusion(QList<QList<DataInputCam> >)),Associe,SLOT(UpdateOcclusionCam2(QList<QList<DataInputCam>>)));
    /**Keluaran Generate mattrans**/
    QObject::connect(generateCamTrans1,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam1(Mat)));
    QObject::connect(generateCamTrans2,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam2(Mat)));
    QObject::connect(generateCamTrans1,SIGNAL(UpdateremaindedData(QList<int>)),Associe,SLOT(remaindedDataCam1(QList<int>)));
    QObject::connect(generateCamTrans2,SIGNAL(UpdateremaindedData(QList<int>)),Associe,SLOT(remaindedDataCam2(QList<int>)));
    /**Keluaran Object Associate berupa QLIST of Outlier dan Hasil Mapping dari masingmasing camera**/
    QObject::connect(Associe,SIGNAL(sendDataFinal(QList<QList<DataInputCam> >)),SIGNAL(SendDataFinal(QList<QList<DataInputCam> >)));
    QObject::connect(fussion,SIGNAL(sendDatabeTransformed(QList<QList<DataInputCam> >)),SIGNAL(sendDataQFoundLost(QList<QList<DataInputCam> >)));

    IssetCurrent = false;IssetOutlier= false;IssetTransform = false;

}


Tracking::~Tracking(){

}

void Tracking::proc_Tracking(int Frame){
    Frames = Frame;
}

void Tracking::GetDataCamera(QList<QList<DataInputCam> > dataCurrent){
    InputDataCurrent->getDataTrans(dataCurrent);
    data1 = dataCurrent.at(0);
    data2 = dataCurrent.at(1);
    generateCam1->cam_associate(0,Frames,kalmancam1->predictionData,kalmancam1->previousData);
    generateCam2->cam_associate(data1.length(),Frames,kalmancam1->predictionData,kalmancam1->previousData);
    emit sendDataQFoundLost(fussion->ReadyData);
}

void Tracking::GetDataOutlier(QList<QList<DataInputCam> > dataOutlier){
    InputDataOutlier->getDataTrans(dataOutlier);
    kalmancam1->accum_kalmanobj(initGab,data1,Frames);
    kalmancam1->accum_kalmanobj(initGab,data2,Frames);
}

void Tracking::GetTransformedData (QList<QList<DataInputTrans> > DataTransformed){
    InputTransform->getDataTrans(DataTransformed);
    generateCamTrans1->cam_associate();
    generateCamTrans2->cam_associate();
    Associe->accum_assoc(data1,data2);
    emit signalupdateAssociateMat(Associe->association_agrr);
    emit SendDataFinal(Associe->DataFinal);
}


