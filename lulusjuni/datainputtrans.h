#ifndef DATAINPUTTRANS_H
#define DATAINPUTTRANS_H
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>

using namespace cv;
using namespace std;

class DataInputTrans
{
    public:
        DataInputTrans();
        ~DataInputTrans();
        Point2f Pos_trans;
        Point2f speed;
        Point2f accel;
        bool flag;
        int id;
};

#endif // DATAINPUTTRANS_H
