#include "associate.h"


Associate::Associate(QVector<QList<QPoint> > trapeziumCoordinate, double ThresholdCam1,double ThresholdCam2){
    cameraprocessor1 = new CameraObjectProcessor(trapeziumCoordinate.at(0),ThresholdCam1);
    cameraprocessor2 = new CameraObjectProcessor(trapeziumCoordinate.at(1),ThresholdCam2);
       
    QObject::connect(cameraprocessor1,SIGNAL(updateMatrices(Mat)),this,SIGNAL(updateMatricesCam1(Mat)));
    QObject::connect(cameraprocessor2,SIGNAL(updateMatrices(Mat)),this,SIGNAL(updateMatricesCam2(Mat)));

    QObject::connect(cameraprocessor1,SIGNAL(sendLostFound(QVector<QList<Player> >)),this,SIGNAL(sendLostFoundCam1(QVector<QList<Player> >)));
    QObject::connect(cameraprocessor2,SIGNAL(sendLostFound(QVector<QList<Player> >)),this,SIGNAL(sendLostFoundCam2(QVector<QList<Player> >)));

    QObject::connect(cameraprocessor1,SIGNAL(sendClusterOcclusion(QVector<QList<Player> >)),this,SIGNAL(sendClusterOcclusionCam1(QVector<QList<Player> >)));
    QObject::connect(cameraprocessor2,SIGNAL(sendClusterOcclusion(QVector<QList<Player> >)),this,SIGNAL(sendClusterOcclusionCam2(QVector<QList<Player> >)));
    
    QObject::connect(cameraprocessor1,SIGNAL(sendcleanData(QList<Player>)),this,SIGNAL(sendcleanDataCam1(QList<Player>)));
    QObject::connect(cameraprocessor2,SIGNAL(sendcleanData(QList<Player>)),this,SIGNAL(sendcleanDataCam2(QList<Player>)));

    isSetDataCurrent=false;
    isSetDataPrediction=false;
    isSetDataPrevious=false;

}

Associate::~Associate(){

}

void Associate::getCurrentData(QVector<QList<Player> > currentData){
    if(isSetDataPrevious && isSetDataPrediction){
        currentDataCamera1.clear();
        currentDataCamera2.clear();
        
        currentDataCamera1 = currentData.at(0);
        currentDataCamera2 = currentData.at(1);

        cameraprocessor1->camAssociate(0,currentDataCamera1,predictDataCamera1 , previousDataCamera1);
        cameraprocessor2->camAssociate(currentDataCamera1.length(),currentDataCamera2,predictDataCamera1, previousDataCamera1);
        isSetDataPrediction = false;
        isSetDataPrevious = false;
    }
}

void Associate::getPreviousData(QVector<QList<Player> > previousData){
    previousDataCamera1.clear();    
    previousDataCamera2.clear();

    previousDataCamera1 = previousData.at(0);
    previousDataCamera2 = previousData.at(1);

    isSetDataPrevious=true;
}
void Associate::getPredictionData(QVector<QList<Player> > predictData){
    predictDataCamera1.clear();    
    predictDataCamera2.clear();

    predictDataCamera1 = predictData.at(0);
    predictDataCamera2 = predictData.at(1);
    
    isSetDataPrediction=true;
}
