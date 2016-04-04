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
void GenerateMatCam::updatePredic(QList<DataInputCam> predict){
    pred = predict;
    sizePrediction = pred.length();
    Isset1 = true;
}
void GenerateMatCam::updateinit(QList<DataInputCam> init){
    inits = init;
    sizeInits = inits.length();
    Isset2 = true;
}
void GenerateMatCam::updateCurrent(QList<DataInputCam> current){
    curr = current;
    sizeCurrent =  curr.length();
    Isset3 = true;
}
void GenerateMatCam::updateFrame(int fr){
    frames = fr;
    Isset4 = true;
}
void GenerateMatCam::cam_associate(){
   if(Isset1 &Isset2 &Isset3 &Isset4){
    if(frames == 1){
        Associate = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8UV);
        for(i=0;i<sizeCurrent;i++){
            Associate.at<int>(i,i)= 1;
        }
    }
    else{
            if(YDL>YUL && YDR>YUR && XDR>XUR && XDL<XUR){
                yo =((XDR-XDL)/(((-XDL+XUL)/(YDL-YUL))+((XDR-XUR)/(YDR-YUR))))-((YDL+YDR)/2);
            }
            xo =(((((yo*(-XDL+XUL))/(YDL-YUL))+XDL)+(((yo*(XDR-XUR))/(YDR-YUR))+(XDR)))/2);
            link_theid();
    }
   }
   emit UpdateMatrices(Associate);
   Isset1 =false;Isset2 =false;Isset3 =false;Isset4 =false;
   pred.clear();
   curr.clear();
   inits.clear();
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
void GenerateMatCam::link_theid(){
    int i,j;
    double th_xka,th_xki,th_y;
    Associate = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
    if(frames==2){
        for(i=0;i<sizeInits;i++){
           for(j=0;j<sizeCurrent;j++){
                Euclid_x = inits.at(i).dataplayer.x-curr.at(i).dataplayer.x;
                Euclid_y = abs(inits.at(i).dataplayer.y-curr.at(i).dataplayer.y);
                find_threshold_x(th_xka,th_xki,(double)inits.at(i).dataplayer.y,(double)inits.at(i).dataplayer.x,(double)curr.at(i).dataplayer.y);
                th_y=find_threshold_y((double)inits.at(i).dataplayer.y);
                if(Euclid_y < th_y){
                       if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                          Associate.at<int>(i,j) = 1;
                         }
                }
           }
        }
    }
    else{
        for(i=0;i<sizePrediction;i++){
           for(j=0;j<sizeCurrent;j++){
               Euclid_x = pred.at(i).dataplayer.x-curr.at(i).dataplayer.x;
               Euclid_y = abs(pred.at(i).dataplayer.y-curr.at(i).dataplayer.y);
               find_threshold_x(th_xka,th_xki,(double)pred.at(i).dataplayer.y,(double)pred.at(i).dataplayer.x,(double)curr.at(i).dataplayer.y);
               th_y=find_threshold_y((double)pred.at(i).dataplayer.y);
               if(Euclid_y < th_y){
                       if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                           Associate.at<int>(i,j) = 1;
                       }
               }
           }
       }
    }
}


