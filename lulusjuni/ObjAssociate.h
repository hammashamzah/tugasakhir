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
        explicit Associate (QObject *parent = 0);
        int validate;
        Associate();
        ~Associate();
        void accum_assoc(QList<DataInputCam>,QList<DataInputCam>);
        Mat association_agrr;
        QList<DataInputCam>Mapping;

        QList<QList<DataInputCam>> clusterOccCam1;
        QList<QList<DataInputCam>> clusterOccCam2;
        QList<QList<DataInputCam>> prevClusterOccCam1;
        QList<QList<DataInputCam>> prevClusterOccCam2;

        QList<int> remainData1;
        QList<int> remainData2;

    private:
        void mapping();
        void AddMat();
        void handlerOutlier();
        QList<DataInputCam>cam1;
        QList<DataInputCam>cam2;

        QList<int> posibleId_newclustercam1;
        QList<int> posibleId_newclustercam2;

        Mat assoc1;
        Mat assoc2;
        bool IsMatCam1,IsMatCam2,IsOccCam1,IsOccCam2,IsRemainCam1,IsRemainCam2;
   public slots:
        void updateMatCam1(Mat);//from generate MatTrans
        void updateMatCam2(Mat);//from generate MatTrans
        void UpdateOcclusionCam1(QList<QList<DataInputCam>>);//dari generateMatcam
        void UpdateOcclusionCam2(QList<QList<DataInputCam>>);//dari generateMatcam
        void remaindedDataCam1(QList<int>);//dari generateMattrans
        void remaindedDataCam2(QList<int>);//dari generateMattrans
        void handlerOutlier();
    signals:
        void posibleIdsend(QList<int>);
        void posibbleIdsend(QList<int>);
};


#endif // OBJASSOCIATE_H_INCLUDED
