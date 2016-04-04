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
#include <QList>
#include "datainputcam.h"

using namespace cv;
using namespace std;

class GenerateMatCam
{
    public:
        GenerateMatCam(int cam,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double pixel_th);
        ~GenerateMatCam();
        void cam_associate();
    private:
        Mat Associate;
        double XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR,THETA;
        int cameras;
        bool Isset1,Isset2,Isset3,Isset4;
        QList<DataInputCam> pred;
        QList<DataInputCam> inits;
        QList<DataInputCam> curr;
        int sizeInits,sizePrediction,sizeCurrent;
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
        void updatePredic(QList<DataInputCam>);
        void updateinit(QList<DataInputCam>);
        void updateCurrent(QList<DataInputCam>);
        void updateFrame(int fr);
   signals:
        void UpdateMatrices(Mat);
};

#endif // GENERATEMATCAM_H
