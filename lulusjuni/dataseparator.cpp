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
        //lost camera 2 found camera 1
        if((hasilTransformasi.at(i).cam == 1 && hasilTransformasi.at(i).flag == false)||(hasilTransformasi.at(i).cam == 2 && hasilTransformasi.at(i).flag == true) ){
            DataCam1.append(hasilTransformasi.at(i));
        }
        //lost camera 1 found camera 2
        if((hasilTransformasi.at(i).cam == 1 && hasilTransformasi.at(i).flag == true)||(hasilTransformasi.at(i).cam == 2 && hasilTransformasi.at(i).flag == false)){
            DataCam2.append(hasilTransformasi.at(i));
        }
    }
    emit SendCamera1(DataCam1);
    emit SendCamera2(DataCam2);
}
