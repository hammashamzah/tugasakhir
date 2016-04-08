#include "Highlevel.h"


HighLevel::HighLevel(double FR,double xdl1,double xdr1,double xul1,double xur1,double ydl1,double ydr1,double yul1,double yur1,double pixel_th1,
                            double xdl2,double xdr2,double xul2,double xur2,double ydl2,double ydr2,double yul2,double yur2,double pixel_th2,
                            double xdl3,double xdr3,double xul3,double xur3,double ydl3,double ydr3,double yul3,double yur3,double pixel_th3,
                            double TdataCamera1,double TdataCamera2,double TdataCamera3,mode ops){
    operate = ops;
    generateCam1 = new GenerateMatCam(1,xdl1,xdr1,xul1,xur1,ydl1,ydr1,yul1,yur1,pixel_th1);
    generateCam2 = new GenerateMatCam(2,xdl2,xdr2,xul2,xur2,ydl2,ydr2,yul2,yur2,pixel_th2);
    generateCam3 = new GenerateMatCam (3,xdl3,xdr3,xul3,xur3,ydl3,ydr3,yul3,yur3,pixel_th3);
    generateCamTrans1=new GenerateMatTrans (TdataCamera1);
    generateCamTrans2=new GenerateMatTrans (TdataCamera2);
    generateCamTrans3=new GenerateMatTrans (TdataCamera3);
    kalmancam1  = new Kalmanobj (1,xdl1,xdr1,xul1,xur1,ydl1,ydr1,yul1,yur1,FR);
    kalmancam2  = new Kalmanobj (2,xdl2,xdr2,xul2,xur2,ydl2,ydr2,yul2,yur2,FR);
    kalmancam3  = new Kalmanobj (3,xdl2,xdr2,xul2,xur2,ydl2,ydr2,yul2,yur2,FR);
    Associe     = new Associate (operate);
    flagrun1 = false;
    flagrun2 = false;

    QObject::connect(generateCam1,SIGNAL(updateMatrices(Mat)),generateCamTrans1,SLOT(getAssociate(Mat)));
    QObject::connect(generateCam1,SIGNAL(updateOcclusion(QList<Point>)),Associe,SLOT(getOcclusion1(QList<Point>)));
    QObject::connect(generateCam1,SIGNAL(sendCurrent(QList<DataInputCam>)),Associe,SLOT(updateCurrentCam1(QList<DataInputCam>)));
    QObject::connect(generateCam2,SIGNAL(updateMatrices(Mat)),generateCamTrans2,SLOT(getAssociate(Mat)));
    QObject::connect(generateCam2,SIGNAL(updateOcclusion(QList<Point>)),Associe,SLOT(getOcclusion2(QList<Point>)));
    QObject::connect(generateCam2,SIGNAL(sendCurrent(QList<DataInputCam>)),Associe,SLOT(updateCurrentCam2(QList<DataInputCam>)));
    QObject::connect(generateCam3,SIGNAL(updateMatrices(Mat)),generateCamTrans2,SLOT(getAssociate(Mat)));
    QObject::connect(generateCam3,SIGNAL(updateOcclusion(QList<Point>)),Associe,SLOT(getOcclusion3(QList<Point>)));
    QObject::connect(generateCam3,SIGNAL(sendCurrent(QList<DataInputCam>)),Associe,SLOT(updateCurrentCam3(QList<DataInputCam>)));
    QObject::connect(generateCamTrans1,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam1(Mat)));
    QObject::connect(generateCamTrans2,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam2(Mat)));
    QObject::connect(generateCamTrans3,SIGNAL(UpdateAssociate(Mat)),Associe,SLOT(updateMatCam3(Mat)));
}


HighLevel::~HighLevel(){

}


void HighLevel::requestedCamData(){
    mutex.lock();
    IsReady = true;
    flagrun1 = true;
    flagrun2 = false;
    mutex.unlock();
    emit requestDataCam(IsReady);
}

