#include "fussiondatafortrans.h"

FussionDataforTrans::FussionDataforTrans()
{
    IsSetdatCam1 = false;
    IsSetdatCam2 = false;
}

FussionDataforTrans::~FussionDataforTrans()
{

}


void FussionDataforTrans::getDataLostFoundCam1(QList<DataInputCam>ReadyData1){
    ReadyData = ReadyData1;
    IsSetdatCam1 = true;
}

void FussionDataforTrans::getDataLostFoundCam2(QList<DataInputCam>ReadyData2){
    ReadyDataCam2 = ReadyData2;
    IsSetdatCam2 = true;
}

void FussionDataforTrans::sendDataFussion(){
    int i = 0;
    while(!IsSetdatCam1 || !IsSetdatCam2){
        if(IsSetdatCam1 && IsSetdatCam2){
            break;
        }
    }
    do{
        ReadyData.append(ReadyDataCam2.at(i));
        i++;
    }while (i < ReadyDataCam2.length());
    emit sendDatabeTransformed(ReadyData);
    IsSetdatCam1 = false;
    IsSetdatCam2 = false;
}
