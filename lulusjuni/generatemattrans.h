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

class GenerateMatTrans
{
    public:
        GenerateMatTrans(double trehshold);
        ~GenerateMatTrans();
        void cam_associate();
    private:
        Mat Associate;
        double THETA;
        bool Isset1,Isset2,Isset3,Isset4;
        QList<DataInputTrans> Qlost;
        QList<DataInputTrans> QFound;
        Mat fixIt;
        Mat inits;
        Mat Assoc;
        int sizeQLost,sizeQFound;
        double Euclid_r,Euclid_x,Euclid_y;
        void link_theid();
        double eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj);
    public slots:
        void updateQLost(QList<DataInputTrans>);//darigenerateMatcam
        void updateQFound(QList<DataInputTrans>);//dari generateMatcam
        void getAssociate(Mat);//dari generateMatcam
   signals:
        void UpdateAssociate(Mat);//menuju objassociate
};


#endif // GENERATEMATTRANS_H
