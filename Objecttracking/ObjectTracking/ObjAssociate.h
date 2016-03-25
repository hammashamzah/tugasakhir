#ifndef OBJASSOCIATE_H_INCLUDED
#define OBJASSOCIATE_H_INCLUDED
#include "opencv/ml.h"
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
#define theta 20
#define xul 100
#define xur 729
#define xdr 1000
#define xdl 30
#define yul 512
#define yur 511
#define ydr 1000
#define ydl 1003
/**#define camera_max 3
/**#define w_lapangan 70/**lebar lapangan 70 m**/
/**#define l_lapangan 100/**panjang lapangan 100 m**/

#define state_hipothetic    1
#define state_Normal        2
#define state_pottrans      3
#define state_group         4
#define state_camtrans      5

using namespace cv;
using namespace std;


struct Node* result;


/**
    CvEM empredict;
    CvEMParams parameter;

    int num_samples;
    Mat labels;
    parameter.covs      = NULL;
    parameter.means     = NULL;
    parameter.weights   = NULL;
    parameter.probs     = NULL;
    parameter.nclusters = N;
    parameter.cov_mat_type       = CvEM::COV_MAT_SPHERICAL;
    parameter.start_step         = CvEM::START_AUTO_STEP;
    parameter.term_crit.max_iter = 1000;
    parameter.term_crit.epsilon  = 0.005;
    parameter.term_crit.type     = CV_TERMCRIT_ITER|CV_TERMCRIT_EPS;
**/



struct Node* predic1;
struct Node* predic2;
struct Node* predic3;
struct Node* measure1;
struct Node* measure2;
struct Node* measure3;

double basic_threshold = theta;
double yo;
double xo;
double threshold_glob = 1.00;/**threshold 3d ialah dis ekitar 1 meter dari objek yang ditinjau**/

double threshold_transition = 1.50;/**threshold untuk menghandle camera transition 1.5 meter**/


int num_trans1;
int num_trans2;
int numm1,numm2,numm3,nump1,nump2,nump3;


int obj_cam[3];
int meas_cam[3];
LinkedList listgen;

int accumulate_row1[23];
int accumulate_row2[23];
int accumulate_row3[23];
int accumulate_col1[23];
int accumulate_col2[23];
int accumulate_col3[23];

bool Inits;

int id_obj_occluded[23];


/**
    Node* predictor1;
    Node* predictor2;
    Node* predictor3;
    Node* measurement1;
    Node* measurement2;
    Node* measurement3;
**/




class associate{
    public:        
        void cam_associate(int cam,int num_p,int num_m,struct Node *p,struct Node *m,int assoc[][23]);
        ~associate();
        void link_theid(int cam);
        void init_matrices_assoc();
    private:
        double threshold_coef(double y);
        void find_threshold_x(double *x_kanan,double *x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
        int num_predictor;
        int num_measurement;
        int cameras;
        double eigen_distance(double x_measure, double x_obj, double y_measure, double y_obj);
        struct Node *predictor;
        struct Node *measurement;
        int association1        [23][23];
        int association2        [23][23];
        int association3        [23][23];
        int association1p       [23][23];
        int association2p       [23][23];
        int association3p       [23][23];
        int association_globe   [23][23];
};


#endif // OBJASSOCIATE_H_INCLUDED
