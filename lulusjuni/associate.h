#ifndef OBJASSOCIATE_H_INCLUDED
#define OBJASSOCIATE_H_INCLUDED
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include "datainputcam.h"
#include "datainputtrans.h"
#include "objectvariable.h"

using namespace cv;
using namespace std;


class Associate:public QObject
{
    Q_OBJECT
    public:
        int validate;
        Associate();
        ~Associate();
        void accum_assoc(QList<DataInputCam>, QList<DataInputCam>, int);
        Mat association_agrr;
        QList<QList<DataInputCam> > DataFinal;
        double min;

    private:
        bool startAssociate;
        void mapping();
        void AddMat();
        void handlerOutlier();

        QList<DataInputCam>Mapping1;
        QList<DataInputCam>Mapping2;

        QList<QList<DataInputCam> > clusterOccCam1;
        QList<QList<DataInputCam> > clusterOccCam2;
        QList<QList<DataInputCam> > prevClusterOccCam1;
        QList<QList<DataInputCam> > prevClusterOccCam2;


        QList<int> remainData1;
        QList<int> remainData2;

        QList<DataInputCam>cam1;
        QList<DataInputCam>cam2;

        QList <DataInputCam> Outlier1;
        QList <DataInputCam> Outlier2;

        QList<QList<DataInputCam> > ReadyOutlier;
        Mat assoc1;
        Mat assoc2;
        bool IsMatCam1,IsMatCam2,IsOccCam1,IsOccCam2,IsRemainCam1,IsRemainCam2;
   public slots:
        void updateMatCam1(Mat);//from generate MatTrans
        void updateMatCam2(Mat);//from generate MatTrans
        void UpdateOcclusionCam1(QList<QList<DataInputCam> >);//dari generateMatcam
        void UpdateOcclusionCam2(QList<QList<DataInputCam> >);//dari generateMatcam
        void remaindedDataCam1(QList<int>);//dari generateMattrans
        void remaindedDataCam2(QList<int>);//dari generateMattrans
    signals:
        void sendDataFinal(QList<QList<DataInputCam> >);
        void sendDataFinalCam1(QList<DataInputCam>);
        void sendDataFinalCam2(QList<DataInputCam>);
        void sendDataOutlier(QList<QList<DataInputCam> >);
};


#endif // OBJASSOCIATE_H_INCLUDED
