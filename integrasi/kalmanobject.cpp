#include "kalmanobject.h"

KalmanObject::KalmanObject(Player currentData, double interval)
{
    id = currentData.id;
    counter = 0;
    frameInterval = interval; //seconds
    previousData = currentData;
    //initialize kalman filter
    Mat transitionMatrix = (Mat_<float>(NUMBER_OF_MEASUREMENT, NUMBER_OF_STATE) << 1, 0,    frameInterval,          0,      0.5 * frameInterval * frameInterval,            0,
                            0, 1,            0,  frameInterval,                            0, 0.5 * frameInterval * frameInterval,
                            0, 0,            1,          0,                      frameInterval,          0,
                            0, 0,            0,          1,                              0,   frameInterval,
                            0, 0,            0,          0,                              1,          0,
                            0, 0,            0,          0,                              0,          1
                           );


    KF.transitionMatrix = transitionMatrix;
    setIdentity(KF.processNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-3));
    setIdentity(KF.errorCovPost, Scalar::all(0.1));
    cv::Mat state(NUMBER_OF_STATE, 1, CV_32F);
}

KalmanObject::~KalmanObject()
{

}

void KalmanObject::process(Player currentData) {
    counter++;
    //generate measurement
    measurement.pos = currentData.pos;
    measurement.speed.x = (currentData.pos.x - previousData.pos.x) / frameInterval;
    measurement.speed.y = (currentData.pos.y - previousData.pos.y) / frameInterval;
    current = currentData;
    current.speed = measurement.speed;
    measurement.acceleration.x = (current.speed.x - previousData.speed.x) / frameInterval;
    measurement.acceleration.y = (current.speed.y - previousData.speed.y) / frameInterval;

    statePost = (Mat_<float>(NUMBER_OF_STATE, 1) << measurement.pos.x, measurement.pos.y,
                 measurement.speed.x, measurement.speed.y,
                 measurement.acceleration.x, measurement.acceleration.y);
    if (counter < 2) {
        prediction = measurement;
    } else {
        if (counter == 2) {
            KF.statePost = statePost;
        } else {
            KF.correct(statePost);
        }
        state = KF.predict();
        prediction.id = currentData.id;
        prediction.camera = currentData.camera;
        prediction.framePosition = currentData.framePosition;
        prediction.pos.x = state.at<float>(0);
        prediction.pos.y = state.at<float>(1);
        prediction.speed.x = state.at<float>(2);
        prediction.speed.y = state.at<float>(3);
        prediction.acceleration.x = state.at<float>(4);
        prediction.acceleration.y = state.at<float>(5);
    }

    previousData = current;
}

