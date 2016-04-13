#ifndef GENERATEMATTRANS_H
#define GENERATEMATTRANS_H

#include "objectvariable.h"
#include "opencv/ml.h"
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <cmath>
#include <QList>
#include <datainputtrans.h>
using namespace cv;
using namespace std;

class TransformedObjectProcessor:public QObject
{
    Q_OBJECT
    public:
        TransformedObjectProcessor(double trehshold);
        ~TransformedObjectProcessor();
        void cam_associate();
    private:
        Mat Associate;
        double THETA;
        bool IsSetMat,IsSetDataTrans,IsOccSet;

        QList<int> remaindedDataId;
        QList<DataInputTrans> QlostFound;
        QList<DataInputTrans> Qlost;
        QList<DataInputTrans> Qfound;


        QList <QList<DataInputCam> > prevOcc;
        QList <QList<DataInputCam> > currOcc;

        Mat fixIt;
        Mat inits;
        Mat Assoc;
        double Euclid_r;
        void link_theid();
        void generateQCluster();
        double eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj);
    public slots:
        void getAssociate(Mat);//dari generateMatcam
        void getDataTrans(QList<DataInputTrans>);//dari Aznan
   signals:
        void UpdateAssociate(Mat);//menuju objassociate
        void UpdateremaindedData(QList<int>);//menuju objassociate

};


#endif // GENERATEMATTRANS_H
