#include "fusiondatafortrans.h"

FusionDataforTrans::FussionDataforTrans(bool on)
{
    startfussion = on;
    IsSetdatCam1 = false;
    IsSetdatCam2 = false;
}

FusionDataforTrans::~FussionDataforTrans()
{

}


void FusionDataforTrans::getDataLostFoundCam1(QList<DataInputCam>ReadyData1){
    Ready1 = ReadyData1;
    IsSetdatCam1 = true;
}

void FusionDataforTrans::getDataLostFoundCam2(QList<DataInputCam>ReadyData2){
    Ready2 = ReadyData2;
    IsSetdatCam2 = true;
}

void FusionDataforTrans::sendDataFussion(){
    ReadyData.clear();
    if(startfussion){
        while(!IsSetdatCam1 || !IsSetdatCam2){
            if(IsSetdatCam1 && IsSetdatCam2){
                break;
            }
        }
        ReadyData.append(Ready1);
        ReadyData.append(Ready2);
        emit sendDatabeTransformed(ReadyData);
        IsSetdatCam1 = false;
        IsSetdatCam2 = false;
    }
}
