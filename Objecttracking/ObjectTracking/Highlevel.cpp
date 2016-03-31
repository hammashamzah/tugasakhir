#include <KalmanObj.h>
#include <ObjAssociate.h>
#include <LinkedList.h>
#include <preprocessing.h>
#define NUM_PLAYER 23

int prev_num1,prev_num2,prev_num3;
player plays1,plays2,plays3;
play_transform played1,played2,played3;
int association[NUM_PLAYER][NUM_PLAYER];

LinkedList hlevel;
preprocess  prep;
associate   assoc;
Kalmanobj   trackingkalmn;
Point accel_3d3[23],velo3d3[23],accels3[23],velo3[23];
Point accel_3d2[23],velo3d2[23],accels2[23],velo2[23];
Point accel_3d1[23],velo3d1[23],accels1[23],velo1[23];

Highlevel::Highlevel(bool process_on, int frame,bool init,int num_cluster1,int num_cluster2,int num_cluster3){
    int i;
    Node *init1 = new Node;
    Node *init2 = new Node;
    Node *init3 = new Node;
    Node *prev_dat1 = new Node;
    Node *New_dat1 = new Node;
    Node *prev_dat2 = new Node;
    Node *New_dat2 = new Node;
    Node *prev_dat3 = new Node;
    Node *New_dat3 = new Node;
    Node *pred_dat1 = new Node;
    Node *pred_dat2 = new Node;
    Node *pred_dat3 = new Node;
    /**init all parameter**/
    for(i=0;i<23;i++){
        accel_3d3[i].x=0,velo3d3[i].x=0,accels3[i].x=0,velo3[i].x=0;
        accel_3d2[i].x=0,velo3d2[i].x=0,accels2[i].x=0,velo2[i].x=0;
        accel_3d1[i].x=0,velo3d1[i].x=0,accels1[i].x=0,velo1[i].x=0;
        accel_3d3[i].y=0,velo3d3[i].y=0,accels3[i].y=0,velo3[i].y=0;
        accel_3d2[i].y=0,velo3d2[i].y=0,accels2[i].y=0,velo2[i].y=0;
        accel_3d1[i].y=0,velo3d1[i].y=0,accels1[i].y=0,velo1[i].y=0;
    }
    /**extract data**/
    prep.preprocess(process_on,num_cluster1,&prev_num1,1,plays1,played1,&New_dat1,&prev_dat1);
    prep.preprocess(process_on,num_cluster2,&prev_num2,2,plays2,played2,&New_dat2,&prev_dat2);
    prep.preprocess(process_on,num_cluster3,&prev_num3,3,plays3,played3,&New_dat3,&prev_dat3);
    if(init){
        hlevel.copyLinkedList(New_dat1,&init1);
        hlevel.copyLinkedList(New_dat2,&init2);
        hlevel.copyLinkedList(New_dat3,&init3);
    }
    /**object association**/
    assoc.init_multicamassoc();
    assoc.associate(init,pred_dat1,pred_dat2,pred_dat3,New_dat1,New_dat2,New_dat3,prev_num1,prev_num2,prev_num3,num_cluster1,num_cluster2,num_cluster3,association);
    /**kalman tracking**/
    hlevel.deleteLinkedList(&pred_dat1);
    hlevel.deleteLinkedList(&pred_dat2);
    hlevel.deleteLinkedList(&pred_dat3);
    trackingkalmn.Kalmanobj(1,frame,num_cluster1);
    multitrackObj(init,init1,New_dat1,&pred_dat1,accel_3d1,velo3d1,accels1,velo1);
    trackingkalmn.Kalmanobj(2,frame,num_cluster2);
    multitrackObj(init,init2,New_dat2,&pred_dat2,accel_3d2,velo3d2,accels2,velo2);
    trackingkalmn.Kalmanobj(3,frame,num_cluster3);
    multitrackObj(init,init3,New_dat3,&pred_dat3,accel_3d3,velo3d3,accels3,velo3);
}
