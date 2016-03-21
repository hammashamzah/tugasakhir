#include "KalmanObj.h"
#define DEBUG

Kalmanobj::Kalmanobj(int camera_id,int start,int Num_Obj){
    frame_start = start;
    camera = camera_id;
    intervals = 1/FrPs;
    Object_Number = Num_Obj;
    if(frame_start == 1){
        Isinit = true;
    }
    else{
        Isinit = false;
    }
}

Kalmanobj::~Kalmanobj(){
    
}


void Kalmanobj::multitrackObj(struct Node* init_symp, struct Node* current_symp, struct Node** predict_track){
    Node *list_curr = current_symp;
    Node *list_init = init_symp;
    Point priory_pos,priory_vels,priory_acc,post_pos,post_vels,post_acc;
    Point priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp;
    double pred_h,pred_w;
    
    while(list_curr!=NULL){
        *predict_track = new Node;
        track_ind3Dmotion(list_curr,&priory_pos,&priory_vels,&priory_acc,&post_pos,&post_vels,&post_acc);
        track_ind2Dmotion(list_curr,&priory_posp,&priory_velsp,&priory_accp,&post_posp,&post_velsp,&post_accp);
        Node *list_get = list1.searchNode(list_init,list_curr->data_id);
        track_size(&pred_w, &pred_h,list_get,list_curr);
        (*predict_track)->data_id = list_curr->data_id;
        (*predict_track)->val_x = (double)post_posp.x;
        (*predict_track)->val_y = (double)post_posp.y;
        (*predict_track)->x_trans = (double)post_pos.x;
        (*predict_track)->y_trans = (double)post_pos.y;
        (*predict_track)->val_w = pred_w;
        (*predict_track)->val_h = pred_h;
        (*predict_track)->flag = list_curr->flag;
        (*predict_track)->flago = list_curr->flago;
        (*predict_track)->next = NULL;
        list_curr = list_curr->next;
    }
}

void Kalmanobj::initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y){
    int i;
    Mat statePost = (Mat_<float>(stateNum_mot, 1) << pos_x,pos_y,v_x,v_y,a_x,a_y);
    Mat transitionMatrix = (Mat_<float>(stateNum_mot, stateNum_mot) << 1, 0,    intervals,          0,      0.5*intervals*intervals,            0,
                                                               0, 1,            0,  intervals,                            0, 0.5*intervals*intervals,
                                                               0, 0,            1,          0,                      intervals,          0,
                                                               0, 0,            0,          1,                              0,   intervals,
                                                               0, 0,            0,          0,                              1,          0,
                                                               0, 0,            0,          0,                              0,          1
                                                            );

    
    KF_Mot.transitionMatrix = transitionMatrix;
    KF_Mot.statePost = statePost;
    setIdentity(KF_Mot.measurementMatrix);
    setIdentity(KF_Mot.processNoiseCov, Scalar::all(1e-1));
    setIdentity(KF_Mot.measurementNoiseCov, Scalar::all(1e-3));
    setIdentity(KF_Mot.errorCovPost, Scalar::all(0.1));
    measurement_pos = Mat::zeros(measureNum_mot, 1, CV_32F);
}


Point Kalmanobj::getCurrentStateMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}

Point Kalmanobj::getVelocityMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}

Point Kalmanobj::getAccMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}

Point Kalmanobj::extract_actual_v(struct Node* current_symp){
    Point state_pos;
    double bef_px,bef_py,curr_px,curr_py;
    if(Isinit){
        bef_px = current_symp->val_x;
        bef_py = current_symp->val_y;
    }
    bef_px = curr_px;
    curr_px = current_symp-> val_x;
    bef_py = curr_py;
    curr_py = current_symp-> val_y;
    state_pos.x = (curr_px - bef_px)/intervals;
    state_pos.y = (curr_py - bef_py)/intervals;
    return(state_pos);
}

Point Kalmanobj::extract_actual_a(double curr_vx, double curr_vy){
    double a_x,a_y;
    Point state_pos;
    double bef_px,bef_py,curr_px,curr_py;
    
    if(Isinit){
        a_x = 0;
        a_y = 0;
        bef_px = curr_vx;
        bef_py = curr_vy;
    }
    bef_px = curr_px;
    curr_px = curr_vx;
    bef_py = curr_py;
    curr_py = curr_vy;
    state_pos.x = (curr_px - bef_px)/intervals;
    state_pos.y = (curr_py - bef_py)/intervals;
    return(state_pos);
}

void track_size(double *pred_w, double *pred_h,struct Node* init_matric,struct Node* curr_matric){
    /*koordinate titik hilang*/
    double yo =((xdr-xdl)/(((-xdl+xul)/(ydl-yul))+((xdr-xur)/(ydr-yur))))-((ydl+ydr)/2);
    double perb_init = (-(init_matric->val_y)+((ydl+ydr)/2))/((init_matric->val_y)-yo);
    double perb_act = ((curr_matric->val_y)-yo)/(((curr_matric->val_y)-yo)+((init_matric->val_y)-((ydl+ydr)/(2))));
    double width_pres = (1+perb_init)*curr_matric->val_w;
    double height_pres = (1+perb_init)*curr_matric->val_h;
    *pred_w = width_pres * perb_act;
    *pred_h = height_pres * perb_act;
}

void Kalmanobj::track_ind2Dmotion(struct Node* curr_cond, Point *pre_position,Point *pre_velocity,Point *pre_Accelerate,Point *post_position,Point *post_velocity,Point *post_Accelerate){
    Point *vcc_p,*acc_p;
    initKalmanMOt((double)curr_cond->val_x, (double)curr_cond->val_y,(double)vcc_p->x,(double)vcc_p->y,(double)acc_p->x, (double)acc_p->y);
    KF_Mot.predict();
    *pre_position = getCurrentStateMot();
    *pre_velocity = getVelocityMot();
    *pre_Accelerate = getAccMot();
    KF_Mot.correct(measurement_pos);
    *post_position = getCurrentStateMot();
    *post_velocity = getVelocityMot();
    *post_Accelerate = getAccMot();
    *vcc_p = extract_actual_v(curr_cond);
    *acc_p = extract_actual_a((double)vcc_p->x,(double)vcc_p->y);
}

void Kalmanobj::track_ind3Dmotion(struct Node* curr_cond, Point *pre_position,Point *pre_velocity,Point *pre_Accelerate,Point *post_position,Point *post_velocity,Point *post_Accelerate){
    Point *vcc,*acc;
    initKalmanMOt((double)curr_cond->val_x, (double)curr_cond->val_y,(double)vcc->x,(double)vcc->y,(double)acc->x, (double)acc->y);
    KF_Mot.predict();
    *pre_position = getCurrentStateMot();
    *pre_velocity = getVelocityMot();
    *pre_Accelerate = getAccMot();
    KF_Mot.correct(measurement_pos);
    *post_position = getCurrentStateMot();
    *post_velocity = getVelocityMot();
    *post_Accelerate = getAccMot();
    *vcc = extract_actual_v(curr_cond);
    *acc = extract_actual_a((double)vcc->x,(double)vcc->y);
}

