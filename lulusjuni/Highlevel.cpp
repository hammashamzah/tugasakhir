#include "Highlevel.h"
#include "objectvariable.h"

LinkedList hlevel;

HighLevel::HighLevel(bool process_on,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double hung_th,double fr){
    start = process_on;
    preproc1 = new Preprocess(process_on);
    preproc2 = new Preprocess(process_on);
    preproc3 = new Preprocess(process_on);
    kalman1 = new Kalmanobj(1,process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,fr);
    kalman2 = new Kalmanobj(2,process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,fr);
    kalman3 = new Kalmanobj(3,process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,fr);
    assoccie = new Associate(process_on,xdl,xdr,xul,xur,ydl,ydr,yul,yur,hung_th);
    init1     = new Node;
    init2     = new Node;
    init3     = new Node;
    prev_dat1 = new Node;
    New_dat1  = new Node;
    prev_dat2 = new Node;
    New_dat2  = new Node;
    prev_dat3 = new Node;
    New_dat3  = new Node;
    pred_dat1 = new Node;
    pred_dat2 = new Node;
    pred_dat3 = new Node;
    map_res   = new Node;
}

void HighLevel::Highlevel_proc(int frame,bool init,int num_cluster1,int num_cluster2,int num_cluster3,player plays1[],player plays2[],player plays3[],play_transform played1[],play_transform played2[],play_transform played3[]){
    int i;
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
        preproc1->accum_preprocess(num_cluster1,prev_num1, 1,plays1,played1);
        preproc1->accum_preprocess(num_cluster2,prev_num2, 2,plays2,played2);
        preproc1->accum_preprocess(num_cluster3,prev_num3, 3,plays3,played3);
        if(init){
            hlevel.copyLinkedList(preproc1->current_dat1,&init1);
            hlevel.copyLinkedList(preproc2->current_dat1,&init2);
            hlevel.copyLinkedList(preproc3->current_dat1,&init3);
        }
        else{
            hlevel.copyLinkedList(preproc1->current_dat1,&New_dat1);
            hlevel.copyLinkedList(preproc2->current_dat1,&New_dat2);
            hlevel.copyLinkedList(preproc3->current_dat1,&New_dat3);
            hlevel.copyLinkedList(preproc1->prev_dat1,&prev_dat1);
            hlevel.copyLinkedList(preproc2->prev_dat1,&prev_dat2);
            hlevel.copyLinkedList(preproc3->prev_dat1,&prev_dat3);
        }
        /**object association**/

        hlevel.deleteLinkedList(&map_res);
        assoccie->init_multicamassoc();
        assoccie->cam_associate( 1, nump1,numm1,predic1,measure1);
        assoccie->cam_associate( 2, nump2,numm2,predic2,measure2);
        assoccie->cam_associate( 3, nump3,numm3,predic3,measure3);
        assoccie->accum_assoc(init,pred_dat1,pred_dat2,pred_dat3,New_dat1,New_dat2,New_dat3,prev_num1,prev_num2,prev_num3,num_cluster1,num_cluster2,num_cluster3);
        if(assoccie->validate==NUM_PLAYER)
            Isvalid = true;
        else
            Isvalid =false;
        map_res = new Node;
        hlevel.copyLinkedList(assoccie->mapping_result,&map_res);
        update_player();
        get_matricesAssociate();
        /**kalman tracking**/
        hlevel.deleteLinkedList(&pred_dat1);
        hlevel.deleteLinkedList(&pred_dat2);
        hlevel.deleteLinkedList(&pred_dat3);
        pred_dat1 = new Node;
        pred_dat2 = new Node;
        pred_dat3 = new Node;
        kalman1->accum_kalmanobj(frame,num_cluster1);
        kalman1->multitrackObj(init1,New_dat1);
        kalman2->accum_kalmanobj(frame,num_cluster2);
        kalman2->multitrackObj(init2,New_dat2);
        kalman3->accum_kalmanobj(frame,num_cluster3);
        kalman3->multitrackObj(init3,New_dat3);
        hlevel.copyLinkedList(kalman1->predict_track,&pred_dat1);
        hlevel.copyLinkedList(kalman2->predict_track,&pred_dat2);
        hlevel.copyLinkedList(kalman3->predict_track,&pred_dat3);
    }
}


void HighLevel::get_matricesAssociate(){
    int i,j;
    for(i=0;i<NUM_PLAYER;i++){
        for(j=0;j<NUM_PLAYER;j++){
            assoc_mat[i][j]= assoccie->association_agrr[i][j];
        }

    }
}



void HighLevel::update_player(){
    int i=0;
    Node* bufferfin;
    bufferfin = map_res;
    while(i<NUM_PLAYER && bufferfin != NULL){
        player_visual[bufferfin->data_id].id=bufferfin->data_id;
        player_visual[bufferfin->data_id].Position = QPoint((int)bufferfin->x_trans,(int)bufferfin->y_trans);
        player_visual[bufferfin->data_id].speed = sqrt(((bufferfin->vx_trans)*(bufferfin->vx_trans))+((bufferfin->vy_trans)*(bufferfin->vy_trans)));
        bufferfin = bufferfin->next;
    }
}
