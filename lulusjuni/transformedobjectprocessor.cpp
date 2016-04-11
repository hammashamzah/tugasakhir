#include "generatemattrans.h"


TransformedObjectProcessor::TransformedObjectProcessor(double threshold)
{
    THETA = threshold;
    IsSetMat = false;
    IsSetDataTrans = false;
}

TransformedObjectProcessor::~TransformedObjectProcessor()
{

}


void TransformedObjectProcessor::getDataTrans(QList<DataInputTrans>LostFound)//dari Aznan
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


void TransformedObjectProcessor::getAssociate(Mat initials){
    inits = initials;
    IsSetMat = true;
}


void TransformedObjectProcessor::cam_associate(){
    QlostFound.clear();
    inits.release();
    while(!IsSetMat ){
        QTest::qWait(100);
        if(IsSetMat){
            break;
        }
    }
    link_theid();
    emit UpdateAssociate(Assoc);
    emit UpdateremaindedData(remaindedDataId);
}


double TransformedObjectProcessor::eigen_distance_transform(double x_m, double y_m, double x_obj, double y_obj){
    return(sqrt(((x_m-x_obj)*(x_m-x_obj))+((y_m-y_obj)*(y_m-y_obj))));
}

/**Hungarian Algorithms**/
void TransformedObjectProcessor::link_theid(){
    int i,j;

    fixIt = Mat::zeros(JUMLAH_PLAYER,JUMLAH_PLAYER,CV_8U);
        for(i=0;i<Qfound.length();i++){
           j=0;
           while(j< Qlost.length()){
                double th_r = eigen_distance_transform((double)Qfound.at(i).Pos_trans.x,(double)Qfound.at(i).Pos_trans.y,(double)Qlost.at(j).Pos_trans.x,(double)Qlost.at(j).Pos_trans.y);
                if(th_r < THETA){
                       fixIt.at<uint8_t>(Qlost.at(j).id,Qfound.at(i).id) += 1;
                       break;
                }
                j++;
             }
           if(j== Qlost.length()){
                remaindedDataId.append(i);
           }
        }
    Assoc = fixIt + inits;
}



