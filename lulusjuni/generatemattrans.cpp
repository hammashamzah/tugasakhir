#include "generatemattrans.h"

GenerateMatTrans::GenerateMatTrans(double threshold)
{
    THETA = threshold;
}
GenerateMatTrans::~GenerateMatTrans()
{

}
void GenerateMatTrans::updatePredic(QList<DataInputTrans> predic){
     pred = predic;
     sizePredic = pred.length();
     Isset1 = true;
}
void GenerateMatTrans::updateinit(QList<DataInputTrans> init){
     inits = init;
     sizeInit = inits.length();
     Isset2 = true;
}
void GenerateMatTrans::updateCurrent(QList<DataInputTrans> current){
      curr = current;
      sizeCurrent = curr.length();
      Isset3 = true;
}
void GenerateMatTrans::updateFrame(int fr){
    frames =fr;
    Isset4 = true;
}

void GenerateMatTrans::cam_associate(){
    if(Isset1  & Isset2 & Isset3){
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
    Isset1 = false;Isset2 = false;Isset3 = false;Isset4 = false;
    emit UpdateAssociate(Associate);
    curr.clear();
    pred.clear();
    inits.clear();
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
           if(frames==2){
               for(i=0;i<sizeInit;i++){
                  for(j=0;j<sizeCurrent;j++){
                       double th_r = eigen_distance_transform((double)curr.at(j).Pos_trans.x,(double)curr.at(j).Pos_trans.y,(double)inits.at(i).Pos_trans.x,(double)inits.at(i).Pos_trans.y);
                       if(th_r < THETA){
                              Associate.at<int>(i,j) = 1;
                          }
                    }
               }
           }
           else{
                for(i=0;i<sizePredic;i++){
                  for(j=0;j<sizeCurrent;j++){
                        double th_r = eigen_distance_transform((double)curr.at(j).Pos_trans.x,(double)curr.at(j).Pos_trans.y,(double)pred.at(i).Pos_trans.x,(double)pred.at(i).Pos_trans.y);
                        if(th_r < THETA){
                            Associate.at<int>(i,j) = 1;
                        }
                    }
                }
            }
}


