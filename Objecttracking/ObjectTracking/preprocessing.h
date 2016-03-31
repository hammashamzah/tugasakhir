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
Node *pNew  = new Node;
Node *buff1 = new Node;
Node *buff2 = new Node;

int clusters;
int clusters1;
int cam;
        
/**Data from multiple object detector unit**/
typedef struct{int id; Rect play_dat;char state;bool fo;}player;
/**Data from 2D transformation unit**/
typedef struct{int id; double x_trans;double y_trans;bool fl;}play_transform;


class preprocess{
    private:
        void extract_data(player* plays, play_transform* played);
    public:
        preprocess(bool start,int num_cluster,int* num_cluster_k1, int cameras,player* plays, play_transform* played,struct Node**current_dat,struct Node** prev_dat); 

};

#endif // PREPROCESSING_H_INCLUDED
