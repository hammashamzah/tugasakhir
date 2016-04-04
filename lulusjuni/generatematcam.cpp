#include "generatematcam.h"


GenerateMatcam::GenerateMatcam(int cam,double xdl,double xdr,double xul,double xur,double ydl,double ydr,double yul,double yur,double pixel_th)
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

GenerateMatcam::~GenerateMatcam()
{


}
void GenerateMatcam::updatePredic(bool Isset,ArrDatCam predic){
    if(Isset){
        pred = predic.data;
    }
}

void GenerateMatcam::updateinit(bool Isset, ArrDatCam init){
    if(Isset){
        inits = init.data;
    }
}

void GenerateMatcam::updateCurrent(bool Isset, ArrDatCam current){
    if(Isset){
        curr = current.data;
        frames =  current.frame;
    }
}




void GenerateMatcam::cam_associate(){
    if(frames == 1){
        Associate = (Mat_<int>(JUMLAH_PLAYER,JUMLAH_PLAYER) <<   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
                                                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1);

    }
    else{
            if(YDL>YUL && YDR>YUR && XDR>XUR && XDL<XUR){
                yo =((XDR-XDL)/(((-XDL+XUL)/(YDL-YUL))+((XDR-XUR)/(YDR-YUR))))-((YDL+YDR)/2);
            }
            xo =(((((yo*(-XDL+XUL))/(YDL-YUL))+XDL)+(((yo*(XDR-XUR))/(YDR-YUR))+(XDR)))/2);
            link_theid();

    }
}
/**
double GenMatAss::eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj){
    return(sqrt(((x_m-x_obj)*(x_m-x_obj))+((y_m-y_obj)*(y_m-y_obj))));
}**/


double GenerateMatcam::threshold_coef(double y){
    double threshold_k;
    double konst = (YDL+YDR)/2;
    if(y!=konst){
        threshold_k  = ((y-yo)/(y-konst));
    }
    return (threshold_k);
}

void GenerateMatcam::find_threshold_x(double &x_kanan,double &x_kiri,double y,double x,double y_m){
    double k = threshold_coef(y);
    double th = k*THETA;
    if(y > yo){
        x_kanan = x+(th/2)-(((x-xo)/(y-yo))*(y_m-y));
        x_kiri = x-(th/2)-(((x-xo)/(y-yo))*(y_m-y));
    }
}

double GenerateMatcam::find_threshold_y(double y){
    double k = threshold_coef(y);
    double th = k*THETA;
    return th/2;
}


/**Hungarian Algorithms**/
void GenerateMatcam::link_theid(){
    //double Euclid_x;
    //double Euclid_y;
    int i,j;
    double th_xka,th_xki,th_y;
    Associate = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
    for(i=0;i<JUMLAH_PLAYER;i++){
       for(j=0;j<JUMLAH_PLAYER;j++){
           if(frames==2){
               Euclid_x = inits.data[j].playerData.x-curr.data[j].playerData.x;
               Euclid_y = abs(inits.data[j].playerData.y-curr.data[j].playerData.y);
               find_threshold_x(th_xka,th_xki,(double)inits.data[j].playerData.y,(double)inits.data[j].playerData.x,(double)curr.data[i].playerData.y);
               th_y=find_threshold_y((double)inits.data[j].playerData.y);
               if(Euclid_y < th_y){
                   if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                      Associate.at<int>(i,j) = 1;
                   }
                }
           }
           else{
               Euclid_x = pred.data[j].playerData.x-curr.data[j].playerData.x;
               Euclid_y = abs(pred.data[j].playerData.y-curr.data[j].playerData.y);
               find_threshold_x(th_xka,th_xki,(double)pred.data[j].playerData.y,(double)pred.data[j].playerData.x,(double)curr.data[j].playerData.y);
               th_y=find_threshold_y((double)pred.data[j].playerData.y);
               //double euclid_r = eigen_distance_transform(measurement->x_trans, measurement->y_trans, buffer->x_trans, buffer->y_trans);
               if(Euclid_y < th_y){
                   if((Euclid_x< 0 && Euclid_x> th_xki)||(Euclid_x> 0 && Euclid_x< th_xka)){
                      Associate.at<int>(i,j) = 1;
                   }
                }
           }
           /*
           if(euclid_r < threshold_glob){
                association_globe[buffer->data_id][measurement->data_id] = 1;
           }*/
       }
    }

}