void HighLevel::run1(QList<DataInputCam> dataCamera1,QList<DataInputCam>dataCamera2,QList<DataInputCam>dataCamera3)
{
    IsReady = false;
    finishRun1 = false;
    if(Frames == 1){
        DataInputCam buffer;
        for(int i=0;i<((dataCamera1.length())+(dataCamera1.length())+(dataCamera1.length()));i++){
            if(i<dataCamera1.length()){

                buffer.id = i;
                buffer.dataplayer.x = dataCamera1.at(i).dataplayer.x;
                buffer.dataplayer.y = dataCamera1.at(i).dataplayer.y;
                buffer.dataplayer.width = dataCamera1.at(i).dataplayer.width;
                buffer.dataplayer.height = dataCamera1.at(i).dataplayer.height;
                buffer.flagOcclusion = dataCamera1.at(i).flagOcclusion;
                buffer.status = dataCamera1.at(i).status;
                buffer.pixelSpeed.x = dataCamera1.at(i).pixelSpeed.x;
                buffer.pixelSpeed.y = dataCamera1.at(i).pixelSpeed.y;
            }
            else if((i>=dataCamera1.length())&&(i<dataCamera1.length()+dataCamera2.length())){
                buffer.id = i;
                buffer.dataplayer.x = dataCamera2.at(i).dataplayer.x;
                buffer.dataplayer.y = dataCamera2.at(i).dataplayer.y;
                buffer.dataplayer.width = dataCamera2.at(i).dataplayer.width;
                buffer.dataplayer.height = dataCamera2.at(i).dataplayer.height;
                buffer.flagOcclusion = dataCamera2.at(i).flagOcclusion;
                buffer.status = dataCamera2.at(i).status;
                buffer.pixelSpeed.x = dataCamera2.at(i).pixelSpeed.x;
                buffer.pixelSpeed.y = dataCamera2.at(i).pixelSpeed.y;
            }
            else{
                buffer.id = i;
                buffer.dataplayer.x = dataCamera3.at(i).dataplayer.x;
                buffer.dataplayer.y = dataCamera3.at(i).dataplayer.y;
                buffer.dataplayer.width = dataCamera3.at(i).dataplayer.width;
                buffer.dataplayer.height = dataCamera3.at(i).dataplayer.height;
                buffer.flagOcclusion = dataCamera3.at(i).flagOcclusion;
                buffer.status = dataCamera3.at(i).status;
                buffer.pixelSpeed.x = dataCamera3.at(i).pixelSpeed.x;
                buffer.pixelSpeed.y = dataCamera3.at(i).pixelSpeed.y;
            }
            initGab.append(buffer);
        }
    }
    switch(operate){
            case(singel):{
                    generateCam1->cam_associate(0,dataCamera1,Frames,kalmancam1->predictionData,kalmancam1->previousData);
                    indicatedLost1 = generateCam1->indicatedLost;
                    indicatedFound1 = generateCam1->indicatedFound;
                    break;
            }
            case(dual):{
                    generateCam1->cam_associate(0,dataCamera1,Frames,kalmancam1->predictionData,kalmancam1->previousData);
                    indicatedLost1 = generateCam1->indicatedLost;
                    indicatedFound1 = generateCam1->indicatedFound;
                    generateCam2->cam_associate(((dataCamera1.length())),dataCamera2,Frames,kalmancam2->predictionData,kalmancam2->previousData);
                    indicatedLost2 = generateCam1->indicatedLost;
                    indicatedFound2 = generateCam2->indicatedFound;
                    break;
            }
            case(triple):{
                    generateCam1->cam_associate(0,dataCamera1,Frames,kalmancam1->predictionData,kalmancam1->previousData);
                    indicatedLost1 = generateCam1->indicatedLost;
                    indicatedFound1 = generateCam1->indicatedFound;
                    generateCam2->cam_associate(((dataCamera1.length())),dataCamera2,Frames,kalmancam2->predictionData,kalmancam2->previousData);
                    indicatedLost2 = generateCam1->indicatedLost;
                    indicatedFound2 = generateCam2->indicatedFound;
                    generateCam3->cam_associate(((dataCamera1.length())+(dataCamera2.length())),dataCamera3,Frames,kalmancam3->predictionData,kalmancam3->previousData);
                    indicatedLost3 = generateCam3->indicatedLost;
                    indicatedFound3 = generateCam3->indicatedFound;
                    break;
            }
        }
    finishRun1 = true;
    emit sendDataQFoundLost(indicatedFound1,indicatedLost1,indicatedFound2,indicatedLost2,indicatedFound3,indicatedLost3);
    emit sendFlagGetLostFoundData(finishRun1);
    mutex.lock();
    bool runs = flagrun2;
    mutex.unlock();
    while(1){
        if(runs){
            break;
        }
    }
    QThread::wait(1000);
}

