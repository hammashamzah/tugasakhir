#include "dataseparator.h"

DataSeparator::DataSeparator()
{

}

DataSeparator::~DataSeparator()
{

}

void DataSeparator::getDataTrans(QList<DataInputTrans> hasilTransformasi){
    DataCam1.clear();
    DataCam2.clear();
    for(int i=0;i<hasilTransformasi.length();i++){
        if(hasilTransformasi.at(i).cam == 1){
            DataCam1.append(hasilTransformasi.at(i));
        }
        if(hasilTransformasi.at(i).cam == 2){
            DataCam2.append(hasilTransformasi.at(i));
        }
    }
    emit SendCamera1(DataCam1);
    emit SendCamera2(DataCam2);
}
