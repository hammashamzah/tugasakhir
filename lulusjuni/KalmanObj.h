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
#include "datainputcam.h"
#include "objectvariable.h"
/**Parameter yang akan dipindahkan ke KalmanObj.h**/

using namespace std;
using namespace cv;


class Kalmanobj{
    public:
        Kalmanobj(int camera_id,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur);
        ~Kalmanobj();
        void accum_kalmanobj();
        void multitrackObj();
    private:
        QList <DataInputCam> currentData;
        QList <DataInputCam> previousData;
        QList <DataInputCam> predictionData;
        QList <DataInputCam> initsData;
        QList <DataInputCam> prev;
        double XUL,XUR,XDR,XDL,YUL,YUR,YDR,YDL;
        void initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y);
        Point2f getCurrentStateMot() const;
        Point2f getVelocityMot() const;
        Point2f getAccMot() const;
        void extract_actual_v(double curr_posx,double curr_posy,int idx);
        void extract_actual_a(int idx);
        void track_size(double &pred_w, double &pred_h,DataInputCam reff,DataInputCam current);
        void track_ind2Dmotion(DataInputCam current,Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce);
        //void track_ind3Dmotion(Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce);
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
        Point2f curr_pos         [JUMLAH_PLAYER];
        Point2f post_pos         [JUMLAH_PLAYER];
        Point2f pre_velocity     [JUMLAH_PLAYER];
        Point2f post_velocity    [JUMLAH_PLAYER];
        Point2f accel            [JUMLAH_PLAYER];
   public slots:
        void updateCurrentData(QList<DataInputCam>);//from ObjAssociate hasil mapping
        void updateInitsData(QList<DataInputCam>);//from Hamas
        void updateFrame(int frm);//from Hamas
   signals:
        void updatePrediction(QList<DataInputCam>);//menuju generateMatCam
        void sendPrevious(QList<DataInputCam>);//menuju generateMatCam
};

#endif // KALMANOBJ_H_INCLUDED
