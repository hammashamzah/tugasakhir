#include "ObjAssociate.h"

Associate::Associate(){
    IsMatCam1 = false;
    IsMatCam2 = false;
    IsOccCam1 = false;
    IsOccCam2 = false;
    IsRemainCam1 = false;
    IsRemainCam2 = false;
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

void Associate::UpdateOcclusionCam1(QList<QList<DataInputCam>> Occ1)//dari generateMatcam
{
    prevClusterOccCam1.clear();
    prevClusterOccCam1 = clusterOccCam1;
    clusterOccCam1.clear();
    clusterOccCam1 = Occ1;
    IsOccCam1 = true;
}

void Associate::UpdateOcclusionCam2(QList<QList<DataInputCam>>)//dari generateMatcam
{
    prevClusterOccCam2.clear();
    prevClusterOccCam2 = clusterOccCam2;
    clusterOccCam2.clear();
    clusterOccCam2 = Occ1;
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

void Associate::accum_assoc(QList<DataInputCam> DataCam1,QList<DataInputCam> DataCam2){
    association_agrr = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
    cam1.clear();
    cam2.clear();
    cam1 = DataCam1;
    cam2 = DataCam2;
    while(!IsMatCam1 || !IsMatCam2 || !IsOccCam1 || !IsOccCam2 || !IsRemainCam1 || !IsRemainCam2){
        if(IsMatCam1 && IsMatCam2 && IsOccCam1 && IsOccCam2 && IsRemainCam1 && IsRemainCam2){
            break;
        }
    }
    association_agrr = assoc1 + assoc2 ;
    mapping();
    IsMatCam1 = false;IsMatCam2 =false;IsOccCam1=false;IsOccCam2=false;IsRemainCam1=false;IsRemainCam2=false;
}

/*
void Associate::handlerOutlier(){
    double euclid_distance;
    const double min = Thresholdoutlier;
    QList <DataInputCam> buff;
    possibleId_newclustercam1.clear();
    if(!remainData1.isEmpty() && !clusterOccCam1.isEmpty()){
        for(int i=0;i<remainData1.length();i++){
            for(int j=0;j<prevClusterOccCam1.length();j++){
                buff = prevClusterOccCam1.at(i);
                euclid_distance = sqrt(((((double)cam1.at(remainData1).dataplayer.x)-((double)buff.at(1).dataplayer.x))*(((double)cam1.at(remainData1).dataplayer.x)-((double)buff.at(1).dataplayer.x)))+((((double)cam1.at(remainData1).dataplayer.y)-((double)buff.at(1).dataplayer.y))*(((double)cam1.at(remainData1).dataplayer.y)-((double)buff.at(1).dataplayer.y))));
                if(euclid_distance <= min){
                    posibleId_newclustercam1.clear();
                    for(int j=0;j<buff.length();j++){
                        posibleId_newclustercam1.append(buff.at(j).id);
                    }
                }
            }
        }
        emit possible
    }
    if(!remainData2.empty()){
        for(int i=0;i<remainData1.length();i++){
            for(int j=0;j<prevClusterOccCam1.length();j++){
                buff = prevClusterOccCam1.at(i);
                euclid_distance = sqrt(((((double)cam1.at(remainData1).dataplayer.x)-((double)buff.at(1).dataplayer.x))*(((double)cam1.at(remainData1).dataplayer.x)-((double)buff.at(1).dataplayer.x)))+((((double)cam1.at(remainData1).dataplayer.y)-((double)buff.at(1).dataplayer.y))*(((double)cam1.at(remainData1).dataplayer.y)-((double)buff.at(1).dataplayer.y))));
                if(euclid_distance <= min){
                    posibleId_newclustercam1.clear();
                    for(int j=0;j<buff.length();j++){
                        posibleId_newclustercam1.append(buff.at(j).id);
                    }
                }
            }
        }
    }
}
*/
void Associate::mapping(){
    DataInputCam buffer;
    for(int i=0;i<JUMLAH_PLAYER;i++){
        for(int j=0;j<JUMLAH_PLAYER;j++){
            if(j<cam1.length()){
                if(association_agrr.at<int>(i,j)==1){
                    buffer.id = i;
                    buffer.dataplayer.x = cam1.at(j).dataplayer.x;
                    buffer.dataplayer.y = cam1.at(j).dataplayer.y;
                    buffer.dataplayer.width =cam1.at(j).dataplayer.width;
                    buffer.dataplayer.height =cam1.at(j).dataplayer.height;
                    buffer.status = cam1.at(j).status;
                    buffer.camera = 1;
                    buffer.flag = cam1.at(j).flag;
                    buffer.pixelSpeed.x =cam1.at(j).pixelSpeed.x;
                    buffer.pixelSpeed.y =cam1.at(j).pixelSpeed.y;
                    Mapping.append(buffer);
                }
            }
            else if((j<cam1.length()+cam2.length())&&(j>cam1.length()+cam2.length())){
                if(association_agrr.at<int>(i,j)==1){
                    buffer.id = i;
                    buffer.dataplayer.x = cam2.at(j).dataplayer.x;
                    buffer.dataplayer.y = cam2.at(j).dataplayer.y;
                    buffer.dataplayer.width =cam2.at(j).dataplayer.width;
                    buffer.dataplayer.height =cam2.at(j).dataplayer.height;
                    buffer.status = cam2.at(j).status;
                    buffer.camera = 2;
                    buffer.flag = cam2.at(j).flag;
                    buffer.pixelSpeed.x =cam2.at(j).pixelSpeed.x;
                    buffer.pixelSpeed.y =cam2.at(j).pixelSpeed.y;
                    Mapping.append(buffer);
                }
            }
            else{
                if(association_agrr.at<int>(i,j)==1){
                    buffer.id = i;
                    buffer.dataplayer.x = cam3.at(j).dataplayer.x;
                    buffer.dataplayer.y = cam3.at(j).dataplayer.y;
                    buffer.dataplayer.width =cam3.at(j).dataplayer.width;
                    buffer.dataplayer.height =cam3.at(j).dataplayer.height;
                    buffer.status = cam3.at(j).status;
                    buffer.camera = 3;
                    buffer.flag = cam3.at(j).flag;
                    buffer.pixelSpeed.x =cam3.at(j).pixelSpeed.x;
                    buffer.pixelSpeed.y =cam3.at(j).pixelSpeed.y;
                    Mapping.append(buffer);
                }
            }
        }
    }
}
