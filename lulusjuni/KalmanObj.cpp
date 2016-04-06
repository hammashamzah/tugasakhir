#include "KalmanObj.h"

#define DEBUG

Kalmanobj::Kalmanobj(int camera_id,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double fr){
    camera = camera_id;
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


void Kalmanobj::resetdata(){
    int i,j;
    for(i=0;i<sizePrevious;i++){
        int k = 0;
        for(j=0;j<sizeCurrent;j++){
            if(previousData.at(i).id == currentData.at(j).id){
                k++;
            }
        }
        if(k > 0){
            accel[i].x=0.00;
            accel[i].y=0.00;
            pre_velocity[i].x=0.00;
            pre_velocity[i].y=0.00;
            post_velocity[i].x=0.00;
            post_velocity[i].y=0.00;
            post_pos[i].x=0.00;
            post_pos[i].y=0.00;
        }
    }
}

void Kalmanobj::accum_kalmanobj(QList<DataInputCam> init,QList<DataInputCam> current,int frm){
    int i;
    frames = frm;
    initsData = init;
    previousData.clear();
    previousData = currentData;
    currentData.clear();
    currentData = current;
    sizeCurrent = currentData.length();
    sizePrevious = previousData.length();
    intervals = 1/FrPs;
    if(frames == 1){
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
    emit updatePrediction(predictionData);
    emit sendPrevious(prev);

    Isset1=false;
    Isset2=false;
    Isset3=false;
    currentData.clear();
    initsData.clear();
}

Kalmanobj::~Kalmanobj(){
    
}

void Kalmanobj::multitrackObj(){
    int i;
    DataInputCam buffer,buffer2;
    Point2f priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp;
    double pred_h,pred_w;
    for(i=0;i<sizeCurrent;i++){
        //track_ind3Dmotion(currentData.at(i)priory_pos,priory_vels,priory_acc,post_pos,post_vels,post_acc);
        track_ind2Dmotion(currentData.at(i),priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp);
        //Node *list_get = list1.searchNode(list_init,list_curr->data_id);
        track_size(pred_w, pred_h,initsData.at(currentData.at(i).id),currentData.at(i));

        buffer2.id = currentData.at(i).id;
        buffer2.dataplayer.x = (double)currentData.at(i).dataplayer.x;
        buffer2.dataplayer.y = (double)currentData.at(i).dataplayer.y;
        buffer2.dataplayer.width = currentData.at(i).dataplayer.width;
        buffer2.dataplayer.height = currentData.at(i).dataplayer.height;
        buffer2.status = (double)currentData.at(i).status;
        buffer2.flagOcclusion = (double)currentData.at(i).flagOcclusion;
        buffer2.pixelSpeed.x = (double)pre_velocity[i].x;
        buffer2.pixelSpeed.y = (double)pre_velocity[i].y;

        buffer.id = currentData.at(i).id;
        buffer.dataplayer.x = (double)post_posp.x;
        buffer.dataplayer.y = (double)post_posp.y;
        buffer.dataplayer.width = pred_w;
        buffer.dataplayer.height = pred_h;
        buffer.status = (double)currentData.at(i).status;
        buffer.flagOcclusion = (double)currentData.at(i).flagOcclusion;
        buffer.pixelSpeed.x = (double)post_velsp.x;
        buffer.pixelSpeed.y = (double)post_velsp.y;
        predictionData.append(buffer);
        prev.append(buffer2);
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
    state_pos.x = statePost.at<double>(2);
    state_pos.y = statePost.at<double>(3);
    return (state_pos);
}

Point2f Kalmanobj::getAccMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(4);
    state_pos.y = statePost.at<double>(5);
    return (state_pos);
}

void Kalmanobj::extract_actual_v(double curr_posx,double curr_posy,int idx){
        post_pos[idx].x= curr_pos[idx].x;
        post_pos[idx].y= curr_pos[idx].y;
        curr_pos[idx].x= curr_posx;
        curr_pos[idx].y= curr_posy;
        post_velocity[idx] = pre_velocity[idx];
        pre_velocity[idx].x = (curr_pos[idx].x-post_pos[idx].x)/intervals;
        pre_velocity[idx].y = (curr_pos[idx].y-post_pos[idx].y)/intervals;
}

void Kalmanobj::extract_actual_a(int idx){
   accel[idx].x = (pre_velocity[idx].x-post_velocity[idx].x)/intervals;
   accel[idx].y = (pre_velocity[idx].y-post_velocity[idx].y)/intervals;

}

void Kalmanobj::track_size(double &pred_h,double &pred_w,DataInputCam reff,DataInputCam curr){
    /*koordinate titik hilang*/
    double yo =((XDR-XDL)/(((-XDL+XUL)/(YDL-YUL))+((XDR-XUR)/(YDR-YUR))))-((YDL+YDR)/2);
    double perb_init = (-((double)reff.dataplayer.y)+((YDL+YDR)/2))/(((double)((double)reff.dataplayer.width))-yo);
    double perb_act = (((double)curr.dataplayer.y)-yo)/((((double)curr.dataplayer.y)-yo)+((reff.dataplayer.y)-((YDL+YDR)/(2))));
    double width_pres = (1+perb_init)*((double)curr.dataplayer.width);
    double height_pres = (1+perb_init)*((double)curr.dataplayer.height);
    pred_w = width_pres * perb_act;
    pred_h = height_pres * perb_act;
}

void Kalmanobj::track_ind2Dmotion(DataInputCam curr_cond, Point pre_pos,Point pre_veloc,Point pre_Acce,Point post_pos,Point post_veloc,Point post_Acce){
    initKalmanMOt((double)curr_cond.dataplayer.x, (double)curr_cond.dataplayer.y,(double)pre_velocity[curr_cond.id].x,(double)pre_velocity[curr_cond.id].y,(double)accel[curr_cond.id].x, (double)accel[curr_cond.id].y);
    KF_Mot.predict();
    pre_pos = getCurrentStateMot();
    pre_veloc = getVelocityMot();
    pre_Acce = getAccMot();
    KF_Mot.correct(measurement_pos);
    post_pos = getCurrentStateMot();
    post_veloc = getVelocityMot();
    post_Acce = getAccMot();
    extract_actual_v((double)curr_cond.dataplayer.x,(double)curr_cond.dataplayer.y,curr_cond.id);
    extract_actual_a(curr_cond.id);
}

