#include "generatemattrans.h"

GenerateMatTrans::GenerateMatTrans(double threshold)
{
    THETA = threshold;
    IsSetMat = false;
    IsSetDataTrans = false;
}

GenerateMatTrans::~GenerateMatTrans()
{

}


void GenerateMatTrans::getDataTrans(QList<DataInputTrans>LostFound)//dari Aznan
{
    QlostFound = LostFound;
    for(int i=0;i<QlostFound.length();i++){
        if(QlostFound.at(i).flag == false){
            Qfound.append(QlostFound.at(i));
        }
        else if(QlostFound.at(i).flag == true){
            Qlost.append(QlostFound.at(i));
        }
    }
    IsSetDataTrans = true;
}


void GenerateMatTrans::getAssociate(Mat initials){
    inits = initials;
    IsSetMat = true;
}


void GenerateMatTrans::cam_associate(){
    QlostFound.clear();
    inits.release();
    while(!IsSetDataTrans || !IsSetMat){
        if(IsSetDataTrans && IsSetMat){
            break;
        }
    }\
    link_theid();
    emit UpdateAssociate(Assoc);
}


double GenerateMatTrans::eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj){
    return(sqrt(((x_m-x_obj)*(x_m-x_obj))+((y_m-y_obj)*(y_m-y_obj))));
}
/**Hungarian Algorithms**/
void GenerateMatTrans::link_theid(){
    int i,j;
    fixIt = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
        for(i=0;i<Qlost.length();i++){
           for(j=0;j<Qfound.length();j++){
                double th_r = eigen_distance_transform((double)Qfound.at(j).Pos_trans.x,(double)Qfound.at(j).Pos_trans.y,(double)Qlost.at(i).Pos_trans.x,(double)Qlost.at(i).Pos_trans.y);
                if(th_r < THETA){
                       fixIt.at<uint8_t>(Qlost.at(i).id,Qfound.at(i).id) += 1;
                   }
             }
        }
    Assoc = fixIt + inits;
}



