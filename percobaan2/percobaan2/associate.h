#ifndef OBJASSOCIATE_H_INCLUDED
#define OBJASSOCIATE_H_INCLUDED
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <QList>
#include <QObject>
#include <QPoint>
#include "kalmanpredictor.h"
#include "player.h"
#include "cameraobjectprocessor.h"

using namespace cv;
using namespace std;


class Associate:public QObject
{
    Q_OBJECT
    public:
        CameraObjectProcessor *cameraprocessor1;
        CameraObjectProcessor *cameraprocessor2;

        Associate(QList<QList<QPoint> >, double ThresholdCam1,double ThresholdCam2);
        ~Associate();
        
    private:
        QList<Player> currentDataCamera1;
        QList<Player> currentDataCamera2;
        
        QList<Player> previousDataCamera1;
        QList<Player> previousDataCamera2;
        
        QList<Player> predictDataCamera1;
        QList<Player> predictDataCamera2;

        bool isSetDataCurrent,isSetDataPrediction,isSetDataPrevious;        
    public slots:
        void getCurrentData(QVector<QList<Player> >);
        void getPreviousData(QVector<QList<Player> >);
        void getPredictionData(QVector<QList<Player> >);
    signals:
        void sendCleanData(QVector<QList<Player> >);
        //void sendLostFoundData(QList<QList<QList<Player> > >);
};

#endif // OBJASSOCIATE_H_INCLUDED
