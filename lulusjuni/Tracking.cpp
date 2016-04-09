#include "Tracking.h"

Tracking::Tracking(int FR,double x_down_left1,double x_down_right1,double x_upper_left1,double x_upper_right1,double y_down_left1,double y_down_right1,double y_upper_left1,double y_upper_right1,double pixel_th1,
                            double x_down_left2,double x_down_right2,double x_upper_left2,double x_upper_right2,double y_down_left2,double y_down_right2,double y_upper_left2,double y_upper_right2,double pixel_th2,
                            double TdataCamera1,double TdataCamera2,mode ops, QList <DataInputCam>Init){
    operate = ops;
    generateCam1 = new GenerateMatCam(1,x_down_left1,x_down_right1,x_upper_left1,x_upper_right1,y_down_left1,y_down_right1,y_upper_left1,y_upper_right1,pixel_th1);
    generateCam2 = new GenerateMatCam(2,x_down_left2,x_down_right2,x_upper_left2,x_upper_right2,y_down_left2,y_down_right2,y_upper_left2,y_upper_right2,pixel_th2);
    generateCamTrans1=new GenerateMatTrans (TdataCamera1);
    generateCamTrans2=new GenerateMatTrans (TdataCamera2);
    kalmancam1  = new Kalmanobj (1,x_down_left1,x_down_right1,x_upper_left1,x_upper_right1,y_down_left1,y_down_right1,y_upper_left1,y_upper_right1,FR);
    kalmancam2  = new Kalmanobj (2,x_down_left2,x_down_right2,x_upper_left2,x_upper_right2,y_down_left2,y_down_right2,y_upper_left2,y_upper_right2,FR);
    Associe     = new Associate (operate);
    flagrun1 = false;
    flagrun2 = false;
    initGab = Init;
    QObject::connect(generateCam1,SIGNAL(updateMatrices(Mat)),generateCamTrans1,SLOT(getAssociate(Mat)));
    QObject::connect(generateCam1,SIGNAL(updateOcclusion(QList<Point>)),Associe,SLOT(getOcclusion1(QList<Point>)));
    QObject::connect(generateCam1,SIGNAL(sendCurrent(QList<DataInputCam>)),Associe,SLOT(updateCurrentCam1(QList<DataInputCam>)));
    QObject::connect(generateCam2,SIGNAL(updateMatrices(Mat)),generateCamTrans2,SLOT(getAssociate(Mat)));
    QObject::connect(generateCam2,SIGNAL(updateOcclusion(QList<Point>)),Associe,SLOT(getOcclusion2(QList<Point>)));
    QObject::connect(generateCam2,SIGNAL(sendCurrent(QList<DataInputCam>)),Associe,SLOT(updateCurrentCam2(QList<DataInputCam>)));
    QObject::connect(generateCamTrans1,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam1(Mat)));
    QObject::connect(generateCamTrans2,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam2(Mat)));
}


Tracking::~Tracking(){

}


void Tracking::requestedCamData(){
    mutex.lock();
    IsReady = true;
    flagrun1 = true;
    flagrun2 = false;
    mutex.unlock();
    emit requestDataCam(IsReady);
}

void Tracking::run1(int Frame,QList<DataInputCam> dataCamera1,QList<DataInputCam>dataCamera2)
{
    IsReady = false;
    finishRun1 = false;
    Frames = Frame;
    generateCam1->cam_associate(0,dataCamera1,Frames,kalmancam1->predictionData,kalmancam1->previousData);
    /**indicatedLostFound1 = generateCam1->indicatedLostFound;
    indicatedLostFound2 = generateCam2->indicatedLostFound;**/
    generateCam2->cam_associate(((dataCamera1.length())),dataCamera2,Frames,kalmancam2->predictionData,kalmancam2->previousData);
    /**indicatedLost2 = generateCam1->indicatedLost;
    indicatedFound2 = generateCam2->indicatedFound;**/
    emit sendDataQFoundLost(indicatedFound1,indicatedLost1,indicatedFound2,indicatedLost2);
    mutex.lock();
    bool runs = flagrun2;
    mutex.unlock();
    while(1){
        if(runs){
            break;
        }
    }
}

void Tracking::run2(QList<DataInputTrans>LostCam1,QList<DataInputTrans>FoundCam1,QList<DataInputTrans>LostCam2,QList<DataInputTrans>FoundCam2)
{
    mutex.lock();
        if(!FoundCam1.empty() || !LostCam1.empty() || !FoundCam2.empty() || !LostCam2.empty()){
           generateCamTrans2->cam_associate(LostCam1,FoundCam2);
           generateCamTrans1->cam_associate(LostCam2,FoundCam1);
        }
        Associe->accum_assoc();
        hasilMapping = Associe->Mapping;
        AsosiasiGlob.release();
        AsosiasiGlob = Associe->association_agrr;
        generateCamTrans2->cam_associate(LostCam2,FoundCam2);
        Associe->accum_assoc();
        hasilMapping.clear();
        hasilMapping = Associe->Mapping;
        AsosiasiGlob.release();
        AsosiasiGlob = Associe->association_agrr;
        emit signalupdateAssociateMat(AsosiasiGlob);
        emit SendHasilMapping(hasilMapping);
        /**Data separator**/
        for(int i=0;i<hasilMapping.length();i++){
           if(hasilMapping.at(i).camera==1){
               inKalman1.append(hasilMapping.at(i));
           }
           else if(hasilMapping.at(i).camera==2){
               inKalman2.append(hasilMapping.at(i));
           }
        }
        kalmancam1->accum_kalmanobj(inKalman1,initGab,Frames);
        kalmancam2->accum_kalmanobj(inKalman2,initGab,Frames);
        inKalman1.clear();
        inKalman2.clear();
        indicatedLost1.clear();
        indicatedFound1.clear();
        indicatedLost2.clear();
        indicatedFound2.clear();
        FoundCam1.clear();
        FoundCam2.clear();
        LostCam1.clear();
        LostCam2.clear();
        mutex.unlock();
}
