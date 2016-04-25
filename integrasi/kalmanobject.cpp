#include "kalmanobject.h"

KalmanObject::KalmanObject(Player currentData, float interval)
{
    KF.init(6, 2, 0, CV_32F);
    counter = 0; //kalman filter baru diinisiasi
    maxCounter = 10;
    id = currentData.id;
    frameInterval = interval; //seconds
    previous = currentData;
    prediction = currentData;

    //initialize kalman filter
    measurement.setTo(Scalar(0));
    KF.transitionMatrix =  (Mat_<float>(6, 6) <<
                            1, 0,   (float)frameInterval,          0,                       0.5 * (float)frameInterval * (float)frameInterval,            0,
                            0, 1,   0,                             (float)frameInterval,    0,                                                            0.5 * (float)frameInterval * (float)frameInterval,
                            0, 0,   1,                             0,                       (float)frameInterval,                                         0,
                            0, 0,   0,                             1,                       0,                                                            (float)frameInterval,
                            0, 0,   0,                             0,                       1,                                                            0,
                            0, 0,   0,                             0,                       0,                                                            1
                           );
    KF.statePost.at<float>(0) = currentData.pos.x;
    KF.statePost.at<float>(1) = currentData.pos.y;
    KF.statePost.at<float>(2) = 0;
    KF.statePost.at<float>(3) = 0;
    KF.statePost.at<float>(4) = 0;
    KF.statePost.at<float>(5) = 0;
    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.measurementNoiseCov, Scalar::all(5));
    setIdentity(KF.errorCovPost, Scalar::all(0.1));
    ////qDebug() << "Kalman Filter initialized";
}

KalmanObject::~KalmanObject()
{

}

void KalmanObject::predict() {
    Mat state = KF.predict();
    prediction.id = previous.id;
    prediction.camera = previous.camera;
    prediction.framePosition = previous.framePosition;
    prediction.cameraPos.x = previous.cameraPos.x;
    prediction.cameraPos.y = previous.cameraPos.y;
    prediction.pos.x = state.at<float>(0);
    prediction.pos.y = state.at<float>(1);
    prediction.speed.x = state.at<float>(2);
    prediction.speed.y = state.at<float>(3);
    prediction.acceleration.x = state.at<float>(4);
    prediction.acceleration.y = state.at<float>(5);
    ////qDebug() << "Masuk sini bos 2";
}


void KalmanObject::correct(Player currentData) {
    previous = currentData;

    Mat_<float> measurement(2, 1);
    measurement(0) = currentData.pos.x;
    measurement(1) = currentData.pos.y;
    KF.correct(measurement);
}
