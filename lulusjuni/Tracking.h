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
        GenerateMatCam *generateCam1;
        GenerateMatCam *generateCam2;
        GenerateMatTrans *generateCamTrans1;
        GenerateMatTrans *generateCamTrans2;
        Kalmanobj *kalmancam1;
        Kalmanobj *kalmancam2;
        Associate *Associe;

        Tracking(int FR,double x_down_left1,double x_down_right1,double x_upper_left1,double x_upper_right1,double y_down_left1,double y_down_right1,double y_upper_left1,double y_upper_right1,double pixel_th1,
                                    double x_down_left2,double x_down_right2,double x_upper_left2,double x_upper_right2,double y_down_left2,double y_down_right2,double y_upper_left2,double y_upper_right2,double pixel_th2,
                                    double TdataCamera1,double TdataCamera2,mode ops, QList <DataInputCam>Init);
        ~Tracking();
        Mat AsosiasiGlob;
        QList<DataInputCam> hasilMapping;
        void run1(int Frame,QList<DataInputCam> dataCamera1,QList<DataInputCam>dataCamera2);
        void run2(QList<DataInputTrans>,QList<DataInputTrans>,QList<DataInputTrans>,QList<DataInputTrans>);
    private:
        QThread* thread;
        DataSeparator* InputTransform;


        QMutex mutex;
        bool flagrun1;
        bool flagrun2;
        bool IsReady;
        bool finishRun1;
        int Frames;
        mode operate;
        QList<DataInputCam> inKalman1;
        QList<DataInputCam> inKalman2;
        QList<DataInputCam> initGab;
    public slots:
        void getDataCam1(QList<DataInputCam>);
        void getDataCam2(QList<DataInputCam>);
        void getFrame(int);
        void getDataTransform(QList<DataInputTrans>);
    signals:
        void sendDataQFoundLost(QList<DataInputCam>);
        void signalupdateAssociateMat(Mat);
        void SendHasilMapping(QList<DataInputCam>);
}
;


#endif // TRACKING_H_INCLUDED
