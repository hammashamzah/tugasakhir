#include "kalmanobject.h"

KalmanObject::KalmanObject(int identity,int FrameRate)
{
    id = identity;
    intervals =1/((double)FrameRate);
    counter = 0;
    initializeKalman();
}

KalmanObject::~KalmanObject()
{

}

void KalmanObject::initializeKalman(){
    Mat transitionMatrix = (Mat_<float>(NUMBER_OF_MEASUREMENT,NUMBER_OF_STATE) << 1, 0,    intervals,          0,      0.5*intervals*intervals,            0,
                                                               0, 1,            0,  intervals,                            0, 0.5*intervals*intervals,
                                                               0, 0,            1,          0,                      intervals,          0,
                                                               0, 0,            0,          1,                              0,   intervals,
                                                               0, 0,            0,          0,                              1,          0,
                                                               0, 0,            0,          0,                              0,          1
                                                            );


    KF.transitionMatrix = transitionMatrix;
    setIdentity(KF.processNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-3));
    setIdentity(KF.errorCovPost, Scalar::all(0.1));
}

void KalmanObject::process_KalmanObject(Player measurementData){
    counter++;
    measuredData = measurementData;
    statePost = (Mat_<float>(NUMBER_OF_STATE, 1) << (double)measuredData.pos.x,(double)measuredData.pos.y,(double)measuredData.speed.x,(double)measuredData.speed.y,(double)measuredData.acceleration.x,(double)measuredData.acceleration.y);
    if(counter==3){
         KF.statePost = statePost;
         state = KF.predict();
         prediction.id = measuredData.id;
         prediction.camera = measuredData.camera;
         prediction.framePosition = measuredData.framePosition;
         prediction.pos.x =state.at<double>(0);
         prediction.pos.y =state.at<double>(7);
         prediction.speed.x =state.at<double>(14);
         prediction.speed.y =state.at<double>(21);
         prediction.acceleration.x =state.at<double>(28);
         prediction.acceleration.y =state.at<double>(35);
    }else if(counter > 3){
        KF.correct(statePost);
        state = KF.predict();
        prediction.id = measuredData.id;
        prediction.camera = measuredData.camera;
        prediction.framePosition = measuredData.framePosition;
        prediction.pos.x =state.at<double>(0);
        prediction.pos.y =state.at<double>(7);
        prediction.speed.x =state.at<double>(14);
        prediction.speed.y =state.at<double>(21);
        prediction.acceleration.x =state.at<double>(28);
        prediction.acceleration.y =state.at<double>(35);
    }else{
        prediction = measuredData;
    }
}

