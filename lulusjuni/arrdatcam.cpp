#include "arrdatcam.h"

ArrDatCam::ArrDatCam(Datainputcam buff[JUMLAH_PLAYER],int numCluster, int fr)
{

}

ArrDatCam::~ArrDatCam()
{

}

void ArrDatCam:: setdata(bool state_input,Datainputcam dat[JUMLAH_PLAYER],int numCluster, int fr){
    if(state_input){
        data.data = dat;
        jumlahCluster = numCluster;
        frame = fr;
        Isset = true;
    }
    else{
        Isset = false;
    }
}

