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
        Player(int identity, int frame,int cam,Point2f position,Point2f kecepatan,Point2f percepatan);
        //destructor
        ~Player();
        //variable
        int id;
        int framePosition;
        int camera;
        cv::Point2f pos;
        cv::Point2f speed;
        cv::Point2f acceleration;
        cv::Point2f transformedPos;
        cv::Point2f transformedSpeed;
};

#endif // PLAYER_H
