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
    if (YDL > YUL && YDR > YUR && XDR > XUR && XDL < XUR) {
        yo = -((XDR - XDL) / (((-XDL + XUL) / (YDL - YUL)) + ((XDR - XUR) / (YDR - YUR)))) + ((YDL + YDR) / 2);
    }
    xo = ((((((YDL - yo) * (-XDL + XUL)) / (YDL - YUL)) + XDL) + ((-(((YDR - yo) * (XDR - XUR)) / (YDR - YUR)) + (XDR)))) / 2);
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
        threshold_k  = ((y - yo) / (konst - yo));
    }
    return (threshold_k);
}
void UnitDynamicAssociate::find_threshold_x(float &x_kanan, float &x_kiri, float y, float x, float y_m) {
    float k = threshold_coef(y);
    float th = k * associationTh;
    x_kanan = x + (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
    x_kiri = x - (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
}
float UnitDynamicAssociate::find_threshold_y(float y) {
    float k = threshold_coef(y);
    float th = k * associationTh;
    return th / 2;
}
void UnitDynamicAssociate::find_threshold_xocc(float &x_kanan, float &x_kiri, float y, float x, float y_m) {
    float k = threshold_coef(y);
    float th = k * occlusionTh;
    x_kanan = x + (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
    x_kiri = x - (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
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
            QString temp1 = "Current Data: ";
            for (int a = 0; a < current.size(); a++)
            {
                temp1 += " ";
                temp1 += QString::number(current.at(a).id);
            }
            qDebug() << temp1;

            QString temp2 = "Previous Data: ";
            for (int b = 0; b < previous.size(); b++)
            {
                temp2 += " ";
                temp2 += QString::number(previous.at(b).id);
            }
            qDebug() << temp2;
            QString temp3 = "Prediction Data: ";
            for (int c = 0; c < prediction.size(); c++)
            {
                temp3 += " ";
                temp3 += QString::number(prediction.at(c).id);
            }
            qDebug() << temp3;
            int indexMatchedPrediction = -1;
            //find matched prediction id
            for (int j = 0; j < prediction.size(); j++) {
                if (prediction.at(j).id == previous.at(i).id) {
                    indexMatchedPrediction = j;
                    break;
                }
            }
            qDebug() << "indexMatchedPrediction: " << indexMatchedPrediction;
            if (current.isEmpty()) {
                //set all previous data as potentially lost
                potentially_Lost.append(i);
            } else {
                isPreviousObjectAssociated = false;
                for (int j = 0; j < current.size() ; j++) {
                    if (indexMatchedPrediction > 0) {
                        Euclid_x = BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.x + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.x - current.at(j).pos.x;
                        Euclid_y = abs(BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y - current.at(j).pos.y);
                        find_threshold_x(th_xka, th_xki,
                                         BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y,
                                         BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.x + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.x,
                                         current.at(j).pos.y);
                        th_y = find_threshold_y(BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y);
                    } else {
                        Euclid_x = previous.at(i).pos.x - current.at(j).pos.x;
                        Euclid_y = abs(previous.at(i).pos.y - current.at(j).pos.y);
                        find_threshold_x(th_xka, th_xki,
                                         previous.at(i).pos.y,
                                         previous.at(i).pos.x,
                                         current.at(j).pos.y);
                        th_y = find_threshold_y(previous.at(i).pos.y);
                    }

                    if ((Euclid_y < th_y) && ((Euclid_x <= 0 && Euclid_x >= th_xki) || (Euclid_x >= 0 && Euclid_x <= th_xka))) {
                        //associated
                        qDebug() << "object associated" << " " << i << " " << j;
                        previous[i].pos = current.at(j).pos;
                        previous[i].speed = current.at(j).speed;
                        previous[i].acceleration = current.at(j).acceleration;
                        previous[i].framePosition  = current.at(j).framePosition;
                        previous[i].camera = current.at(j).camera;
                        current.removeAt(j);
                        isPreviousObjectAssociated = true;
                    } else {
                        qDebug() << "tidak berasosiasi: " << i << " " << j;
                    }
                }
            }
            if (!isPreviousObjectAssociated) {
                qDebug() << "Object " << i << " with id " << previous.at(i).id << " is potentially lost";
                potentially_Lost.append(i);
            }
        }
    }
}

void UnitDynamicAssociate::occlusionHandler() {
    if (previous.isEmpty() && prediction.isEmpty()) {
        previous.append(current);
    } else {
        if (current.isEmpty()) {
            //destroy all of potentially lost
            for (int i = 0; i < potentially_Lost.size(); i++) {
                previous.removeAt(potentially_Lost.at(i));
            }
        } else {
            int h = first_ID;
            for (int i = 0; i < current.size() && !potentially_Lost.isEmpty(); i++) {
                isCurrentObjectOccluded = false;
                for (int j = 0; j < potentially_Lost.size() && !potentially_Lost.isEmpty(); j++) {
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
                        qDebug() << "object occluded: " << j << " " << i;
                        previous[indexMatchedPrevious].pos.x = current.at(j).pos.x;
                        previous[indexMatchedPrevious].pos.y = current.at(j).pos.y;
                        previous[indexMatchedPrevious].framePosition = current.at(j).framePosition;
                        previous[indexMatchedPrevious].camera = current.at(j).camera;
                        potentially_Lost.removeAt(j);
                        isCurrentObjectOccluded = true;
                    }
                }
                if (!isCurrentObjectOccluded) {
                    current[i].id = h;
                    potentially_New.append(current.at(i));
                    h++;
                }
            }
            if (!potentially_Lost.isEmpty()) {
                for (int i = 0; i < potentially_Lost.size(); i++) {
                    previous.removeAt(potentially_Lost.at(i));
                }
            }

            lastID = h;
        }
    }
}
