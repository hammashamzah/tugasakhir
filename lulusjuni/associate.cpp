#include "associate.h"

Associate::Associate(){
}

Associate::~Associate(){

}


void Associate::updateMatCam1(Mat ass1){//from generate MatCam
    assoc1 = ass1;
    IsMatCam1 = true;
}

void Associate::updateMatCam2(Mat ass2){//from generate MatCam
    assoc2 = ass2;
    IsMatCam2 = true;
}

void Associate::UpdateOcclusionCam1(QList<QList<DataInputCam> > Occ1)//dari generateMatcam
{
    prevClusterOccCam1.clear();
    prevClusterOccCam1 = clusterOccCam1;
    clusterOccCam1.clear();
    clusterOccCam1 = Occ1;
    IsOccCam1 = true;
}

void Associate::UpdateOcclusionCam2(QList<QList<DataInputCam> > Occ2)//dari generateMatcam
{
    prevClusterOccCam2.clear();
    prevClusterOccCam2 = clusterOccCam2;
    clusterOccCam2.clear();
    clusterOccCam2 = Occ2;
    IsOccCam2 = true;
}

void Associate::remaindedDataCam1(QList<int> RemainCam1)//dari generateMattrans
{
    remainData1.clear();
    remainData1 =  RemainCam1;
    IsRemainCam1 = true;
}

void Associate::remaindedDataCam2(QList<int> RemainCam2){
    remainData2.clear();
    remainData2 =  RemainCam2;
    IsRemainCam1 = true;
}

void Associate::accum_assoc(QList<DataInputCam> DataCam1,QList<DataInputCam> DataCam2, int threshold){
    association_agrr = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
    cam1.clear();
    cam2.clear();
    cam1 = DataCam1;
    cam2 = DataCam2;
    //threshold outlier untuk masing-masing kamera atau untuk dua kamera?
    min = threshold;
        while(!IsMatCam1 || !IsMatCam2 || !IsOccCam1 || !IsOccCam2 || !IsRemainCam1 || !IsRemainCam2){
            if(IsMatCam1 && IsMatCam2 && IsOccCam1 && IsOccCam2 && IsRemainCam1 && IsRemainCam2){
                break;
            }
        association_agrr = assoc1 + assoc2 ;
        mapping();
        handlerOutlier();
        DataFinal.clear();
        ReadyOutlier.clear();
        ReadyOutlier.append(Outlier1);
        ReadyOutlier.append(Outlier2);
        DataFinal.append(Mapping1);
        DataFinal.append(Mapping2);
        emit sendDataFinalCam1(Mapping1);
        emit sendDataFinalCam2(Mapping2);
        emit sendDataOutlier(ReadyOutlier);
        emit sendDataFinal(DataFinal);
        IsMatCam1 = false;IsMatCam2 =false;IsOccCam1=false;IsOccCam2=false;IsRemainCam1=false;IsRemainCam2=false;
    }
}


