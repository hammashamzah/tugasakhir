#include "unitdynamicassociate.h"

UnitDynamicAssociate::UnitDynamicAssociate() {
}
UnitDynamicAssociate::~UnitDynamicAssociate() {

}

void UnitDynamicAssociate::setParameters(QList<QPoint> trapeziumCoordinate, float associationThreshold, float occlusionThreshold) {
    XDL = (float)trapeziumCoordinate[0].x();
    XDR = (float)trapeziumCoordinate[3].x();
    XUL = (float)trapeziumCoordinate[1].x();
    XUR = (float)trapeziumCoordinate[2].x();
    YDL = (float)trapeziumCoordinate[0].y();
    YDR = (float)trapeziumCoordinate[3].y();
    YUL = (float)trapeziumCoordinate[1].y();
    YUR = (float)trapeziumCoordinate[2].y();
    associationTh = associationThreshold;
    occlusionTh = occlusionThreshold;
    /*after reobservation of the real data I think single horizon point isn't suitable to the case, we need another horizon representation being 2 horizon points*/
    //first horizon point
    xo_1 = (((XDL)*((YUL-YDL)/(XUL-XDL)))-((XDR)*((YUR-YDR)/(XUR-XDR)))+(YDR-YDL))/(((YUL-YDL)/(XUL-XDL))-((YUR-YDR)/(XUR-XDR)));
    yo_1 = (((YUL-YDL)/(XUL-XDL))*(xo_1-XDL))+YDL;
    //second horizon point
    xo_2 = (((XUL)*((YUR-YUL)/(XUR-XUL)))-((XDL)*((YDR-YDL)/(XDR-XDL)))+(YDL-YUL))/(((YUR-YUL)/(XUR-XUL))-((YDR-YDL)/(XDR-XDL)));
    yo_2 = (((YDR-YDL)/(XDR-XDL))*(xo_2-XDL))+YUR;
    /**
      the most possible implementation of 2 horizon representation is on the occlussion handler,
      but for the association handler more suitable use euclidan distance comparison
    **/
}
void UnitDynamicAssociate::dataCameraAssociation(QList<Player> previousData, QList<Player> currentData, QList<Player> predictionData, int firstID) {
    current = currentData;
    prediction = predictionData;
    previous = previousData;
    first_ID = firstID;
    potentially_New.clear();
    potentially_Lost.clear();
    dataAssociating();
    occlusionHandler();

    emit sendAssociatedData(previous);
    emit sendNewData(potentially_New);
}
float UnitDynamicAssociate::threshold_coef(float y) {
    float threshold_k;
    float konst = (YDL + YDR) / 2;
    if (y != konst) {
        threshold_k  = ((y - yo_1) / (konst - yo_1));
    }
    return (threshold_k);
}
void UnitDynamicAssociate::find_threshold_x(float &x_kanan, float &x_kiri, float y, float x, float y_m) {
    float k = threshold_coef(y);
    float th = k * associationTh;
    x_kanan = x + (th / 2) - (((x - xo_1) / (y - yo_1)) * (y_m - y));
    x_kiri = x - (th / 2) - (((x - xo_1) / (y - yo_1)) * (y_m - y));
}
float UnitDynamicAssociate::find_threshold_y(float y) {
    float k = threshold_coef(y);
    float th = k * associationTh;
    return th / 2;
}
void UnitDynamicAssociate::find_threshold_xocc(float &x_kanan, float &x_kiri, float y, float x, float y_m) {
    float k = threshold_coef(y);
    float th = k * occlusionTh;
    x_kanan = x + (th / 2) - (((x - xo_1) / (y - yo_1)) * (y_m - y));
    x_kiri = x - (th / 2) - (((x - xo_1) / (y - yo_1)) * (y_m - y));
}
float UnitDynamicAssociate::find_threshold_yocc(float y) {
    float k = threshold_coef(y);
    float th = k * occlusionTh;
    return th / 2;
}
void UnitDynamicAssociate::dataAssociating() {
    float th_xka, th_xki, th_y;
    potentially_Lost.clear();

    if (!(previous.isEmpty() && prediction.isEmpty())) {
        for (int i = 0; i < previous.size() && !current.isEmpty(); i++) {
            qDebug() << "iterasi previous data ke: " << i;
            indexMatchedPrediction =-1;
            if(!prediction.isEmpty()){
                for (int j = 0; j < prediction.size(); j++) {
                    if (prediction.at(j).id == previous.at(i).id) {
                        indexMatchedPrediction = j;
                        break;
                    }
                }
            }
            //qDebug()() << "indexMatchedPrediction: " << indexMatchedPrediction;
            if (current.isEmpty()) {
                qDebug()<<"masuk current empty";
                //set all previous data as potentially lost
                potentially_Lost.append(previous.at(i).id);
            } else {
                qDebug()<<"masuk current not empty";
                isPreviousObjectAssociated = false;
                for (int j = 0; (j < current.size()) && !current.isEmpty(); j++) {
                    if (indexMatchedPrediction > 0) {
                        qDebug()<<"PREDICTION AVAILABLE";
                        sub_proc_varx = BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.x + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.x;
                        sub_proc_vary = BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y;
                        Euclid_x = BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.x + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.x - current.at(j).pos.x;
                        Euclid_y = abs(BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y - current.at(j).pos.y);
                        find_threshold_x(th_xka, th_xki,
                                         BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y,
                                         BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.x + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.x,
                                         current.at(j).pos.y);
                        th_y = find_threshold_y(BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y);
                    } else {
                        qDebug()<<"PREDICTION UNAVAILABLE";
                        sub_proc_vary = previous.at(i).pos.y;
                        sub_proc_varx = previous.at(i).pos.x;
                        Euclid_x = previous.at(i).pos.x - current.at(j).pos.x;
                        Euclid_y = abs(previous.at(i).pos.y - current.at(j).pos.y);
                        find_threshold_x(th_xka, th_xki,
                                         previous.at(i).pos.y,
                                         previous.at(i).pos.x,
                                         current.at(j).pos.y);
                        th_y = find_threshold_y(previous.at(i).pos.y);
                    }
                    Euclid_r = sqrt((((sub_proc_varx)-(current.at(j).pos.x))*((sub_proc_varx)-(current.at(j).pos.x)))+(((sub_proc_vary)-(current.at(j).pos.y))*((sub_proc_vary)-(current.at(j).pos.y))));
                    if(Euclid_r < associationTh){
                    /*if ((Euclid_y < th_y) && ((Euclid_x <= 0 && Euclid_x >= th_xki) || (Euclid_x >= 0 && Euclid_x <= th_xka))) {*/
                        //associated
                        //qDebug()() << "object associated" << " " << i << " " << j;
                        previous[i].pos = current.at(j).pos;
                        previous[i].speed = current.at(j).speed;
                        previous[i].acceleration = current.at(j).acceleration;
                        previous[i].framePosition  = current.at(j).framePosition;
                        previous[i].camera = current.at(j).camera;
                        current.removeAt(j);
                        j--;
                        isPreviousObjectAssociated = true;
                    } else {
                        //qDebug()() << "tidak berasosiasi: " << i << " " << j;
                    }
                }
            }
            if (!isPreviousObjectAssociated) {
                //qDebug()() << "Object " << i << " with id " << previous.at(i).id << " is potentially lost";
                potentially_Lost.append(i);
            }
        }
    }
}

