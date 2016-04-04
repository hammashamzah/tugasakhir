#ifndef ARRTRANS_H
#define ARRTRANS_H
#include "objectvariable.h"

struct DataInputTrans{
    Point2f Pos_trans;
    Point2f speed;
    Point2f accel;
    bool flag;
    int id;
};

class Arrtrans
{
public:
    DataInputTrans data[JUMLAH_PLAYER];
    Arrtrans();
    ~Arrtrans();
};

#endif // ARRTRANS_H
