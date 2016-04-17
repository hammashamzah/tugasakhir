#ifndef KALMANDYNAMIC_H
#define KALMANDYNAMIC_H

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

using namespace std;
using namespace cv;

class KalmanDynamic:public QObject
{
        Q_OBJECT
    public:
    	Player* player;
        SearchPlayerData* searchingdata;
        KalmanDynamic(QList<QPoint> trapeziumCoordinate,double fr);
        ~KalmanDynamic();
		        
        
        QList <Player> previousData;
        QList <Player> predictionData;
    private:
        QList <Player> currentData;
        QList <Player> prev;

        double XUL,XUR,XDR,XDL,YUL,YUR,YDR,YDL;
        Point2f getCurrentStateMot() const;
        Point2f getVelocityMot() const;
        Point2f getAccMot() const;

        Point2f post_posp,post_velsp,post_accp;
        Point2f priory_posp,priory_velsp,priory_accp;

        KalmanFilter KF_Mot;
        bool IssetCurr;
        int sizeCurrent,sizePrevious;
        double FrPs;
        double intervals;
        double yo;

        Mat_<float> measurement_pos;
        QList <Player> measuring;

        void accum_kalmanobj();
        void multitrackObj();
        void initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y);
        void extract_actual_v(double curr_posx,double curr_posy,int idx);
        void extract_actual_a(int idx);
        void track_size(double &pred_w, double &pred_h,Player reff,Player current);
        void track_ind2Dmotion(Player curr_cond, Point2f &pre_pos,Point2f &pre_veloc,Point2f &pre_Acce,Point2f &post_pos,Point2f &post_veloc,Point2f &post_Acce);

    public slots:
        void getDataCurr(QList<Player>);
    signals:
        void sendPrediction(QList<Player>);
        void sendPrevious(QList<Player>);
};

#endif // KALMANDYNAMIC_H

