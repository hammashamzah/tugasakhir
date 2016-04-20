#include "kalmanobject.h"

KalmanObject::KalmanObject(Player currentData, float interval)
{
    KalmanFilter KF(6, 2, 0, CV_32F);
    id = currentData.id;
    frameInterval = interval; //seconds
    previous.id = currentData.id;
    previous.camera = currentData.camera;
    previous.framePosition = currentData.framePosition;
    previous.pos.x = currentData.pos.x;
    previous.pos.y = currentData.pos.y;
    previous.speed.x = currentData.speed.x;
    previous.speed.y = currentData.speed.y;
    previous.acceleration.x = currentData.acceleration.x;
    previous.acceleration.y = currentData.acceleration.y;
    previous.transformedPos.x = currentData.transformedPos.x;
    previous.transformedPos.x = currentData.transformedPos.y;

    prediction.id = currentData.id;
    prediction.camera = currentData.camera;
    prediction.framePosition = currentData.framePosition;
    prediction.pos.x = currentData.pos.x;
    prediction.pos.y = currentData.pos.y;
    prediction.speed.x = currentData.speed.x;
    prediction.speed.y = currentData.speed.y;
    prediction.acceleration.x = currentData.acceleration.x;
    prediction.acceleration.y = currentData.acceleration.y;
    prediction.transformedPos.x = currentData.transformedPos.x;
    prediction.transformedPos.x = currentData.transformedPos.y;

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
    KF.statePost.at<float>(0) = (float)currentData.pos.x;
    KF.statePost.at<float>(1) = (float)currentData.pos.y;
    KF.statePost.at<float>(2) = 0;
    KF.statePost.at<float>(3) = 0;
    KF.statePost.at<float>(4) = 0;
    KF.statePost.at<float>(5) = 0;
    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.measurementNoiseCov, Scalar::all(5));
    setIdentity(KF.errorCovPost, Scalar::all(0.1));
    qDebug() << "Kalman Filter initialized";
}

KalmanObject::~KalmanObject()
{

}

void KalmanObject::processData(Player currentData) {
    qDebug() << "Masuk sini bos";
    //generate measurement
    qDebug() << currentData.pos.x << " " << currentData.pos.y << " " << previous.pos.x << " "
             << previous.pos.y << " " << currentData.speed.x << " " << currentData.speed.y << " "
             << previous.speed.x << " " << previous.speed.y << " " << frameInterval;;
    Mat_<float> measurement(2, 1);

    measurement(0) = currentData.pos.x;
    measurement(1) = currentData.pos.y;
    //measurement(2) = (currentData.pos.x - previous.pos.x) / frameInterval;
    //measurement(3) = (currentData.pos.y - previous.pos.y) / frameInterval;
    //measurement(4) = (currentData.speed.x - previous.speed.x) / frameInterval;
    //measurement(5) = (currentData.speed.y - previous.speed.y) / frameInterval;
    qDebug() << "Masuk sini bos 1";

    Mat state = KF.predict();
    prediction.id = currentData.id;
    prediction.camera = currentData.camera;
    prediction.framePosition = currentData.framePosition;
    prediction.pos.x = state.at<float>(0);
    prediction.pos.y = state.at<float>(1);
    prediction.speed.x = state.at<float>(2);
    prediction.speed.y = state.at<float>(3);
    prediction.acceleration.x = state.at<float>(4);
    prediction.acceleration.y = state.at<float>(5);
    prediction.transformedPos.x = currentData.transformedPos.x;
    prediction.transformedPos.x = currentData.transformedPos.y;
    qDebug() << "Masuk sini bos 2";

    KF.correct(measurement);
    qDebug() << "Masuk sini bos 3";

    previous.id = currentData.id;
    previous.camera = currentData.camera;
    previous.framePosition = currentData.framePosition;
    previous.pos.x = currentData.pos.x;
    previous.pos.y = currentData.pos.y;
    previous.speed.x = currentData.speed.x;
    previous.speed.y = currentData.speed.y;
    previous.acceleration.x = currentData.acceleration.x;
    previous.acceleration.y = currentData.acceleration.y;
    previous.transformedPos.x = currentData.transformedPos.x;
    previous.transformedPos.x = currentData.transformedPos.y;
    qDebug() << "selesai sini";
}

