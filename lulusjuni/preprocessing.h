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
#include "node.h"
using namespace std;
using namespace cv;

        
/**Data from multiple object detector unit**/
typedef struct{int id; Rect play_dat;int status;bool fo;}player;
/**Data from 2D transformation unit**/
typedef struct{int id; double x_trans;double y_trans;bool fl;}play_transform;



class Preprocess{
    private:
        void extract_data(player* plays, play_transform* played);
        Node *pNew  ;
        Node *buff1 ;
        Node *buff2 ;
        int clusters;
        int clusters1;
        int cam;
    public:
        bool proc_start;
        Preprocess(bool start);
        ~Preprocess();
        void accum_preprocess(int num_cluster,int &num_cluster_k1, int cameras,player* plays, play_transform* played);
        LinkedList list1;
        Node* current_dat1; Node* prev_dat1;
};

#endif // PREPROCESSING_H_INCLUDED
