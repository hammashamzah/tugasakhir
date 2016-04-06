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
#include "objectvariable.h"

GenerateMatCam *generateCam1 ;
GenerateMatCam *generateCam2;
GenerateMatCam *generateCam3;
GenerateMatTrans *generateCamTrans1;
GenerateMatTrans *generateCamTrans2;
GenerateMatTrans *generateCamTrans3;
Kalmanobj *kalmancam1;
Kalmanobj *kalmancam2;
Kalmanobj *kalmancam3;
Associate *Associe;

class HighLevel:public QObject
{
    Q_OBJECT
    public:
        HighLevel(double FR,double xdl1,double xdr1,double xul1,double xur1,double ydl1,double ydr1,double yul1,double yur1,double pixel_th1,
                                double xdl2,double xdr2,double xul2,double xur2,double ydl2,double ydr2,double yul2,double yur2,double pixel_th2,
                                double xdl3,double xdr3,double xul3,double xur3,double ydl3,double ydr3,double yul3,double yur3,double pixel_th3,
                                double THcam1,double THcam2,double THcam3,mode ops);
        ~HighLevel();
        void proHighLevel(int Fr,mode proc);
        Mat AsosiasiGlob;
    private:
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
        QList<DataInputCam>HCam1;
        QList<DataInputCam>HCam2;
        QList<DataInputCam>HCam3;
        QList<DataInputTrans>aCam1F;
        QList<DataInputTrans>aCam2F;
        QList<DataInputTrans>aCam3F;
        QList<DataInputTrans>aCam1L;
        QList<DataInputTrans>aCam2L;
        QList<DataInputTrans>aCam3L;
        bool Isset1,Isset2,Isset3,Isset4,Isset5,Isset6,Isset7,Isset8,Isset9,Isseto;
    public slots:
        void updateDataHamasCam1(QList<DataInputCam>);
        void updateDataHamasCam2(QList<DataInputCam>);
        void updateDataHamasCam3(QList<DataInputCam>);
        void updateDataAznanCam1F(QList<DataInputTrans>);
        void updateDataAznanCam2F(QList<DataInputTrans>);
        void updateDataAznanCam3F(QList<DataInputTrans>);
        void updateDataAznanCam1L(QList<DataInputTrans>);
        void updateDataAznanCam2L(QList<DataInputTrans>);
        void updateDataAznanCam3L(QList<DataInputTrans>);
    signals:
        void sendDataQFound1(QList<DataInputCam>);
        void sendDataQLost1(QList<DataInputCam>);
        void sendDataQFound2(QList<DataInputCam>);
        void sendDataQLost2(QList<DataInputCam>);
        void sendDataQFound3(QList<DataInputCam>);
        void sendDataQLost3(QList<DataInputCam>);
        void signalupdateAssociateMat(Mat);
}
;


#endif // HIGHLEVEL_H_INCLUDED
