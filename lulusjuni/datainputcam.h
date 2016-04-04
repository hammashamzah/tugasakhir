#ifndef DATAINPUTCAM_H
#define DATAINPUTCAM_H

#include "opencv/cv.h"
#include "objectvariable.h"
#include <QObject>
using namespace cv;



class Datainputcam{
    public:
        int id;
        Rect playerData;
        bool flagOcclusion;
        int status;
        Datainputcam (int identity, Rect Player_dat, int stats, bool fo);
        ~Datainputcam();
};


#endif // DATAINPUTCAM_H
