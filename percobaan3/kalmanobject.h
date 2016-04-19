#ifndef KALMANOBJECT_H
#define KALMANOBJECT_H
#define NUMBER_OF_STATE 6
#define NUMBER_OF_MEASUREMENT 6

#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <string>
#include <QList>
#include <QObject>
#include <QPoint>
#include "player.h"

using namespace cv;
using namespace std;

class KalmanObject:public QObject
{
    Q_OBJECT
public:
    KalmanObject(int identity,int FrameRate);
    ~KalmanObject();
    int id;
    Player measuredData;
    KalmanFilter KF;
    int counter;
    void process_KalmanObject(Player measurementData);
    Player prediction;
private:
    void initializeKalman();
    double intervals;
    Mat state;
    Mat statePost;
};

#endif // KALMANOBJECT_H
