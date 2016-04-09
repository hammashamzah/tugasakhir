#include "ObjAssociate.h"

Associate::Associate(){
    IsMatCam1 = false;
    IsMatCam2 = false;
}

Associate::~Associate(){

}

/**void Associate::getOcclusion1(QList<Point> occ){
    Occlussion1 = occ;
    Isseto = true;
}

void Associate::getOcclusion2(QList<Point> occ){
    Occlussion2 = occ;
    Isset7 = true;
}

void Associate::getOcclusion3(QList<Point> occ){
    Occlussion3 = occ;
    Isset8 = true;
}**/

void Associate::updateMatCam1(Mat ass1){//from generate MatCam
    assoc1 = ass1;
    IsMatCam1 = true;
}

void Associate::updateMatCam2(Mat ass2){//from generate MatCam
    assoc2 = ass2;
    IsMatCam2 = true;
}
/**
void Associate::updateMatCam3(Mat ass3){//from generate MatCam
    assoc3 = ass3;
    Isset3 = true;
}
void Associate::updateCurrentCam1(QList<DataInputCam> dat1){// from generate MatCam
    cam1 =dat1;
    Isset4 =true;
}

void Associate::updateCurrentCam2(QList<DataInputCam> dat2){//from generate MatCam
    cam2 =dat2;
    Isset5 =true;
}

void Associate::updateCurrentCam3(QList<DataInputCam> dat3){//from generate MatCam
    cam3 =dat3;
    Isset6 =true;
}**/

void Associate::accum_assoc(QList<DataInputCam> DataCam1,QList<DataInputCam> DataCam2,QList<Point> OcclusionCam1,QList<Point> OcclusionCam2){
    association_agrr = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
    cam1.clear();
    cam2.clear();
    Occlussion1.clear();
    Occlussion2.clear();
    cam1 = DataCam1;
    cam2 = DataCam2;
    Occlussion1 = OcclusionCam1;
    Occlussion2 = OcclusionCam2;
    while(!IsMatCam1 || !IsMatCam2){
        if(IsMatCam1 && IsMatCam2){
            break;
        }
    }
    association_agrr = assoc1 + assoc2 ;
    mapping();
    IsMatCam1 = false;IsMatCam2 =false;
}

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
