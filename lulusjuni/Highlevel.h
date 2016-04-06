#ifndef HIGHLEVEL_H_INCLUDED
#define HIGHLEVEL_H_INCLUDED

#include "KalmanObj.h"
#include "ObjAssociate.h"
#include "KalmanObj.h"
#include "kalmanobj3d.h"
#include "generatematcam.h"
#include "generatemattrans.h"
#include "ObjAssociate.h"
#include "objectvariable.h"
#include <QObject>
#include <QList>

class HighLevel{
    public:
        HighLevel(double FR,double xdl1,double xdr1,double xul1,double xur1,double ydl1,double ydr1,double yul1,double yur1,double pixel_th1,
                                double xdl2,double xdr2,double xul2,double xur2,double ydl2,double ydr2,double yul2,double yur2,double pixel_th2,
                                double xdl3,double xdr3,double xul3,double xur3,double ydl3,double ydr3,double yul3,double yur3,double pixel_th3,
                                double THcam1,double THcam2,double THcam3,mode ops);
        ~HighLevel();
        proHighLevel(mode proc);
    private:
        int Frames;
        mode operate;
        QList<DataInputCam> initGab;
        QList<DataInputCam>HCam1;
        QList<DataInputCam>HCam2;
        QList<DataInputCam>HCam3;
        QList<DataInputCam>aCam1F;
        QList<DataInputCam>aCam2F;
        QList<DataInputCam>aCam3F;
        QList<DataInputTrans>aCam1L;
        QList<DataInputTrans>aCam2L;
        QList<DataInputTrans>aCam3L;
        bool Isset1,Isset2,Isset3,Isset4,Isset5,Isset6,Isset7,Isset8,Isset9,Isseto;
    public slots:
        void updateDataHamasCam1(QList<DataInputCam>);
        void updateDataHamasCam2(QList<DataInputCam>);
        void updateDataHamasCam3(QList<DataInputCam>);
        void updateDataAznanCam1(QList<DataInputTrans>);
        void updateDataAznanCam2(QList<DataInputTrans>);
        void updateDataAznanCam3(QList<DataInputTrans>);
    signals:
        void sendDataQFound1(QList<DataInputCam>);
        void sendDataQLost1(QList<DataInputCam>);
        void sendDataQFound2(QList<DataInputCam>);
        void sendDataQLost2(QList<DataInputCam>);
        void sendDataQFound3(QList<DataInputCam>);
        void sendDataQLost3(QList<DataInputCam>);

}
;


#endif // HIGHLEVEL_H_INCLUDED
