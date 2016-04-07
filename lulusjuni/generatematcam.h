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

class GenerateMatCam:public QObject
{
    Q_OBJECT
public:
        explicit GenerateMatCam(QObject *parent = 0);
        GenerateMatCam(int cam,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double pixel_th);
        ~GenerateMatCam();
        void cam_associate(int data_before,QList<DataInputCam> Current,int Fr,QList<DataInputCam> predict,QList<DataInputCam> prev);
        QList<DataInputCam> indicatedLost;
        QList<DataInputCam> indicatedFound;
    private:
        ObjectVariable obj;
        int data_bef;
        Mat Associate;
        double XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR,THETA;
        int cameras;
        bool Isset1,Isset2,Isset3,Isseto;
        QList<DataInputCam> pred;
        QList<DataInputCam> curr;
        QList<DataInputCam> previous;
        QList<Point> occlusion;
        Mat accCol;Mat accRow;

        int sizeInits,sizePrediction,sizeCurrent,sizePrevious;
        double Euclid_x,Euclid_y;
        double th_y;
        double th_xka,th_xki;
        double xo,yo;
        int frames;
        double threshold_coef(double y);
        void find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
        void link_theid(int data_before);
        void accums();
        void checkFound();
        void checkLost();
        void checkOcclusion();
/*    public slots:
        void updatePredic(QList<DataInputCam>);//dari KalmanObj
        void updatePrevious(QList<DataInputCam>);//dari KalmanObj*/
   signals:
        void updateMatrices(Mat);//menuju generatematrans
        void updateOcclusion(QList<Point>);//menuju objassociate
        void sendCurrent(QList<DataInputCam>);//menuju objectassociate
};

#endif // GENERATEMATCAM_H
