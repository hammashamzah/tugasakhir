#include "Highlevel.h"
#define XUL 100
#define XUR 729
#define XDR 1000
#define XDL 30
#define YUL 512
#define YUR 511
#define YDR 1000
#define YDL 1003

#define FRAME_RATE 24



void HighLevel::HighLevel(double FR,double xdl1,double xdr1,double xul1,double xur1,double ydl1,double ydr1,double yul1,double yur1,double pixel_th1,
                            double xdl2,double xdr2,double xul2,double xur2,double ydl2,double ydr2,double yul2,double yur2,double pixel_th2,
                            double xdl3,double xdr3,double xul3,double xur3,double ydl3,double ydr3,double yul3,double yur3,double pixel_th3,
                            double THcam1,double THcam2,double THcam3,mode ops)
{
    operate = ops;
    GenerateMatCam generateCam1(1,xdl1,xdr1,xul1,xur1,ydl1,ydr1,yul1,yur1,pixel_th1);
    GenerateMatCam generateCam2(2,xdl2,xdr2,xul2,xur2,ydl2,ydr2,yul2,yur2,pixel_th2);
    GenerateMatCam generateCam3(3,xdl3,xdr3,xul3,xur3,ydl3,ydr3,yul3,yur3,pixel_th3);
    GenerateMatTrans generateCamTrans1(THcam1);
    GenerateMatTrans generateCamTrans2(THcam2);
    GenerateMatTrans generateCamTrans3(THcam3);
    Kalmanobj kalmancam1(1,xdl1,xdr1,xul1,xur1,ydl1,ydr1,yul1,yur1,FR);
    Kalmanobj kalmancam2(2,xdl2,xdr2,xul2,xur2,ydl2,ydr2,yul2,yur2,FR);
    Kalmanobj kalmancam3(3,xdl2,xdr2,xul2,xur2,ydl2,ydr2,yul2,yur2,FR);
    Associate Associe(operate);
}

HighLevel::~HighLevel(){

}

void HighLevel::updateDataHamasCam1(QList<DataInputCam> hamasCam1){
    HCam1 = hamasCam1;
    Isset1 = true;
}

void HighLevel::updateDataHamasCam2(QList<DataInputCam> hamasCam2){
    HCam2 = hamasCam2;
    Isset2 = true;
}

void HighLevel::updateDataHamasCam3(QList<DataInputCam> hamasCam3){
    HCam3 = hamasCam3;
    Isset3 = true;
}

void HighLevel::updateDataAznanCam1(QList<DataInputTrans> aznanCam1Lost){
    aCam1L = aznanCam1Lost;
    Isset4 = true;
}

void HighLevel::updateDataAznanCam1(QList<DataInputTrans> aznanCam1Found){
    aCam1F = aznanCam1Found;
    Isset5 = true;
}

void HighLevel::updateDataAznanCam2(QList<DataInputTrans> aznanCam2Lost){
    aCam2L = aznanCam2Lost;
    Isset6 = true;
}

void HighLevel::updateDataAznanCam2(QList<DataInputTrans> aznanCam2Found){
    aCam2F = aznanCam2Found;
    Isset7 = true;
}

void HighLevel::updateDataAznanCam3(QList<DataInputTrans> aznanCam3Lost){
    aCam3L = aznanCam3Lost;
    Isset8 = true;
}

void HighLevel::updateDataAznanCam3(QList<DataInputTrans> aznanCam3Found){
    aCam3F = aznanCam3Found;
    Isset9 = true;
}

void HighLevel::proHighLevel(int Fr,mode proc){
    Frames = Fr;
    operate = proc;
    switch(operate){
            case(singel):{;


            break;
            }
            case(dual):{;

            break;
            }
            case(triple):{;

            break;
            }
        }
    Isset1 = false;Isset4 = false;Isset7 = false;
    Isset2 = false;Isset5 = false;Isset8 = false;
    Isset3 = false;Isset6 = false;Isset9 = false;
}






