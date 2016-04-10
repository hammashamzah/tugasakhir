#ifndef TRACKING_H_INCLUDED
#define TRACKING_H_INCLUDED
/******************
#define XUL 100
#define XUR 729
#define XDR 1000
#define XDL 30
#define YUL 512
#define YUR 511
#define YDR 1000
#define YDL 1003

#define FRAME_RATE 24
*********************/

#include "fussiondatafortrans.h"
#include "dataseparator.h"
#include "dataseparatorcam.h"
#include "KalmanObj.h"
#include "generatematcam.h"
#include "generatemattrans.h"
#include "ObjAssociate.h"
#include <QObject>
#include <QMutex>
#include <QTimer>
#include <QEventLoop>
#include <QDebug>
#include <QThread>
#include "objectvariable.h"



class Tracking: public QObject
{
    Q_OBJECT
    public:
        explicit Tracking(QObject *parent = 0);
        GenerateMatCam      *generateCam1;
        GenerateMatCam      *generateCam2;
        GenerateMatTrans    *generateCamTrans1;
        GenerateMatTrans    *generateCamTrans2;
        Kalmanobj           *kalmancam1;
        Kalmanobj           *kalmancam2;
        Associate           *Associe;
        FussionDataforTrans *fussion;
        DataSeparator       *InputTransform;
        DataSeparatorCam    *InputDataCurrent;
        DataSeparatorCam    *InputDataOutlier;

        Tracking(int FR,double x_down_left1,double x_down_right1,double x_upper_left1,double x_upper_right1,double y_down_left1,double y_down_right1,double y_upper_left1,double y_upper_right1,double pixel_th1,
                                    double x_down_left2,double x_down_right2,double x_upper_left2,double x_upper_right2,double y_down_left2,double y_down_right2,double y_upper_left2,double y_upper_right2,double pixel_th2,
                                    double TdataCamera1,double TdataCamera2, QList <DataInputCam>Init);
        ~Tracking();
        Mat AsosiasiGlob;
        QList<DataInputCam> hasilMapping;
        void proc_Tracking(int Frame);
    private:
        QList<DataInputCam>data1;
        QList<DataInputCam>data2;

        QThread* thread1;
        QThread* thread2;
        QThread* thread3;


        QMutex mutex;
        bool IssetCurrent,IssetOutlier,IssetTransform,IssetFrame;
        int Frames;
        QList<DataInputCam> inKalman1;
        QList<DataInputCam> inKalman2;
        QList<DataInputCam> initGab;

    public slots:
        void GetTransformedData (QList<QList<DataInputTrans> >);
        void GetDataCamera      (QList<QList<DataInputCam> >);
        void GetDataOutlier     (QList<QList<DataInputCam> >);
        void GetDataFrame       (int);

    signals:
        void sendDataQFoundLost(QList<QList<DataInputCam> >);
        void signalupdateAssociateMat(Mat);
        void SendDataFinal(QList<QList<DataInputCam> >);
}
;


#endif // TRACKING_H_INCLUDED
