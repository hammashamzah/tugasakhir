#include "kalmanobj3d.h"

#define DEBUG

Kalmanobj3D::Kalmanobj3D(double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double fr){
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

void Kalmanobj3D::updateCurrentData(QList<DataInputTrans> current){
    previousData.clear();
    previousData = currentData;
    currentData = current;
    sizeCurrent = currentData.length();
    sizePrevious = previousData.length();
    Isset1 = true;
}
void Kalmanobj3D::updateInitsData(QList<DataInputTrans> init){
    initsData = init;
    sizeInit = initsData.length();
    Isset2 = true;
}
void Kalmanobj3D::updateFrame(int frm){
    frames = frm;
    Isset3 = true;
}

void Kalmanobj3D::resetdata(){
    int i,j;
    for(i=0;i<sizePrevious;i++){
        int k = 0;
        for(j=0;j<sizeCurrent;j++){
            if(previousData.at(i).id == currentData.at(j).id){
                k++;
            }
        }
        if(k > 0){
            accel3d[i].x=0.00;
            accel3d[i].y=0.00;
            pre_velocity3d[i].x=0.00;
            pre_velocity3d[i].y=0.00;
            post_velocity3d[i].x=0.00;
            post_velocity3d[i].y=0.00;
            post_pos3d[i].x=0.00;
            post_pos3d[i].y=0.00;
        }
    }
}

void Kalmanobj3D::accum_kalmanobj(){
    int i;
    intervals = 1/FrPs;
    if(Isset1 & Isset2 & Isset3){
        if(frames == 1){
            for(i=0;i<JUMLAH_PLAYER;i++){
                post_pos3d[i].x       = 0.00;
                pre_velocity3d[i].x   = 0.00;
                accel3d[i].x          = 0.00;
                post_pos3d[i].y       = 0.00;
                pre_velocity3d[i].y   = 0.00;
                accel3d[i].y          = 0.00;
            }
        }
        else{
            if(sizeCurrent < sizePrevious){
                resetdata();
            }
            multitrackObj();
        }
    }
    emit updatePrediction(predictionData);
    Isset1=false;
    Isset2=false;
    Isset3=false;
    currentData.clear();
    initsData.clear();
}

Kalmanobj3D::~Kalmanobj3D(){

}

void Kalmanobj3D::multitrackObj(){
    int i;
    DataInputTrans buffer;
    Point2f priory_pos,priory_vels,priory_acc,post_pos,post_vels,post_acc;
    for(i=0;i<sizeCurrent;i++){
        track_ind3Dmotion(currentData.at(i),priory_pos,priory_vels,priory_acc,post_pos,post_vels,post_acc);
        buffer.id = currentData.at(i).id;
        buffer.Pos_trans.x = (double)post_pos.x;
        buffer.Pos_trans.y = (double)post_pos.y;

        buffer.flag = (double)currentData.at(i).flag;
        buffer.speed.x = (double)post_vels.x;
        buffer.speed.y = (double)post_vels.y;
        predictionData.append(buffer);
    }
}

void Kalmanobj3D::initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y){
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


Point2f Kalmanobj3D::getCurrentStateMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}

Point2f Kalmanobj3D::getVelocityMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(2);
    state_pos.y = statePost.at<double>(3);
    return (state_pos);
}

Point2f Kalmanobj3D::getAccMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(4);
    state_pos.y = statePost.at<double>(5);
    return (state_pos);
}

void Kalmanobj3D::extract_actual_v(double curr_posx,double curr_posy,int idx){
        post_pos3d[idx]= curr_pos3d[idx];
        curr_pos3d[idx].x= curr_posx;
        curr_pos3d[idx].y= curr_posy;
        post_velocity3d[idx] = pre_velocity3d[idx];
        pre_velocity3d[idx].x = (curr_pos3d[idx].x-post_pos3d[idx].x)/intervals;
        pre_velocity3d[idx].y = (curr_pos3d[idx].y-post_pos3d[idx].y)/intervals;
}

void Kalmanobj3D::extract_actual_a(int idx){
        accel3d[idx].x = (pre_velocity3d[idx].x-post_velocity3d[idx].x)/intervals;
        accel3d[idx].y = (pre_velocity3d[idx].y-post_velocity3d[idx].y)/intervals;
}

void Kalmanobj3D::track_ind3Dmotion(DataInputTrans curr_cond,Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce){
    initKalmanMOt((double)curr_cond.Pos_trans.x, (double)curr_cond.Pos_trans.y,(double)pre_velocity3d[curr_cond.id].x,(double)pre_velocity3d[curr_cond.id].y,(double)accel3d[curr_cond.id].x, (double)accel3d[curr_cond.id].y);
    KF_Mot.predict();
    pre_pos = getCurrentStateMot();
    pre_veloc = getVelocityMot();
    pre_Acce = getAccMot();
    KF_Mot.correct(measurement_pos);
    post_pos = getCurrentStateMot();
    post_veloc = getVelocityMot();
    post_Acce = getAccMot();
    extract_actual_v((double)curr_cond.Pos_trans.x,(double)curr_cond.Pos_trans.y,curr_cond.id);
    extract_actual_a(curr_cond.id);
}

