#include "generatemattrans.h"


GenerateMatTrans::GenerateMatTrans(double threshold)
{
    THETA = threshold;
}

GenerateMatTrans::~GenerateMatTrans()
{


}

void GenerateMatTrans::updatePredic(bool Isset,Arrdattrans predic){
    if(Isset){
        pred = predic.data;
    }
}

void GenerateMatTrans::updateinit(bool Isset, Arrdattrans init){
    if(Isset){
        inits = init.data;
    }
}

void GenerateMatTrans::updateCurrent(bool Isset, Arrdattrans current){
    if(Isset){
        curr = current.data;
        frames =  current.frame;
    }
}




void GenerateMatTrans::cam_associate(){
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
            link_theid();

    }
}

double GenerateMatTrans::eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj){
    return(sqrt(((x_m-x_obj)*(x_m-x_obj))+((y_m-y_obj)*(y_m-y_obj))));
}



/**Hungarian Algorithms**/
void GenerateMatTrans::link_theid(){
    //double Euclid_x;
    //double Euclid_y;
    int i,j;
    Associate = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
    for(i=0;i<JUMLAH_PLAYER;i++){
       for(j=0;j<JUMLAH_PLAYER;j++){
           if(frames==2){
               double th_r = eigen_distance_transform((double)curr.data[i].Pos_trans.x,(double)curr.data[i].Pos_trans.y,(double)inits.data[j].Pos_trans.x,(double)inits.data[j].Pos_trans.y);
               if(th_r < THETA){
                      Associate.at<int>(i,j) = 1;
                  }
           }
           else{
               double th_r = eigen_distance_transform((double)curr.data[i].Pos_trans.x,(double)curr.data[i].Pos_trans.y,(double)pred.data[j].Pos_trans.x,(double)pred.data[j].Pos_trans.y);
               if(th_r < THETA){
                      Associate.at<int>(i,j) = 1;
                }
           }
       }
    }

}


