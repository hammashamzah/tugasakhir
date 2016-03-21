#ifndef OBJASSOCIATE_H_INCLUDED
#define OBJASSOCIATE_H_INCLUDED
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

using namespace cv;
using namespace std;


double basic_threshold = theta;
double yo;
double xo;
int num_predictor;
int num_measurement;

LinkedList listgen;

struct Node *predictor;
struct Node *measurement;

class associate{
    public:
        associate(int num_p,int num_m,struct Node *p,struct Node *m,int assoc[][23]);
        ~associate();
        void link_theid(int assoc[][23]);
        void init_matrices_assoc(int assoc[][23]);
    private:
        double threshold_coef(double y);
        void find_threshold_x(double *x_kanan,double *x_kiri,double y,double x,double y_m);
        double find_threshold_y(double y);
   
};


#endif // OBJASSOCIATE_H_INCLUDED
