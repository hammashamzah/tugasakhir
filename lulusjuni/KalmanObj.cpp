#include "KalmanObj.h"
#define DEBUG

Kalmanobj::Kalmanobj(int camera_id,bool start,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double fr){
    camera = camera_id;
    mulai = start;
    XDL = xdl;
    XDR = xdr;
    XUL = xul;
    XUR = xur;
    YDL = ydl;
    YDR = ydr;
    YUL = yul;
    YUR = yur;
    FrPs = fr;
}

void Kalmanobj::accum_kalmanobj(int start,int Num_Obj){
    int i;
    frame_start = start;
    intervals = 1/FrPs;
    Object_Number = Num_Obj;
    if(frame_start == 1){
        for(i=0;i<23;i++){
            post_pos[i].x=0.00;
            post_pos3d[i].x=0.00;
            pre_velocity[i].x=0.00;
            pre_velocity3d[i].x=0.00;
            accel[i].x=0.00;
            accel3d[i].x=0.00;
            post_pos[i].y=0.00;
            post_pos3d[i].y=0.00;
            pre_velocity[i].y=0.00;
            pre_velocity3d[i].y=0.00;
            accel[i].y=0.00;
            accel3d[i].y =0.00;
        }
    }
}

Kalmanobj::~Kalmanobj(){
    
}

void Kalmanobj::multitrackObj(struct Node* init_symp, Node* current_symp){
    Node *list_curr = current_symp;
    Node *list_init = init_symp;
    Point2f priory_pos,priory_vels,priory_acc,post_pos,post_vels,post_acc;
    Point2f priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp;
    double pred_h,pred_w;
    while(list_curr!=NULL){
        predict_track = new Node;
        track_ind3Dmotion(list_curr,priory_pos,priory_vels,priory_acc,post_pos,post_vels,post_acc);
        track_ind2Dmotion(list_curr,priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp);
        Node *list_get = list1.searchNode(list_init,list_curr->data_id);
        track_size(pred_w, pred_h,list_get,list_curr);
        predict_track->data_id = list_curr->data_id;
        predict_track->val_x = (double)post_posp.x;
        predict_track->val_y = (double)post_posp.y;
        predict_track->x_trans = (double)post_pos.x;
        predict_track->y_trans = (double)post_pos.y;
        predict_track->val_w = pred_w;
        predict_track->val_h = pred_h;
        predict_track->vx_trans = (double)post_vels.x;
        predict_track->vy_trans = (double)post_vels.y;
        predict_track->flag = list_curr->flag;
        predict_track = predict_track->next;
        list_curr = list_curr->next;
    }
}

void Kalmanobj::initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y){
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


Point2f Kalmanobj::getCurrentStateMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}

Point2f Kalmanobj::getVelocityMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}

Point2f Kalmanobj::getAccMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}

void Kalmanobj::extract_actual_v(double curr_posx,double curr_posy,int idx,int rep){
    if(rep==1){/*untuk 3d coordinate*/
        post_pos3d[idx]= curr_pos3d[idx];
        curr_pos3d[idx].x= curr_posx;
        curr_pos3d[idx].y= curr_posy;
        post_velocity3d[idx] = pre_velocity3d[idx];
        pre_velocity3d[idx].x = (curr_pos3d[idx].x-post_pos3d[idx].x)/intervals;
        pre_velocity3d[idx].y = (curr_pos3d[idx].y-post_pos3d[idx].y)/intervals;
    }
    else{/*untuk 2d coordinate*/
        post_pos[idx]= curr_pos[idx];
        curr_pos[idx].x= curr_posx;
        curr_pos[idx].y= curr_posy;
        post_velocity[idx] = pre_velocity[idx];
        pre_velocity[idx].x = (curr_pos[idx].x-post_pos[idx].x)/intervals;
        pre_velocity[idx].y = (curr_pos[idx].y-post_pos[idx].y)/intervals;
    }
}

void Kalmanobj::extract_actual_a(int idx,int rep){
    if(rep==1){/*untuk 3d coordinate*/
        accel3d[idx].x = (pre_velocity3d[idx].x-post_velocity3d[idx].x)/intervals;
        accel3d[idx].y = (pre_velocity3d[idx].y-post_velocity3d[idx].y)/intervals;
    }
    else{/*untuk 2d coordinate*/
        accel[idx].x = (pre_velocity[idx].x-post_velocity[idx].x)/intervals; 
        accel[idx].y = (pre_velocity[idx].y-post_velocity[idx].y)/intervals;    
    }
}

void Kalmanobj::track_size(double &pred_w, double &pred_h,struct Node* init_matric,struct Node* curr_matric){
    /*koordinate titik hilang*/
    double yo =((XDR-XDL)/(((-XDL+XUL)/(YDL-YUL))+((XDR-XUR)/(YDR-YUR))))-((YDL+YDR)/2);
    double perb_init = (-(init_matric->val_y)+((YDL+YDR)/2))/((init_matric->val_y)-yo);
    double perb_act = ((curr_matric->val_y)-yo)/(((curr_matric->val_y)-yo)+((init_matric->val_y)-((YDL+YDR)/(2))));
    double width_pres = (1+perb_init)*curr_matric->val_w;
    double height_pres = (1+perb_init)*curr_matric->val_h;
    pred_w = width_pres * perb_act;
    pred_h = height_pres * perb_act;
}

void Kalmanobj::track_ind2Dmotion(struct Node* curr_cond, Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce){
    int rep = 1;
    initKalmanMOt((double)curr_cond->val_x, (double)curr_cond->val_y,(double)pre_velocity[curr_cond->data_id].x,(double)pre_velocity[curr_cond->data_id].y,(double)accel[curr_cond->data_id].x, (double)accel[curr_cond->data_id].y);
    KF_Mot.predict();
    pre_pos = getCurrentStateMot();
    pre_veloc = getVelocityMot();
    pre_Acce = getAccMot();
    KF_Mot.correct(measurement_pos);
    post_pos = getCurrentStateMot();
    post_veloc = getVelocityMot();
    post_Acce = getAccMot();
    extract_actual_v((double)curr_cond->val_x,(double)curr_cond->val_y,curr_cond->data_id,rep);
    extract_actual_a(curr_cond->data_id,rep);
}

void Kalmanobj::track_ind3Dmotion(struct Node* curr_cond, Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce){
    int rep = 2;
    initKalmanMOt((double)curr_cond->val_x, (double)curr_cond->val_y,(double)pre_velocity3d[curr_cond->data_id].x,(double)pre_velocity3d[curr_cond->data_id].y,(double)accel3d[curr_cond->data_id].x, (double)accel3d[curr_cond->data_id].y);
    KF_Mot.predict();
    pre_pos = getCurrentStateMot();
    pre_veloc = getVelocityMot();
    pre_Acce = getAccMot();
    KF_Mot.correct(measurement_pos);
    post_pos = getCurrentStateMot();
    post_veloc = getVelocityMot();
    post_Acce = getAccMot();
    extract_actual_v((double)curr_cond->val_x,(double)curr_cond->val_y,curr_cond->data_id,rep);
    extract_actual_a(curr_cond->data_id,rep);
}
