#ifndef GENERATEMATTRANS_H
#define GENERATEMATTRANS_H

#include "opencv/ml.h"
#include "opencv2/legacy/legacy.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <cmath>
#include <QList>
#include <QPoint>
#include <QObject>
#include <player.h>

using namespace cv;
using namespace std;

class TransformedObjectProcessor:public QObject
{
    Q_OBJECT
    public:
        explicit TransformedObjectProcessor(QObject *parent = 0);
        TransformedObjectProcessor(double trehshold);
        ~TransformedObjectProcessor();
        void cam_associate();
    private:
        Mat Associate;
        double THETA;
        bool IsSetMat,IsSetDataTrans,IsOccSet;

        QList <Player> lost;
        QList <Player> found;
        QList <Player> remaindedData;
        Mat associate;
        
        double Euclid_r;
        void link_theid();
        double eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj);
    public slots:
        void getDataTrans(QList<DataInputTrans>);//dari Aznan
   signals:
        void sendAssociateBoundary(Mat);//menuju objassociate
        void UpdateremaindedData(QList<int>);//menuju objassociate

};


#endif // GENERATEMATTRANS_H
