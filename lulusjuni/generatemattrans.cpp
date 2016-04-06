#include "generatemattrans.h"

GenerateMatTrans::GenerateMatTrans(double threshold)
{
    THETA = threshold;
}
GenerateMatTrans::~GenerateMatTrans()
{

}


void GenerateMatTrans::getAssociate(Mat initials){
    inits = initials;
    Isset3 = true;
}


void GenerateMatTrans::cam_associate(QList<DataInputTrans> Lost,QList<DataInputTrans> Found){
    Qlost =Lost;
    sizeQLost = Qlost.length();
    QFound = Found;
    sizeQFound =QFound.length();
    if(Isset1 & Isset2 & Isset3){
        link_theid();
    }
    emit UpdateAssociate(Assoc);
    Qlost.clear();
    QFound.clear();
    inits.release();
}


double GenerateMatTrans::eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj){
    return(sqrt(((x_m-x_obj)*(x_m-x_obj))+((y_m-y_obj)*(y_m-y_obj))));
}
/**Hungarian Algorithms**/
void GenerateMatTrans::link_theid(){
    //double Euclid_x;
    //double Euclid_y;
    int i,j;
    fixIt = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
        for(i=0;i<sizeQLost;i++){
           for(j=0;j<sizeQFound;j++){
                double th_r = eigen_distance_transform((double)QFound.at(j).Pos_trans.x,(double)QFound.at(j).Pos_trans.y,(double)Qlost.at(i).Pos_trans.x,(double)Qlost.at(i).Pos_trans.y);
                if(th_r < THETA){
                       fixIt.at<int>(Qlost.at(i).id,QFound.at(i).id) = 1;
                   }
             }
        }
    Assoc = fixIt + inits;
}



