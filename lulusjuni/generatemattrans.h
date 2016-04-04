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
#include <QObject>
#include "arrdattrans.h"

using namespace cv;
using namespace std;

class GenerateMatTrans
{
    public:
       GenerateMatTrans(double trehshold);
        ~GenerateMatTrans();
        void cam_associate();
        Mat Associate;
        bool Isset;
    private:
        double THETA;
        Arrtrans pred;
        Arrtrans inits;
        Arrtrans curr;
        double Euclid_r,Euclid_x,Euclid_y;
        int frames;
        void link_theid();
        double eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj);
    public slots:
        void updatePredic(bool Isset,Arrdattrans predic);
        void updateinit(bool Isset, Arrdattrans init);
        void updateCurrent(bool Isset, Arrdattrans current);
    signals:
};


#endif // GENERATEMATTRANS_H
