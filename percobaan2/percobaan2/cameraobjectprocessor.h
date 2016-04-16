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
#include <QObject>
#include <QPoint>
#include "searchplayerdata.h"
#include "player.h"

using namespace cv;
using namespace std;

class CameraObjectProcessor: public QObject
{
    Q_OBJECT
    public:
        CameraObjectProcessor(QList<QPoint> trapeziumCoordinate, double pixelThreshold);
        ~CameraObjectProcessor();
        void camAssociate(int minimumIndexOfObject,QList<Player> CurrentData, QList<Player> predict, QList<Player> prev);

        QList<QList<Player> > indicatedLostFound;
        Mat associate;
        double xo,yo;
    private:
        SearchPlayerData* searchingdata;
        int data_bef;
        double XDL,XDR,XUL,XUR,YDL,YDR,YUL,YUR,THETA;
        bool IssetCurrent;

        QList<Point> occlusion;
        QList<Player> pred;
        QList<Player> curr;
        QList<Player> previous;
        QList<Player> cleanData;

        QList <QList<Player> > pot_Occlusion;
        Mat accCol;
        Mat accRow;

        int sizeInits,sizePrediction,sizeCurrent,sizePrevious;
        double Euclid_x,Euclid_y;
        double th_y;
        double th_xka,th_xki;

        /**Prosedur yang digunakan**/
        double threshold_coef(double y);
        void find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
        void link_theid();
        void accums();
        void checkFound();
        void checkLost();
        void checkOcclusion();
        void MappingData();
   signals:
        void updateMatrices(Mat);//menuju generatematrans
        void sendLostFound(QList<QList<Player> >);//menuju fussionData
        void sendClusterOcclusion(QList<QList<Player> >);////menuju ObjAssociate
        void sendcleanData(QList<Player>);
};

#endif // GENERATEMATCAM_H
