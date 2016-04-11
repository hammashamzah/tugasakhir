#include "dataseparator.h"

DataSeparator::DataSeparator(bool on)
{
    startseparate =on;

}

DataSeparator::~DataSeparator()
{

}

void DataSeparator::getDataTrans(QList<QList<DataInputTrans> > hasilTransformasi){
    QList<DataInputTrans> buffer1;
    QList<DataInputTrans> buffer2;
    DataCam1.clear();
    DataCam2.clear();
    buffer1.clear();
    buffer2.clear();
    if(startseparat){
        buffer1 = hasilTransformasi.at(0);
        buffer2 = hasilTransformasi.at(1);
        for(int i =0;i<buffer1.length();i++){
            if(buffer1.at(i).flag==false)//found
            {
                DataCam1.append(buffer1.at(i));
            }
            else if(buffer1.at(i).flag==true)//lost
            {
                DataCam2.append(buffer1.at(i));
            }
        }
        for(int i =0;i<buffer1.length();i++){
            if(buffer2.at(i).flag==false)//found
            {
                DataCam2.append(buffer1.at(i));
            }
            else if(buffer2.at(i).flag==true)//lost
            {
                DataCam1.append(buffer1.at(i));
            }
        }
        emit SendCamera1(DataCam1);
        emit SendCamera2(DataCam2);
    }
}
