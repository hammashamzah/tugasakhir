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
        Point Pos_trans;
        Point speed;
        Point accel;
        bool flag;
        int id;
};

#endif // DATAINPUTTRANS_H
