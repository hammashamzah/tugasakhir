#ifndef KALMANOBJ_H_INCLUDED
#define KALMANOBJ_H_INCLUDED
#include "LinkedList.h"
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
/**Parameter yang akan dipindahkan ke KalmanObj.h**/
#define Pict_sizex 1280
#define Pict_sizey 1024
#define stateNum_mot 6
#define measureNum_mot 2
#define FrPs 24
#define vx_init 0
#define vy_init 0
#define ax_init 0
#define ay_init 0
#define xul 100
#define xur 729
#define xdr 1000
#define xdl 30
#define yul 512
#define yur 511
#define ydr 1000
#define ydl 1003

using namespace std;
using namespace cv;

KalmanFilter KF_Mot;

LinkedList list1;
bool Isinit;
double intervals;
int Object_Number;
int camera;
int frame_start;
Mat_<float> measurement_pos;

class Kalmanobj{
    public:
        Kalmanobj(int camera_id,int start,int Num_Obj);
        ~Kalmanobj();
        void multitrackObj(struct Node* init_symp, struct Node* current_symp, struct Node** predict_track);
    private:
        void initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y);
        Point getCurrentStateMot() const;
        Point getVelocityMot() const;
        Point getAccMot() const;
        Point extract_actual_v(struct Node* current_symp);
        Point extract_actual_a(double curr_vx, double curr_vy);
        void track_size(double *pred_w, double *pred_h,struct Node* init_matric,struct Node* curr_matric);
        void track_ind2Dmotion(struct Node* curr_cond, Point *pre_position,Point *pre_velocity,Point *pre_Accelerate,Point *post_position,Point *post_velocity,Point *post_Accelerate);
        void track_ind3Dmotion(struct Node* curr_cond, Point *pre_position,Point *pre_velocity,Point *pre_Accelerate,Point *post_position,Point *post_velocity,Point *post_Accelerate);
};

#endif // KALMANOBJ_H_INCLUDED