void HighLevel::run2(QList<DataInputTrans>LostCam1,QList<DataInputTrans>FoundCam1,QList<DataInputTrans>LostCam2,QList<DataInputTrans>FoundCam2,QList<DataInputTrans>LostCam3,QList<DataInputTrans>FoundCam3)
{
    mutex.lock();
    if(flagrun1){
        flagrun2 = true;
        switch(operate){
                case(singel):{
                            if(!FoundCam1.empty() || !LostCam1.empty()){
                                generateCamTrans1->cam_associate(LostCam1,FoundCam1);
                            }
                            Associe->accum_assoc();
                            hasilMapping = Associe->Mapping;
                            AsosiasiGlob.release();
                            AsosiasiGlob = Associe->association_agrr;
                            emit signalupdateAssociateMat(AsosiasiGlob);
                            for(int i=0;i<hasilMapping.length();i++){
                                if(hasilMapping.at(i).camera==1){
                                    inKalman1.append(hasilMapping.at(i));
                                }
                                else if(hasilMapping.at(i).camera==2){
                                    inKalman2.append(hasilMapping.at(i));
                                }
                                else if(hasilMapping.at(i).camera==3){
                                    inKalman3.append(hasilMapping.at(i));
                                }
                            }
                            kalmancam1->accum_kalmanobj(inKalman1,initGab,Frames);
                        break;
                }
                case(dual):{
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
                        hasilMapping = Associe->Mapping;
                        AsosiasiGlob.release();
                        AsosiasiGlob = Associe->association_agrr;
                        emit signalupdateAssociateMat(AsosiasiGlob);
                        for(int i=0;i<hasilMapping.length();i++){
                            if(hasilMapping.at(i).camera==1){
                                inKalman1.append(hasilMapping.at(i));
                            }
                            else if(hasilMapping.at(i).camera==2){
                                inKalman2.append(hasilMapping.at(i));
                            }
                            else if(hasilMapping.at(i).camera==3){
                                inKalman3.append(hasilMapping.at(i));
                            }
                        }
                        kalmancam1->accum_kalmanobj(inKalman1,initGab,Frames);
                        kalmancam2->accum_kalmanobj(inKalman2,initGab,Frames);
                        break;
                }
                case(triple):{
                    if(!FoundCam1.empty() || !LostCam1.empty() || !FoundCam2.empty() || !LostCam2.empty() || !FoundCam3.empty() || !LostCam3.empty()){
                        generateCamTrans2->cam_associate(LostCam1,FoundCam2);
                        generateCamTrans1->cam_associate(LostCam2,FoundCam1);
                        generateCamTrans2->cam_associate(LostCam2,FoundCam3);
                        generateCamTrans3->cam_associate(LostCam3,FoundCam2);
                    }
                    Associe->accum_assoc();
                    hasilMapping = Associe->Mapping;
                    AsosiasiGlob.release();
                    AsosiasiGlob = Associe->association_agrr;
                    emit signalupdateAssociateMat(AsosiasiGlob);
                    for(int i=0;i<hasilMapping.length();i++){
                        if(hasilMapping.at(i).camera==1){
                            inKalman1.append(hasilMapping.at(i));
                        }
                        else if(hasilMapping.at(i).camera==2){
                            inKalman2.append(hasilMapping.at(i));
                        }
                        else if(hasilMapping.at(i).camera==3){
                            inKalman3.append(hasilMapping.at(i));
                        }
                    }
                    kalmancam1->accum_kalmanobj(inKalman1,initGab,Frames);
                    kalmancam2->accum_kalmanobj(inKalman2,initGab,Frames);
                    kalmancam3->accum_kalmanobj(inKalman3,initGab,Frames);
                        break;
                }
            }
        hasilMapping.clear();
        inKalman1.clear();
        inKalman2.clear();
        inKalman3.clear();
        indicatedLost1.clear();
        indicatedFound1.clear();
        indicatedLost2.clear();
        indicatedFound2.clear();
        indicatedLost3.clear();
        indicatedFound3.clear();
        FoundCam1.clear();
        FoundCam2.clear();
        FoundCam3.clear();
        LostCam1.clear();
        LostCam2.clear();
        LostCam3.clear();
    }
    mutex.unlock();
}
