#include "cameratransition.h"

CameraTransition::CameraTransition(double ThresholdCameraTransition){
    thresholdCameraTransition = ThresholdCameraTransition;
}

CameraTransition::~CameraTransition(){

}
void CameraTransition::transformedAssociation(QVector<QList<Player> > CombinedNewPotentiallyLost){
    buffer1.clear();
    buffer2.clear();
    Player buff;
    int k;
    if(!CombinedNewPotentiallyLost.at(0).isEmpty() && !CombinedNewPotentiallyLost.at(1).isEmpty()){//associated Transformed Data
        for(int i=0;i<cameraTRansitionResult.at(1).size();i++){
            for(int j=0;j<cameraTRansitionResult.at(0).size();j++){
                k = -1;
                euclid_Distance = sqrt(((cameraTRansitionResult.at(1).at(i).transformedPos.x-cameraTRansitionResult.at(0).at(j).transformedPos.x)*(cameraTRansitionResult.at(1).at(i).transformedPos.x-cameraTRansitionResult.at(0).at(j).transformedPos.x))+((cameraTRansitionResult.at(1).at(i).transformedPos.y-cameraTRansitionResult.at(0).at(j).transformedPos.y)*(cameraTRansitionResult.at(1).at(i).transformedPos.y-cameraTRansitionResult.at(0).at(j).transformedPos.y)));
                if(euclid_Distance < thresholdCameraTransition){
                    buff.id=cameraTRansitionResult.at(0).at(j).id;
                    buff.camera=cameraTRansitionResult.at(i).at(i).camera;
                    buff.pos.x=cameraTRansitionResult.at(1).at(i).pos.x;
                    buff.pos.y=cameraTRansitionResult.at(1).at(i).pos.y;
                    buff.pos.x=cameraTRansitionResult.at(1).at(i).pos.x;
                    buff.transformedPos.x=cameraTRansitionResult.at(1).at(i).transformedPos.x;
                    buff.transformedPos.y=cameraTRansitionResult.at(1).at(i).transformedPos.y;
                    buff.framePosition=cameraTRansitionResult.at(1).at(i).framePosition;
                    cameraTRansitionResult[1].removeAt(i);
                    i--;
                    buffer1.append(buff);
                    k = i;
                }
            }
            if(k==-1){
                buffer2.append(cameraTRansitionResult.at(1).at(i));
            }
        }
    }
    else if(CombinedNewPotentiallyLost.at(0).isEmpty() && !CombinedNewPotentiallyLost.at(1).isEmpty()){//just bypass NewData
        buffer2.append(CombinedNewPotentiallyLost.at(1));
    }
    else if(!CombinedNewPotentiallyLost.at(0).isEmpty() && CombinedNewPotentiallyLost.at(1).isEmpty()){//just destroy Potentially Lost, posible to be Noise

    }
    else{//just return empty data

    }
    cameraTRansitionResult[1]=buffer2;
    cameraTRansitionResult[0]=buffer1;
    emit sendReturnData(cameraTRansitionResult);
}

void CameraTransition::getDataandSendtobeTransformed(QVector<QList<Player> > dataInput){
    emit sendTobeTransformed(dataInput);
}