void Associate::handlerOutlier(){
    double euclid_distance;
    int indicatedmin=0;
    QList<DataInputCam> buff;
    QList<DataInputCam> buffer;
    //ini belum diganti lo ya, embek
    Outlier1.clear();
    Outlier2.clear();
    if(!remainData1.isEmpty()){
        for(int i=0;i<remainData1.length();i++){
            for(int j=0;j<prevClusterOccCam1.length();j++){
                buff.clear();
                buff = prevClusterOccCam1.at(i);
                euclid_distance = sqrt(((((double)cam1.at(remainData1.at(i)).dataplayer.x)-((double)buff.at(0).dataplayer.x))*(((double)cam1.at(remainData1.at(i)).dataplayer.x)-((double)buff.at(0).dataplayer.x)))+((((double)cam1.at(remainData1.at(i)).dataplayer.y)-((double)buff.at(0).dataplayer.y))*(((double)cam1.at(remainData1.at(i)).dataplayer.y)-((double)buff.at(0).dataplayer.y))));
                if(euclid_distance <= min){
                    indicatedmin = j;
                    min = euclid_distance;
                }
            }
            if(indicatedmin < prevClusterOccCam1.length()+1){
               for(int k=0;k<prevClusterOccCam1.at(indicatedmin).length();k++){
                   buff.clear();
                   buff = prevClusterOccCam1.at(indicatedmin);
                   buffer[k].id = buff.at(k).id;
                   buffer[k].dataplayer.x = cam1.at(remainData1.at(i)).dataplayer.x;
                   buffer[k].dataplayer.y = cam1.at(remainData1.at(i)).dataplayer.y;
                   //buffer[k].dataplayer.width = cam1.at(remainData1.at(i)).dataplayer.width;
                   //buffer[k].dataplayer.height = cam1.at(remainData1.at(i)).dataplayer.height;
                
               }
            }
            Outlier1.append(buffer);
        }
    }
    if(!remainData2.isEmpty()){
        for(int i=0;i<remainData2.length();i++){
            for(int j=0;j<prevClusterOccCam2.length();j++){
                buff.clear();
                buff = prevClusterOccCam2.at(i);
                euclid_distance = sqrt(((((double)cam1.at(remainData2.at(i)).dataplayer.x)-((double)buff.at(0).dataplayer.x))*(((double)cam1.at(remainData1.at(i)).dataplayer.x)-((double)buff.at(0).dataplayer.x)))+((((double)cam1.at(remainData1.at(i)).dataplayer.y)-((double)buff.at(0).dataplayer.y))*(((double)cam1.at(remainData1.at(i)).dataplayer.y)-((double)buff.at(0).dataplayer.y))));
                if(euclid_distance <= min){
                    indicatedmin = j;
                    min = euclid_distance;
                }
            }
           for(int k=0;k<prevClusterOccCam2.at(indicatedmin).length();k++){
               buff.clear();
               buff = prevClusterOccCam2.at(indicatedmin);
               buffer[k].id = buff.at(k).id;
               buffer[k].dataplayer.x = cam2.at(remainData2.at(i)).dataplayer.x;
               buffer[k].dataplayer.y = cam2.at(remainData2.at(i)).dataplayer.y;
               //buffer[k].dataplayer.width = cam2.at(remainData2.at(i)).dataplayer.width;
               //buffer[k].dataplayer.height = cam2.at(remainData2.at(i)).dataplayer.height;
                }

            }
        Outlier2.append(buffer);
    }               
}

void Associate::mapping(){
    DataInputCam buffer;
    Mapping1.clear();
    Mapping2.clear();
    for(int i=0;i<JUMLAH_PLAYER;i++){
        for(int j=0;j<JUMLAH_PLAYER;j++){
            if(j<cam1.length()){
                if(association_agrr.at<int>(i,j)==1){
                    buffer.id = i;
                    buffer.dataplayer.x = cam1.at(j).dataplayer.x;
                    buffer.dataplayer.y = cam1.at(j).dataplayer.y;
                    //buffer.dataplayer.width =cam1.at(j).dataplayer.width;
                    //buffer.dataplayer.height =cam1.at(j).dataplayer.height;
                    buffer.flag = cam1.at(j).flag;
                    buffer.pixelSpeed.x =cam1.at(j).pixelSpeed.x;
                    buffer.pixelSpeed.y =cam1.at(j).pixelSpeed.y;
                    Mapping1.append(buffer);
                }
            }
            else if(j>=cam1.length()){
                if(association_agrr.at<int>(i,j)==1){
                    buffer.id = i;
                    buffer.dataplayer.x = cam2.at(j).dataplayer.x;
                    buffer.dataplayer.y = cam2.at(j).dataplayer.y;
                    //buffer.dataplayer.width =cam2.at(j).dataplayer.width;
                    //buffer.dataplayer.height =cam2.at(j).dataplayer.height;
                    buffer.flag = cam2.at(j).flag;
                    buffer.pixelSpeed.x =cam2.at(j).pixelSpeed.x;
                    buffer.pixelSpeed.y =cam2.at(j).pixelSpeed.y;
                    Mapping2.append(buffer);
                }
            }
        }
    }
}
