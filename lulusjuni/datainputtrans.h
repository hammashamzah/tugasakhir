#ifndef DATAINPUTTRANS_H
#define DATAINPUTTRANS_H
#include "opencv/cv.h"

class DataInputTrans
{
public:
    Point2f Pos_trans;
    Point2f speed;
    Point2f accel;
    bool flag;
    int id;
    DataInputTrans(Point2f posisi,Point2f velo,Point2f acc,bool f,int id);
    ~DataInputTrans();
};

#endif // DATAINPUTTRANS_H
