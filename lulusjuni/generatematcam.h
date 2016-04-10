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
        void cam_associate(int data_before,int Fr,QList<DataInputCam> predict,QList<DataInputCam> prev);
        QList<DataInputCam> indicatedLostFound;
        Mat Associate;
        double xo,yo;
    private:
        ObjectVariable obj;
        int data_bef;
        double XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR,THETA;
        int cameras;
        bool IssetCurrent;

        QList<Point> occlusion;
        QList<DataInputCam> pred;
        QList<DataInputCam> curr;
        QList<DataInputCam> previous;

        QList <QList<DataInputCam> > pot_Occlusion;
        Mat accCol;Mat accRow;

        int sizeInits,sizePrediction,sizeCurrent,sizePrevious;
        double Euclid_x,Euclid_y;
        double th_y;
        double th_xka,th_xki;
        int frames;
        double threshold_coef(double y);
        void find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
        void link_theid();
        void accums();
        void checkFound();
        void checkLost();
        void checkOcclusion();
        void generateOcclusionCluster();
   public slots:
        void getDataCurrent(QList<DataInputCam>);
   signals:
        void updateMatrices(Mat);//menuju generatematrans
        void sendLostFound(QList<DataInputCam>);//menuju fussionData
        void sendOcclusion(QList<QList<DataInputCam> >);////menuju ObjAssociate
};

#endif // GENERATEMATCAM_H
