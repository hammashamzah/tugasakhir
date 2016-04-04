#ifndef OBJASSOCIATE_H_INCLUDED
#define OBJASSOCIATE_H_INCLUDED
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include "datainputcam.h"
#include "datainputtrans.h"
#include "objectvariable.h"

using namespace cv;
using namespace std;


class Associate{
    public: 
        int validate;
        Associate();
        ~Associate();
        void init_multicamassoc();
        void accum_assoc();
        void link_theid(int cam);
        void init_matrices_assoc();
        Mat  association_agrr;
        bool Ismapped,Issetmat;
    private:

        /**Parameter Input Class dinamik**/
        QList<DataInputCam> predic1;
        int sizePredict1;bool Isset1;
        QList<DataInputCam> predic2;
        int sizePredict2;bool Isset2;
        QList<DataInputCam> predic3;
        int sizePredict3;bool Isset3;
        QList<DataInputTrans> predicTrans;
        int sizePredictT;bool Isset4;
        QList<DataInputCam> measure1;
        int sizeMeas1;bool Isset5;
        QList<DataInputCam> measure2;
        int sizeMeas2;bool Isset6;
        QList<DataInputCam> measure3;
        int sizeMeas3;bool Isset7;
        QList<DataInputTrans> currentTrans;
        int sizeMeasT;bool Isset8;
        Mat inMatCam1;bool Isset9;
        Mat inMatCam2;bool Isset10;
        Mat inMatCam3;bool Isset11;
        Mat inMatCamT;bool Isset12;


        QList<DataInputCam> mapRes1;
        QList<DataInputCam> mapRes2;
        QList<DataInputCam> mapRes3;
        QList<DataInputTrans> mapResTrans;



        void mapping(Node** Res);
        void sum_updated_mat();
        void mapping();
        void associate_losthyp(int number_lost,int number_found);
        void set_Ntoone(int &occ1,int &occ2,int &occ3,int &clus_occ1,int &clus_occ2,int &clus_occ3);
        void pot_ousted(int init,int camr,int &fin);
        void update_hypothesis(int init,int camr,int &fin);
        void update_arracc();
        //int FSM(int prev_state,bool Isinit,bool set_id,bool onetoN,bool Ntoone,bool onetoone,int flag,bool emptyrow);
        void cam_associate(int cam,int num_p,int num_m,Node *p,struct Node *m);
        double threshold_coef(double y);
        void find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
        int num_predictor;
        int num_measurement;
        int cameras;
        double eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj);
        Mat association1p    ;
        Mat association2p    ;
        Mat association3p    ;
        Mat association_globe;

        double THETA;
        double yo;
        double xo;

        int num_trans1;
        int num_trans2;
        int numm1,numm2,numm3,nump1,nump2,nump3;

        //const double threshold_glob = 1.50;
        int obj_cam[3];
        int meas_cam[3];
        LinkedList listgen;

        int accumulate_row1[JUMLAH_PLAYER];
        int accumulate_row2[JUMLAH_PLAYER];
        int accumulate_row3[JUMLAH_PLAYER];
        int accumulate_col1[JUMLAH_PLAYER];
        int accumulate_col2[JUMLAH_PLAYER];
        int accumulate_col3[JUMLAH_PLAYER];


        Point id_obj_occluded1  [JUMLAH_PLAYER];
        Point id_obj_occluded2  [JUMLAH_PLAYER];
        Point id_obj_occluded3  [JUMLAH_PLAYER];
        Point hypothest         [JUMLAH_PLAYER];
        Point Potentially_out   [JUMLAH_PLAYER];
   public slots:
        void updateMatCam1(Mat);
        void updateMatCam2(Mat);
        void updateMatCam3(Mat);
        void updateMatTrans(Mat);
        void updateKalmanCam1(QList<DataInputCam>);
        void updateKalmanCam2(QList<DataInputCam>);
        void updateKalmanCam3(QList<DataInputCam>);
        void updateKalmanTrans(QList<DataInputTrans>);
        void updateCurrentCam1(QList<DataInputCam>);
        void updateCurrentCam2(QList<DataInputCam>);
        void updateCurrentCam3(QList<DataInputCam>);
        void updateCurrentTrans(QList<DataInputTrans>);
   signals:
        void mapResCam1(QList<DataInputCam>);
        void mapResCam2(QList<DataInputCam>);
        void mapResCam3(QList<DataInputCam>);
        void mapResTrans(QList<DataInputTrans>);
        void matricesChanged(Mat);
};


#endif // OBJASSOCIATE_H_INCLUDED
