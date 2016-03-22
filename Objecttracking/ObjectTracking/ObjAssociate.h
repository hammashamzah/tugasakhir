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
#define camera_max 3

using namespace cv;
using namespace std;
CvEM empredict;
CvEMParams parameter;

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


double basic_threshold = theta;
double yo;
double xo;
int num_predictor;
int num_measurement;

LinkedList listgen;


struct Node *predictor;
struct Node *measurement;
int association[23][23];



class associate{
    public:
        associate(int num_p,int num_m,struct Node *p,struct Node *m,int assoc[][23]);
        ~associate();
        void link_theid();
        void init_matrices_assoc();
    private:
        double threshold_coef(double y);
        void find_threshold_x(double *x_kanan,double *x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
};


#endif // OBJASSOCIATE_H_INCLUDED
