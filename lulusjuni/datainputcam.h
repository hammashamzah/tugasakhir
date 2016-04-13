#ifndef DATAINPUTCAM_H
#define DATAINPUTCAM_H
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class DataInputCam
{
    public:
        DataInputCam();
        ~DataInputCam();
        int id;
        Point2f dataplayer;
        Point2f pixelSpeed;
        bool flag;
};

#endif // DATAINPUTCAM_H
