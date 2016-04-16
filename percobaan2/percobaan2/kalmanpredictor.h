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
#include <QObject>
#include <QPoint>
#include "player.h"
#include "searchplayerdata.h"

/**Parameter yang akan dipindahkan ke KalmanObj.h**/

using namespace std;
using namespace cv;


class KalmanPredictor:public QObject
{
    Q_OBJECT
    public:
        SearchPlayerData* searchingdata;
        KalmanPredictor(QList<QPoint> trapeziumCoordinate,double fr);
        ~KalmanPredictor();
        
        
        QList <Player> previousData;
        QList <Player> predictionData;
    private:
        QList <Player> currentData;
        QList <Player> prev;

        double XUL,XUR,XDR,XDL,YUL,YUR,YDR,YDL;
        Point2f getCurrentStateMot() const;
        Point2f getVelocityMot() const;
        Point2f getAccMot() const;

        KalmanFilter KF_Mot;
        bool IssetCurr;
        int sizeCurrent,sizePrevious;
        double FrPs;
        double intervals;
        double yo;

        Mat_<float> measurement_pos;

        Point2f curr_pos         [JUMLAH_PLAYER];
        Point2f post_pos         [JUMLAH_PLAYER];
        Point2f pre_velocity     [JUMLAH_PLAYER];
        Point2f post_velocity    [JUMLAH_PLAYER];
        Point2f accel            [JUMLAH_PLAYER];
        
        void accum_kalmanobj();
        void multitrackObj();
        void initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y);
        void extract_actual_v(double curr_posx,double curr_posy,int idx);
        void extract_actual_a(int idx);
        void track_size(double &pred_w, double &pred_h,Player reff,Player current);
        void track_ind2Dmotion(Player current,Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce);
        void resetdata();
        void OutlierHandler();

    public slots:
        void getDataCurr(QList<Player>);
    signals:
        void sendPrediction(QList<Player>);//menuju generateMatCam
        void sendPrevious(QList<Player>);//menuju generateMatCam**/
};

#endif // KALMANOBJ_H_INCLUDED
