#include "kalmanpredictor.h"
#define DEBUG

KalmanPredictor::KalmanPredictor(QList<QPoint> trapeziumCoordinate,double fr){
    XDL = trapeziumCoordinate[0].x();
    XDR = trapeziumCoordinate[3].x();
    XUL = trapeziumCoordinate[1].x();
    XUR = trapeziumCoordinate[2].x();
    YDL = trapeziumCoordinate[0].y();
    YDR = trapeziumCoordinate[3].y();
    YUL = trapeziumCoordinate[1].y();
    YUR = trapeziumCoordinate[2].y();
    FrPs = fr;
    intervals = 1/FrPs;
    yo =-((XDR-XDL)/(((-XDL+XUL)/(YDL-YUL))+((XDR-XUR)/(YDR-YUR))))+((YDL+YDR)/2);
    searchingdata = new SearchPlayerData();
    currentData.clear();
    previousData.clear();
}
KalmanPredictor::~KalmanPredictor(){

}
void KalmanPredictor::getDataCurr(QList<Player> current){
    previousData.clear();
    previousData = currentData;
    currentData.clear();
    currentData = current;
    sizeCurrent = currentData.length();
    sizePrevious = previousData.length();
        
    accum_kalmanobj();
}
void KalmanPredictor::resetdata(){
    int i,j;
    for(i=0;i<sizePrevious;i++){
        int k = 0;
        for(j=0;j<sizeCurrent;j++){
            if(previousData.at(i).id == currentData.at(j).id){
                k++;
            }
        }
        if(k == 0){//lost data
                accel[previousData.at(i).id].x=0.00;
                accel[previousData.at(i).id].y=0.00;
                pre_velocity[previousData.at(i).id].x=0.00;
                pre_velocity[previousData.at(i).id].y=0.00;
                post_velocity[previousData.at(i).id].x=0.00;
                post_velocity[previousData.at(i).id].y=0.00;
                post_pos[previousData.at(i).id].x=0.00;
                post_pos[previousData.at(i).id].y=0.00;
        }
    }
}
void KalmanPredictor::accum_kalmanobj(){
        int i;
        if(previousData.isEmpty()){
            for(i=0;i<JUMLAH_PLAYER;i++){
                post_pos[i].x       = 0.00;
                pre_velocity[i].x   = 0.00;
                accel[i].x          = 0.00;
                post_pos[i].y       = 0.00;
                pre_velocity[i].y   = 0.00;
                accel[i].y          = 0.00;
            }
        }
        else{
            if(sizeCurrent < sizePrevious){
                resetdata();
            }
            multitrackObj();
        }
 //   sendPrediction(predictionData);
 //   sendPrevious(previousData);
}

void KalmanPredictor::multitrackObj(){
    int i;
    Player buffer,buffer2;
    Point2f priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp;
    //double pred_h,pred_w;
    for(i=0;i<sizeCurrent;i++){
        track_ind2Dmotion(currentData.at(i),priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp);
        //track_size(pred_w, pred_h,initsData.at(currentData.at(i).id),currentData.at(i));
        buffer2.id = currentData.at(i).id;
        buffer2.pos.x = (double)currentData.at(i).pos.x;
        buffer2.pos.y = (double)currentData.at(i).pos.y;
        buffer2.speed.x = (double)pre_velocity[i].x;
        buffer2.speed.y = (double)pre_velocity[i].y;

        buffer.id = currentData.at(i).id;
        buffer.pos.x = (double)post_posp.x;
        buffer.pos.y = (double)post_posp.y;
        buffer.speed.x = (double)post_velsp.x;
        buffer.speed.y = (double)post_velsp.y;
        predictionData.append(buffer);
        prev.append(buffer2);
    }
}
void KalmanPredictor::initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y){
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
Point2f KalmanPredictor::getCurrentStateMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}
Point2f KalmanPredictor::getVelocityMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(2);
    state_pos.y = statePost.at<double>(3);
    return (state_pos);
}
Point2f KalmanPredictor::getAccMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(4);
    state_pos.y = statePost.at<double>(5);
    return (state_pos);
}
void KalmanPredictor::extract_actual_v(double curr_posx,double curr_posy,int idx){
        post_pos[idx].x= curr_pos[idx].x;
        post_pos[idx].y= curr_pos[idx].y;
        curr_pos[idx].x= curr_posx;
        curr_pos[idx].y= curr_posy;
        post_velocity[idx] = pre_velocity[idx];
        pre_velocity[idx].x = (curr_pos[idx].x-post_pos[idx].x)/intervals;
        pre_velocity[idx].y = (curr_pos[idx].y-post_pos[idx].y)/intervals;
}

void KalmanPredictor::extract_actual_a(int idx){
   accel[idx].x = (pre_velocity[idx].x-post_velocity[idx].x)/intervals;
   accel[idx].y = (pre_velocity[idx].y-post_velocity[idx].y)/intervals;
}
void KalmanPredictor::track_ind2Dmotion(Player curr_cond, Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce){
    initKalmanMOt((double)curr_cond.pos.x, (double)curr_cond.pos.y,(double)pre_velocity[curr_cond.id].x,(double)pre_velocity[curr_cond.id].y,(double)accel[curr_cond.id].x, (double)accel[curr_cond.id].y);
    KF_Mot.predict();
    pre_pos = getCurrentStateMot();
    pre_veloc = getVelocityMot();
    pre_Acce = getAccMot();
    KF_Mot.correct(measurement_pos);
    post_pos = getCurrentStateMot();
    post_veloc = getVelocityMot();
    post_Acce = getAccMot();
    extract_actual_v((double)curr_cond.pos.x,(double)curr_cond.pos.y,curr_cond.id);
    extract_actual_a(curr_cond.id);
}
