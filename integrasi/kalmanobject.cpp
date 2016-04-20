#include "kalmanobject.h"

KalmanObject::KalmanObject(Player currentData, double interval)
{
    KalmanFilter KF(NUMBER_OF_STATE, NUMBER_OF_MEASUREMENT, 0, CV_32F);
    id = currentData.id;
    counter = 0;
    frameInterval = interval; //seconds
    previousData = currentData;
    //initialize kalman filter

    KF.statePre.at<float>(0) = (float)currentData.pos.x;
    KF.statePre.at<float>(1) = (float)currentData.pos.y;
    KF.statePre.at<float>(2) = (float)currentData.speed.x;
    KF.statePre.at<float>(3) = (float)currentData.speed.y;
    KF.statePre.at<float>(4) = (float)currentData.acceleration.x;
    KF.statePre.at<float>(5) = (float)currentData.acceleration.y;

    KF.transitionMatrix =  *(Mat_<float>(NUMBER_OF_MEASUREMENT, NUMBER_OF_STATE) << 1, 0,    (float)frameInterval,          0,      0.5 * (float)frameInterval * (float)frameInterval,            0,
                             0, 1,            0,  (float)frameInterval,                            0, 0.5 * (float)frameInterval * (float)frameInterval,
                             0, 0,            1,          0,                      (float)frameInterval,          0,
                             0, 0,            0,          1,                              0,   (float)frameInterval,
                             0, 0,            0,          0,                              1,          0,
                             0, 0,            0,          0,                              0,          1
                            );
    setIdentity(KF.processNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-3));
    setIdentity(KF.errorCovPost, Scalar::all(0.1));
    Mat_<float> state(NUMBER_OF_STATE, 1);
    qDebug() << "Kalman Filter initialized";
}

KalmanObject::~KalmanObject()
{

}

void KalmanObject::process(Player currentData) {
    counter++;
    current.id = currentData.id;
    current.camera = currentData.camera;
    current.framePosition = currentData.framePosition;
    current.pos.x = currentData.pos.x;
    current.pos.y = currentData.pos.y;
    current.acceleration.x = currentData.acceleration.x;
    current.acceleration.y = currentData.acceleration.y;
    current.transformedPos.x = currentData.transformedPos.x;
    current.transformedPos.y = currentData.transformedPos.y;
    //generate measurement
    measurement.id = currentData.id;
    measurement.camera = currentData.camera;
    measurement.framePosition = currentData.framePosition;
    measurement.pos = currentData.pos;
    measurement.speed.x = (currentData.pos.x - previousData.pos.x) / frameInterval;
    measurement.speed.y = (currentData.pos.y - previousData.pos.y) / frameInterval;
    current.speed.x = measurement.speed.x;
    current.speed.y = measurement.speed.y;
    measurement.acceleration.x = (current.speed.x - previousData.speed.x) / frameInterval;
    measurement.acceleration.y = (current.speed.y - previousData.speed.y) / frameInterval;
    measurement.transformedPos.x = currentData.transformedPos.x;
    measurement.transformedPos.y = currentData.transformedPos.y;

    if (counter < 2) {
        prediction.id = measurement.id;
        prediction.camera = measurement.camera;
        prediction.framePosition = measurement.framePosition;
        prediction.pos.x = measurement.pos.x;
        prediction.pos.y = measurement.pos.y;
        prediction.speed.y = measurement.speed.x;
        prediction.acceleration.x = measurement.acceleration.x;
        prediction.acceleration.y = measurement.acceleration.y;
        prediction.transformedPos.x = measurement.transformedPos.x;
        prediction.transformedPos.y = measurement.transformedPos.y;
    } else {
        if (counter == 2) {
            KF.statePost.at<float>(0) = measurement.pos.x;
            KF.statePost.at<float>(1) = measurement.pos.y;
            KF.statePost.at<float>(2) = measurement.speed.x;
            KF.statePost.at<float>(3) = measurement.speed.y;
            KF.statePost.at<float>(4) = measurement.acceleration.x;
            KF.statePost.at<float>(5) = measurement.acceleration.y;
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
        prediction.transformedPos.x = measurement.transformedPos.x;
        prediction.transformedPos.x = measurement.transformedPos.y;
    }

    previousData = current;
}

