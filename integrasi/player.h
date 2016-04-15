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
        Player(Point data);
        //destructor
        ~Player();
        //variable
        int id;
        cv::Point2f pos;
        cv::Point2f speed;
        cv::Point2f acceleration;
};

#endif // PLAYER_H
