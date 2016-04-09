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

class GenerateMatTrans:public QObject
{
    Q_OBJECT
    public:
        explicit GenerateMatTrans(QObject *parent = 0);
        GenerateMatTrans(double trehshold);
        ~GenerateMatTrans();
        void cam_associate();
    private:
        Mat Associate;
        double THETA;
        bool IsSetMat,IsSetDataTrans;

        QList<DataInputTrans> QlostFound;
        QList<DataInputTrans> Qlost;
        QList<DataInputTrans> Qfound;
        Mat fixIt;
        Mat inits;
        Mat Assoc;
        double Euclid_r;
        void link_theid();
        double eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj);
    public slots:
        void getAssociate(Mat);//dari generateMatcam
        void getDataTrans(QList<DataInputTrans>);//dari Aznan
   signals:
        void UpdateAssociate(Mat);//menuju objassociate

};


#endif // GENERATEMATTRANS_H
