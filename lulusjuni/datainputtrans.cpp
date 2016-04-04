#include "datainputtrans.h"

DataInputTrans::DataInputTrans(Point2f posisi,Point2f velo,Point2f acc,bool f,int identity)
{
    Pos_trans = posisi;
    speed = velo;
    accel = acc;
    id = identity;
    flag = f;
}

DataInputTrans::~DataInputTrans(){

}