void UnitDynamicAssociate::occlusionHandler(){
    lostData.clear();
    if (previous.isEmpty() && prediction.isEmpty()) {
        qDebug()<<"id wasn't yet being set";
        previous.clear();
        previous.append(current);
    } else {
        //qDebug()() << "Masuk occlusion handler";
        if (current.isEmpty()) {
            //destroy all of potentially lost
            for (int i = 0; i < potentially_Lost.size(); i++) {
                for (int k = 0; k < previous.size(); k++) {
                    if (previous.at(k).id == potentially_Lost.at(i)) {
                        indexMatchedPrevious = k;
                        break;
                    }
                }
                previous.removeAt(indexMatchedPrevious);
            }
        } else {
            int h = first_ID;
            for (int i = 0; i < current.size(); i++) {
                if (!potentially_Lost.isEmpty()) {
                    isCurrentObjectOccluded = false;
                    for (int j = 0; (j < potentially_Lost.size()) && !potentially_Lost.isEmpty(); j++) {
                        //find in previous player with the same id as potentially lost
                        for (int k = 0; k < previous.size(); k++) {
                            if (previous.at(k).id == potentially_Lost.at(j)) {
                                indexMatchedPrevious = k;
                                break;
                            }
                        }
                        Euclid_x = current.at(i).pos.x - previous.at(indexMatchedPrevious).pos.x;
                        Euclid_y = abs(current.at(i).pos.y - previous.at(indexMatchedPrevious).pos.y);
                        find_threshold_xocc(th_xka, th_xki, current.at(i).pos.y, current.at(i).pos.x, previous.at(indexMatchedPrevious).pos.y);
                        th_y = find_threshold_yocc(current.at(i).pos.y);
                        if (Euclid_y < th_y && ((Euclid_x <= 0 && Euclid_x >= th_xki) || (Euclid_x >= 0 && Euclid_x <= th_xka))) {
                            //qDebug()() << "object occluded: " << j << " " << i;
                            previous[indexMatchedPrevious].pos.x = current.at(i).pos.x;
                            previous[indexMatchedPrevious].pos.y = current.at(i).pos.y;
                            previous[indexMatchedPrevious].framePosition = current.at(i).framePosition;
                            previous[indexMatchedPrevious].camera = current.at(i).camera;
                            potentially_Lost.removeAt(j);
                            j--;
                            isCurrentObjectOccluded = true;
                        }
                    }
                    if (!isCurrentObjectOccluded) {
                        current[i].id = h;
                        potentially_New.append(current.at(i));
                        h++;
                    }
                }else{
                    current[i].id = h;
                    potentially_New.append(current.at(i));
                    h++;
                }
            }
            if (!potentially_Lost.isEmpty()) {
                for (int i = 0; i < potentially_Lost.size(); i++) {
                    previous.removeAt(indexMatchedPrevious);
                }
            }
            lastID = h;
        }
    }
}
