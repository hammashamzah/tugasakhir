#ifndef OBJASSOCIATE_H_INCLUDED
#define OBJASSOCIATE_H_INCLUDED
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include "datainputcam.h"
#include "datainputtrans.h"
#include "objectvariable.h"

using namespace cv;
using namespace std;


class Associate:public QObject
{
    Q_OBJECT
    public: 
        explicit Associate (QObject *parent = 0);
        int validate;
        Associate();
        ~Associate();
        void accum_assoc(QList<DataInputCam>,QList<DataInputCam>,QList<Point>,QList<Point>);
        Mat association_agrr;
        QList<DataInputCam>Mapping;
    private:
        void mapping();
        void AddMat();
        QList<DataInputCam>cam1;
        QList<DataInputCam>cam2;
        QList<Point>Occlussion1;
        QList<Point>Occlussion2;
        Mat assoc1;
        Mat assoc2;
        bool IsMatCam1,IsMatCam2;

   public slots:
        void updateMatCam1(Mat);//from generate MatTrans
        void updateMatCam2(Mat);//from generate MatTrans
};


#endif // OBJASSOCIATE_H_INCLUDED
