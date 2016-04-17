#ifndef PLAYER_H
#define PLAYER_H
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class Player
{
public:
    //constructor
    Player();
    Player(int identity, int frame, int cameraId, Point2f position);
    Player(int identity, int frame, int cameraId, Point2f position,
           Point2f inputSpeed, Point2f inputTransformedPos, Point2f inputTransformedSpeed);
    Player(Point2f position);
    //destructor
    ~Player();
    //variable
    int id;
    int framePosition;
    int camera;

    cv::Point2f pos;
    cv::Point2f speed;
    cv::Point2f transformedPos;
    cv::Point2f transformedSpeed;
};

#endif // PLAYER_H
