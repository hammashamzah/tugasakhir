#include "dataseparatorcam.h"

DataSeparatorCam::DataSeparatorCam(bool on)
{
    startseparate = on;
}


DataSeparatorCam::~DataSeparatorCam()
{

}


void DataSeparatorCam::getDataTrans(QList<QList<DataInputCam> > data){
    DataCam1.clear();
    DataCam2.clear();
    if(startseparate){
        DataCam1 = data.at(0);
        DataCam2 = data.at(1);
        emit SendCamera1(DataCam1);
        emit SendCamera2(DataCam2);
    }
}
