#include "fusiondatafortrans.h"

FusionDataforTrans::FussionDataforTrans()
{
    IsSetdatCam1 = false;
    IsSetdatCam2 = false;
}

FusionDataforTrans::~FussionDataforTrans()
{

}


void FusionDataforTrans::getDataLostFoundCam1(QList<DataInputCam>ReadyData1) {
    ReadyData.clear();
    ReadyData.append(ReadyData1);
    IsSetdatCam1 = true;
}

void FusionDataforTrans::getDataLostFoundCam2(QList<DataInputCam>ReadyData2) {
    ReadyData.append(ReadyData2);
    IsSetdatCam2 = true;
}

void FusionDataforTrans::sendDataFussion() {
    if(IsSetdatCam1 && IsSetdatCam2){
        emit sendDatabeTransformed(ReadyData);    
    }    
    IsSetdatCam1 = false;
    IsSetdatCam2 = false;
}
