#include "generatematcam.h"

GenerateMatCam::GenerateMatCam(int cam,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double pixel_th)
{
    XDL = xdl;
    XDR = xdr;
    XUL = xul;
    XUR = xur;
    YDL = ydl;
    YDR = ydr;
    YUL = yul;
    YUR = yur;
    THETA = pixel_th;
    cameras = cam;
}
GenerateMatCam::~GenerateMatCam()
{


}
void GenerateMatCam::updatePrevious(QList<DataInputCam> prev){
    previous = prev;
    sizePrevious = previous.length();
    Isseto = true;
}
void GenerateMatCam::updatePredic(QList<DataInputCam> predict){
    pred = predict;
    sizePrediction = pred.length();
    Isset1 = true;
}
void GenerateMatCam::cam_associate(int data_before,QList<DataInputCam> current,int Fr){
    int i,j;
    data_bef = data_before;
    accCol = Mat::zeros(JUMLAH_PLAYER,1,CV_8U);
    accRow = Mat::zeros(JUMLAH_PLAYER,1,CV_8U);
    curr = current;
    sizeCurrent =  curr.length();
    frames = Fr;
    if(frames == 1){
        Associate = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
        for(i=0;i<sizeCurrent;i++){
            for(j=data_bef;j<sizeCurrent+data_bef;j++){
                Associate.at<int>(i,j)= 1;
            }
            checkFound();
        }
    }
    else{
        if(Isseto && Isset1){
            if(YDL>YUL && YDR>YUR && XDR>XUR && XDL<XUR){
                yo =((XDR-XDL)/(((-XDL+XUL)/(YDL-YUL))+((XDR-XUR)/(YDR-YUR))))-((YDL+YDR)/2);
            }
            xo =(((((yo*(-XDL+XUL))/(YDL-YUL))+XDL)+(((yo*(XDR-XUR))/(YDR-YUR))+(XDR)))/2);
            link_theid(data_bef);
            checkFound();
            checkLost();
            emit updateOcclusion(occlusion);
        }
    }
   emit sendCurrent(curr);
   emit updateMatrices(Associate);
   Isset1 =false;Isseto =false;
   pred.clear();
   curr.clear();
   indicatedFound.clear();
   indicatedLost.clear();
   occlusion.clear();
   accCol.release();
   accRow.release();
}
double GenerateMatCam::threshold_coef(double y){
    double threshold_k;
    double konst = (YDL+YDR)/2;
    if(y!=konst){
        threshold_k  = ((y-yo)/(y-konst));
    }
    return (threshold_k);
}
void GenerateMatCam::find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m){
    double k = threshold_coef(y);
    double th = k*THETA;
    if(y > yo){
        x_kanan = x+(th/2)-(((x-xo)/(y-yo))*(y_m-y));
        x_kiri = x-(th/2)-(((x-xo)/(y-yo))*(y_m-y));
    }
}
double GenerateMatCam::find_threshold_y(double y){
    double k = threshold_coef(y);
    double th = k*THETA;
    return th/2;
}
/**Hungarian Algorithms**/
void GenerateMatCam::link_theid(int data_before){
    int i,j;
    double th_xka,th_xki,th_y;
    Associate = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
    if(frames==2){
        for(i=0;i<sizeInits;i++){
           for(j=0;j<sizeCurrent;j++){
                Euclid_x = previous.at(i).dataplayer.x-curr.at(j).dataplayer.x;
                Euclid_y = abs(previous.at(i).dataplayer.y-curr.at(j).dataplayer.y);
                find_threshold_x(th_xka,th_xki,(double)previous.at(i).dataplayer.y,(double)previous.at(i).dataplayer.x,(double)curr.at(j).dataplayer.y);
                th_y=find_threshold_y((double)previous.at(i).dataplayer.y);
                if(Euclid_y < th_y){
                       if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                          Associate.at<int>(i,j+data_before) = 1;
                         }
                }
           }
        }
    }
    else{
        for(i=0;i<sizePrevious;i++){
           for(j=0;j<sizeCurrent;j++){
               const int idx = obj.foo(pred,previous.at(i).id);
               if(idx<=sizePrevious){
                   Euclid_x = (( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.x))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.x)))-(curr.at(j).dataplayer.x);
                   Euclid_y = abs(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.y))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.y))-curr.at(j).dataplayer.y);
                   find_threshold_x(th_xka,th_xki,(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.y))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.y))),(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.x))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.x))),(double)curr.at(j).dataplayer.y);
                   th_y=find_threshold_y((double)(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.y))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.y))));
               }
               else if (idx>sizePrevious){
                   Euclid_x = (previous.at(i).dataplayer.x)-(curr.at(j).dataplayer.x);
                   Euclid_y = abs(previous.at(i).dataplayer.y-curr.at(j).dataplayer.y);
                   find_threshold_x(th_xka,th_xki,(double)previous.at(idx).dataplayer.y,(double)previous.at(idx).dataplayer.x,(double)curr.at(j).dataplayer.y);
                   th_y=find_threshold_y((double)previous.at(idx).dataplayer.y);
               }
               if(Euclid_y < th_y){
                       if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                           Associate.at<int>(i,j+data_before) = 1;
                       }
               }
           }
       }
    }
}
void GenerateMatCam::accums(){
    int i,j;
    for(i=1;i<JUMLAH_PLAYER;i++){
        for(j=data_bef;j<data_bef+sizeCurrent;j++){
            accCol.at<int>(j) = accCol.at<int>(j)+Associate.at<int>(i,j);
            accRow.at<int>(i) = accRow.at<int>(i)+Associate.at<int>(i,j);
        }
    }
}
void GenerateMatCam::checkFound(){
    for(int j=data_bef;j<data_bef+sizeCurrent;j++){
        if((accCol.at<int>(j)==0) & (frames != 1)){
            indicatedFound.append(curr.at(j));
        }
    }
}

void GenerateMatCam::checkLost(){
    DataInputCam buffer;
    for(int i=0;i<JUMLAH_PLAYER;i++){
        if(accRow.at<int>(i)==0){
            int idx = obj.foo(pred,previous.at(i).id);
            if(idx<=previous.length()){
                buffer.id     = previous.at(i).id;
                buffer.camera = previous.at(i).camera;
                buffer.flagOcclusion =previous.at(i).flagOcclusion;
                buffer.pixelSpeed.x =previous.at(i).pixelSpeed.x;
                buffer.pixelSpeed.y =previous.at(i).pixelSpeed.y;
                buffer.status = previous.at(i).status;
                buffer.dataplayer.x = (( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.x))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.x)));
                buffer.dataplayer.y =(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.y))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.y)));
                buffer.dataplayer.width =(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.width))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.width)));
                buffer.dataplayer.height =(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.height))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.height)));
                indicatedLost.append(buffer);
            }
            else{
                indicatedLost.append(previous.at(i));
            }
        }
    }
}
void GenerateMatCam::checkOcclusion(){
    Point buffer;
    for(int i=0;i<JUMLAH_PLAYER;i++){
        for(int j=data_bef;j<data_bef+sizeCurrent;j++){
            if(accCol.at<int>(j)>1 && Associate.at<int>(i,j)==1){
                buffer.x = i;
                buffer.y = j;
                occlusion.append(buffer);
            }
        }
    }
}
