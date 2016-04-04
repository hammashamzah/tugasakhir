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
        Rect dataplayer;
        Point2f pixelSpeed;
        bool flagOcclusion;
        int status;
};

#endif // DATAINPUTCAM_H
