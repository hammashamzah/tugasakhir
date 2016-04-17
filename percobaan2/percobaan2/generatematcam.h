#ifndef GENERATEMATCAM_H
#define GENERATEMATCAM_H

#include "opencv/ml.h"
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <cmath>
#include <QList>
##include "player.h"


using namespace cv;
using namespace std;

class CameraObjectProcessor: public QObject
{
    Q_OBJECT
public:
        CameraObjectProcessor(int cameraNumber, QList<QPoint> trapeziumCoordinate, double pixelThreshold);
        ~CameraObjectProcessor();
        void camAssociate(int data_before,int Fr,QList<Player> predict,QList<Player> prev);
        
        
        /**variable yang akan diemisikan**/
        QList<QList<Player> > indicatedLostFound;
        QList<Player> cleanData;
        QList<QList<Player> > clusterOcclusion;
        Mat Associate;
    private:
        int data_bef;
        double xo,yo;
        double XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR,THETA;
        int cameras;
        bool IssetCurrent;

        QList<Point> occlusion;
        QList<Player> pred;
        QList<Player> curr;
        QList<Player> previous;

        QList <QList<Player> > pot_Occlusion;
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
        void getDataCurrent(QList<Player>);
   signals:
        void updateMatrices(Mat);//menuju generatematrans
        void sendLostFound(QList<Player>);//menuju fussionData
        void sendOcclusion(QList<QList<Player> >);////menuju ObjAssociate
};

#endif // GENERATEMATCAM_H
