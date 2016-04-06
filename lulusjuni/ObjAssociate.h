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
        int validate;
        Associate(mode operate);
        ~Associate();
        void accum_assoc();
        mode ops;
        bool Isset1,Isset2,Isset3,Isset4,Isset5,Isset6,Isseto,Isset7,Isset8;
        Mat association_agrr;
        QList<DataInputCam>Mapping;
    private:
        void mapping();
        void AddMat();
        QList<DataInputCam>cam1;
        QList<DataInputCam>cam2;
        QList<DataInputCam>cam3;
        QList<Point>Occlussion1;
        QList<Point>Occlussion2;
        QList<Point>Occlussion3;
        Mat assoc1;
        Mat assoc2;
        Mat assoc3;

        /**Parameter Input Class dinamik**/

   public slots:
        void getOcclusion1(QList<Point>);
        void getOcclusion2(QList<Point>);
        void getOcclusion3(QList<Point>);
        void updateMatCam1(Mat);//from generate MatCam
        void updateMatCam2(Mat);//from generate MatCam
        void updateMatCam3(Mat);//from generate MatCam
        void updateCurrentCam1(QList<DataInputCam>);// from generate MatCam
        void updateCurrentCam2(QList<DataInputCam>);//from generate MatCam
        void updateCurrentCam3(QList<DataInputCam>);//from generate MatCam
};


#endif // OBJASSOCIATE_H_INCLUDED
