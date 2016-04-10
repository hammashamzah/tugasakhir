#include "fussiondatafortrans.h"

FussionDataforTrans::FussionDataforTrans(bool on)
{
    startfussion = on;
    IsSetdatCam1 = false;
    IsSetdatCam2 = false;
}

FussionDataforTrans::~FussionDataforTrans()
{

}


void FussionDataforTrans::getDataLostFoundCam1(QList<DataInputCam>ReadyData1){
    Ready1 = ReadyData1;
    IsSetdatCam1 = true;
}

void FussionDataforTrans::getDataLostFoundCam2(QList<DataInputCam>ReadyData2){
    Ready2 = ReadyData2;
    IsSetdatCam2 = true;
}

void FussionDataforTrans::sendDataFussion(){
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
