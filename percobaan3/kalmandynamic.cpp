#include "kalmandynamic.h"

KalmanDynamic::KalmanDynamic(QList<QPoint> trapeziumCoordinate,double fr){
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
KalmanDynamic::~KalmanDynamic(){

}
void KalmanDynamic::getDataCurr(QList<Player> current){
    previousData.clear();
    previousData = currentData;
    currentData.clear();
    currentData = current;
    sizeCurrent = currentData.length();
    sizePrevious = previousData.length();      
    accum_kalmanobj();
}
void KalmanDynamic::accum_kalmanobj(){
        measuring.clear();
        multitrackObj();
        //emit sendPrediction(predictionData);
        //emit sendPrevious(previousData);
}

void KalmanDynamic::multitrackObj(){
    double vx_measurement_buffer;
    double ax_measurement_buffer;
    double vy_measurement_buffer;
    double ay_measurement_buffer;
    int idxm;
    predictionData.clear();
    for(int i=0;i<sizeCurrent;i++){
    	for(int j=0;j<sizePrevious;j++){
			int idx = searchingdata->searchPlayer(previousData,currentData.at(i).id);
			if(idx >= sizePrevious){
                measuring.append(Player(currentData.at(i).id,currentData.at(i).framePosition,currentData.at(i).camera,currentData.at(i).pos,Point2f(0,0),Point2f(0,0)));
			}    	
			else{
                idxm = searchingdata->searchPlayer(measuring,currentData.at(i).id);
				vx_measurement_buffer = (((double)currentData.at(i).pos.x)-((double)previousData.at(idx).pos.x))/intervals;
				vy_measurement_buffer = (((double)currentData.at(i).pos.y)-((double)previousData.at(idx).pos.y))/intervals;
				ax_measurement_buffer = ((vx_measurement_buffer)-(measuring.at(idxm).pos.x))/intervals;
				ay_measurement_buffer = ((vy_measurement_buffer)-(measuring.at(idxm).pos.y))/intervals;
                measuring[idxm] = Player(currentData.at(i).id,currentData.at(i).framePosition,currentData.at(i).camera,currentData.at(i).pos,Point2f(vx_measurement_buffer,vy_measurement_buffer),Point2f(ax_measurement_buffer,ay_measurement_buffer));
                track_ind2Dmotion(Player(currentData.at(i).id,currentData.at(i).framePosition,currentData.at(i).camera,currentData.at(i).pos,Point2f(vx_measurement_buffer,vy_measurement_buffer),Point2f(ax_measurement_buffer,ay_measurement_buffer)),priory_posp,priory_velsp,priory_accp,post_posp,post_velsp,post_accp);
                predictionData.append(Player(currentData.at(i).id,currentData.at(i).framePosition,currentData.at(i).camera,post_posp,post_velsp,post_accp));
            }
    	}
    }
}

void KalmanDynamic::initKalmanMOt(double pos_x, double pos_y,double v_x,double v_y,double a_x, double a_y){
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
Point2f KalmanDynamic::getCurrentStateMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(0);
    state_pos.y = statePost.at<double>(1);
    return (state_pos);
}
Point2f KalmanDynamic::getVelocityMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(2);
    state_pos.y = statePost.at<double>(3);
    return (state_pos);
}
Point2f KalmanDynamic::getAccMot() const{
    Point state_pos;
    Mat statePost = KF_Mot.statePost;
    state_pos.x = statePost.at<double>(4);
    state_pos.y = statePost.at<double>(5);
    return (state_pos);
}
void KalmanDynamic::track_ind2Dmotion(Player curr_cond, Point2f &pre_pos,Point2f &pre_veloc,Point2f &pre_Acce,Point2f &post_pos,Point2f &post_veloc,Point2f &post_Acce){
    initKalmanMOt(curr_cond.pos.x,curr_cond.pos.y,curr_cond.speed.x,curr_cond.speed.y,curr_cond.acceleration.x,curr_cond.acceleration.y);
    KF_Mot.predict();
    pre_pos = getCurrentStateMot();
    pre_veloc = getVelocityMot();
    pre_Acce = getAccMot();
    KF_Mot.correct(measurement_pos);
    post_pos = getCurrentStateMot();
    post_veloc = getVelocityMot();
    post_Acce = getAccMot();
}
