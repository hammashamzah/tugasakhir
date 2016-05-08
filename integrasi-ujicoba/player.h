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
    Player(int frame, int cameraId, Point2f cameraPosition, double blob);
    Player(int identity, int cameraId, int frame, Point2f inputPosition, Point2f inputSpeed, Point2f inputAcceleration, Point2f inputCameraPos, double blob);
    //Player(Point2f position);
    //Player(int identity, int frame,int cameraId,Point2f position,Point2f inputSpeed,Point2f inputAcceleration);
    Player& operator=(Player b);
    //destructor
    ~Player();
    //variable
    bool isValid;
    bool isOccluded;
    bool isAssociated;
    int id;
    int framePosition;
    int camera;
    double blobSize;

    cv::Point2f cameraPos;
    cv::Point2f pos;
    cv::Point2f speed;
    cv::Point2f acceleration;

    friend void swap(Player& first, Player& second) {
        using std::swap;
        swap(first.isValid, second.isValid);
        swap(first.isOccluded, second.isOccluded);
        swap(first.id, second.id);
        swap(first.framePosition, second.framePosition);
        swap(first.camera, second.camera);
        swap(first.cameraPos.x, second.cameraPos.x);
        swap(first.cameraPos.y, second.cameraPos.y);
        swap(first.pos.x, second.pos.x);
        swap(first.pos.y, second.pos.y);
        swap(first.speed.x, second.speed.x);
        swap(first.speed.y, second.speed.y);
        swap(first.acceleration.x, second.acceleration.x);
        swap(first.acceleration.y, second.acceleration.y);
        swap(first.blobSize, second.blobSize);
    }
};

#endif // PLAYER_H
