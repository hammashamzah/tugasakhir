#ifndef KALMANOBJ_H_INCLUDED
#define KALMANOBJ_H_INCLUDED
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <string>
#include <QList>
#include "datainputtrans.h"
#include "objectvariable.h"

/**Parameter yang akan dipindahkan ke KalmanObj.h**/
#define Pict_sizex 1280
#define Pict_sizey 1024
#define stateNum_mot 6
#define measureNum_mot 6
#define vx_init 0
#define vy_init 0
#define ax_init 0
#define ay_init 0

using namespace std;
using namespace cv;


class Kalmanobj3D{
    public:
        Kalmanobj3D(double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double fr);
        ~Kalmanobj3D();
        void accum_kalmanobj();
        void multitrackObj();
    private:
        QList <DataInputTrans> currentData;
        QList <DataInputTrans> previousData;
        QList <DataInputTrans> predictionData;
        QList <DataInputTrans> initsData;
        double XUL,XUR,XDR,XDL,YUL,YUR,YDR,YDL;
        void initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y);
        Point2f getCurrentStateMot() const;
        Point2f getVelocityMot() const;
        Point2f getAccMot() const;
        void extract_actual_v(double curr_posx,double curr_posy,int idx);
        void extract_actual_a(int idx);
        //void track_size(double &pred_w, double &pred_h,DataInputTrans reff,DataInputTrans current);
        void track_ind3Dmotion(DataInputTrans curr_cond,Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce);
        void resetdata();
        int Object_Number;
        int camera;
        int frames;
        KalmanFilter KF_Mot;
        bool Isset1,Isset2,Isset3;
        int sizeCurrent,sizeInit,sizePrevious;
        double FrPs;
        double intervals;
        Mat_<float> measurement_pos;
        Point2f curr_pos3d     [JUMLAH_PLAYER];
        Point post_pos3d       [JUMLAH_PLAYER];
        Point pre_velocity3d   [JUMLAH_PLAYER];
        Point post_velocity3d  [JUMLAH_PLAYER];
        Point accel3d          [JUMLAH_PLAYER];
   public slots:
        void updateCurrentData(QList<DataInputTrans>);
        void updateInitsData(QList<DataInputTrans>);
        void updateFrame(int frm);
   signals:
        void updatePrediction(QList<DataInputTrans>);

};

#endif // KALMANOBJ_H_INCLUDED
