#ifndef GENERATEMATCAM_H
#define GENERATEMATCAM_H
#include "objectvariable.h"
#include "opencv/ml.h"
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <cmath>
#include <QObject>
#include "arrdatcam.h"

using namespace cv;
using namespace std;

class GenerateMatcam
{
    public:
        GenerateMatcam(int cam,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double pixel_th);
        ~GenerateMatcam();
        void cam_associate();
        Mat Associate;
        bool Isset;
    private:
        double XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR,THETA;
        int cameras;
        Arrcam pred;
        Arrcam inits;
        Arrcam curr;
        double Euclid_x,Euclid_y;
        double th_y;
        double th_xka,th_xki;
        double xo,yo;
        int frames;
        double threshold_coef(double y);
        void find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
        void link_theid();
    public slots:
        void updatePredic(bool Isset,ArrDatCam predic);
        void updateinit(bool Isset, ArrDatCam init);
        void updateCurrent(bool Isset, ArrDatCam current);
    signals:
};

#endif // GENERATEMATCAM_H
