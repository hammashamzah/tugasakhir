#ifndef PREPROCESSING_H_INCLUDED
#define PREPROCESSING_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
using namespace cv;


LinkedList list1;
int clusters;
int clusters1;
int cam;
        
/**Data from multiple object detector unit**/
typedef struct{int id; Rect play_dat;char state;bool fo;}player;
/**Data from 2D transformation unit**/
typedef struct{int id; double x_trans;double y_trans;bool fl;}play_transform;


class preproc{
    private:
        void extract_data(struct Node **pNew, player* plays, play_transform* played);
    public:
        void preprocess(bool start,int num_cluster_k,int num_cluster_k1, int cameras,player* plays, play_transform* played, struct Node **buffer1,struct Node **buffer2);   

};

#endif // PREPROCESSING_H_INCLUDED
