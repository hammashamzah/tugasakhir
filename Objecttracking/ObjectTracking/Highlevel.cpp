#include "Highlevel.h"
    
LinkedList hlevel;

HighLevel::HighLevel(bool process_on,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double hung_th,double fr){
    start = process_on;
    preproc1 = new Preprocess(process_on,1);
    preproc2 = new Preprocess(process_on,2);
    preproc3 = new Preprocess (process_on,3);
    kalman1 = new Kalmanobj(1,process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,fr);
    kalman2 = new Kalmanobj(2,process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,fr);
    kalman3 = new Kalmanobj(3,process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,fr);
    assoccie = new Associate(process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,hung_th);
}

void HighLevel::Highlevel_proc(int frame,bool init,int num_cluster1,int num_cluster2,int num_cluster3,player plays1[],player plays2[],player plays3[],play_transform played1[],play_transform played2[],play_transform played3[]){
    int i,j;
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
    if(start){
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
        preproc1->accum_preprocess(num_cluster1,prev_num1, 1,plays1,played1,&New_dat1,&prev_dat1);
        preproc2->accum_preprocess(num_cluster2,prev_num2, 2,plays2,played2,&New_dat2,&prev_dat2);
        preproc3->accum_preprocess(num_cluster3,prev_num3, 3,plays3,played3,&New_dat3,&prev_dat3);
        if(init){
            hlevel.copyLinkedList(New_dat1,&init1);
            hlevel.copyLinkedList(New_dat2,&init2);
            hlevel.copyLinkedList(New_dat3,&init3);
        }
        /**object association**/
        assoccie->init_multicamassoc();
        assoccie->accum_assoc(init,pred_dat1,pred_dat2,pred_dat3,New_dat1,New_dat2,New_dat3,prev_num1,prev_num2,prev_num3,num_cluster1,num_cluster2,num_cluster3);
        for(i=0;i<23;i++){
            for(j=0;j<23;j++){
              glob_association[i][j]=assoccie->association_agrr[i][j];  
            }
        }
        /**kalman tracking**/
        hlevel.deleteLinkedList(&pred_dat1);
        hlevel.deleteLinkedList(&pred_dat2);
        hlevel.deleteLinkedList(&pred_dat3);
        kalman1->accum_kalmanobj(frame,num_cluster1);
        kalman1->multitrackObj(init,init1,New_dat1,&pred_dat1,accel_3d1,velo3d1,accels1,velo1);
        kalman2->accum_kalmanobj(frame,num_cluster2);
        kalman2->multitrackObj(init,init2,New_dat2,&pred_dat2,accel_3d2,velo3d2,accels2,velo2);
        kalman3->accum_kalmanobj(frame,num_cluster3);
        kalman3->multitrackObj(init,init3,New_dat3,&pred_dat3,accel_3d3,velo3d3,accels3,velo3);
    }
}