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
#include <QDebug>
#include "player.h"

using namespace cv;
using namespace std;

class KalmanObject
{
public:
    KalmanObject(Player currentData, float interval);
    ~KalmanObject();
    void predict();
    void correct(Player currentData);
    std::string getImageType(int number);
    int id;
    Player prediction;
    Mat measurement;
    int counter;
    int maxCounter;
    float frameInterval;
    KalmanFilter KF;
    Player previous;
private:
};

#endif // KALMANOBJECT_H
