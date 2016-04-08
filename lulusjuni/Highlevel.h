#ifndef HIGHLEVEL_H_INCLUDED
#define HIGHLEVEL_H_INCLUDED
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



class HighLevel: public QThread
{
    Q_OBJECT
    public:
        explicit HighLevel(QObject *parent = 0);
        GenerateMatCam *generateCam1;
        GenerateMatCam *generateCam2;
        GenerateMatCam *generateCam3;
        GenerateMatTrans *generateCamTrans1;
        GenerateMatTrans *generateCamTrans2;
        GenerateMatTrans *generateCamTrans3;
        Kalmanobj *kalmancam1;
        Kalmanobj *kalmancam2;
        Kalmanobj *kalmancam3;
        Associate *Associe;
        HighLevel(double FR,double xdl1,double xdr1,double xul1,double xur1,double ydl1,double ydr1,double yul1,double yur1,double pixel_th1,
                                double xdl2,double xdr2,double xul2,double xur2,double ydl2,double ydr2,double yul2,double yur2,double pixel_th2,
                                double xdl3,double xdr3,double xul3,double xur3,double ydl3,double ydr3,double yul3,double yur3,double pixel_th3,
                                double THcam1,double THcam2,double THcam3,mode ops);
        ~HighLevel();
//        void proHighLevel(int Fr,mode proc);
        Mat AsosiasiGlob;
        void requestedCamData();
        void run2(QList<DataInputTrans>LostCam1,QList<DataInputTrans>FoundCam1,QList<DataInputTrans>LostCam2,QList<DataInputTrans>FoundCam2,QList<DataInputTrans>LostCam3,QList<DataInputTrans>FoundCam3);
    private:
        QMutex mutex;
        bool flagrun1;
        bool flagrun2;
        bool IsReady;
        bool finishRun1;
        int Frames;
        mode operate;
        QList<DataInputCam> hasilMapping;
        QList<DataInputCam> inKalman1;
        QList<DataInputCam> inKalman2;
        QList<DataInputCam> inKalman3;
        QList<DataInputCam> indicatedLost1;
        QList<DataInputCam> indicatedFound1;
        QList<DataInputCam> indicatedLost2;
        QList<DataInputCam> indicatedFound2;
        QList<DataInputCam> indicatedLost3;
        QList<DataInputCam> indicatedFound3;
        QList<DataInputCam> initGab;
    public slots:
        void run1(QList<DataInputCam>,QList<DataInputCam>,QList<DataInputCam>);

    signals:
        void sendDataQFoundLost(QList<DataInputCam>,QList<DataInputCam>,QList<DataInputCam>,QList<DataInputCam>,QList<DataInputCam>,QList<DataInputCam>);
        void requestDataCam(bool);
        void sendFlagGetLostFoundData(bool);
        void signalupdateAssociateMat(Mat);

};


#endif // HIGHLEVEL_H_INCLUDED
