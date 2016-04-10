#include "dataseparatorcam.h"

DataSeparatorCam::DataSeparatorCam(bool on)
{
    startseparate = on;
}


DataSeparatorCam::~DataSeparatorCam()
{

}


void DataSeparatorCam::getDataTrans(QList<QList<DataInputCam> > outlier){
    DataCam1.clear();
    DataCam2.clear();
    if(startseparate){
        DataCam1 = outlier.at(0);
        DataCam2 = outlier.at(1);
        emit SendCamera1(DataCam1);
        emit SendCamera2(DataCam2);
    }
}
