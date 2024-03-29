#ifndef HIGHLEVEL_H_INCLUDED
#define HIGHLEVEL_H_INCLUDED

#include "KalmanObj.h"
#include "ObjAssociate.h"
#include "LinkedList.h"
#include "preprocessing.h"

#define NUM_PLAYER 23

/****
#define XUL 100
#define XUR 729
#define XDR 1000
#define XDL 30
#define YUL 512
#define YUR 511
#define YDR 1000
#define YDL 1003
**********/
#define FRAME_RATE 24
Preprocess *preproc1;
Preprocess *preproc2;
Preprocess *preproc3;
Kalmanobj *kalman1;
Kalmanobj *kalman2;
Kalmanobj *kalman3;
Associate *assoccie;


class HighLevel{
    public:
        HighLevel(bool process_on,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double hung_th,double fr);
        void Highlevel_proc(int frame,bool init,int num_cluster1,int num_cluster2,int num_cluster3,player plays1[],player plays2[],player plays3[],play_transform played1[],play_transform played2[],play_transform played3[]);
        int prev_num1,prev_num2,prev_num3;
        int glob_association[NUM_PLAYER][NUM_PLAYER];
        Point accel_3d3[NUM_PLAYER];Point velo3d3[NUM_PLAYER];Point accels3[NUM_PLAYER];Point velo3[NUM_PLAYER];
        Point accel_3d2[NUM_PLAYER];Point velo3d2[NUM_PLAYER];Point accels2[NUM_PLAYER];Point velo2[NUM_PLAYER];
        Point accel_3d1[NUM_PLAYER];Point velo3d1[NUM_PLAYER];Point accels1[NUM_PLAYER];Point velo1[NUM_PLAYER];
    private:
        bool start;
        
}
;


#endif // HIGHLEVEL_H_INCLUDED
