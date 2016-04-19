#ifndef PLAYER_H
#define PLAYER_H
#define JUMLAH_OBJECT_MAX 50
#define BOBOT_PREDICTIONS 0.3

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <QObject>

using namespace cv;
using namespace std;

class Player:public QObject
{
    Q_OBJECT
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