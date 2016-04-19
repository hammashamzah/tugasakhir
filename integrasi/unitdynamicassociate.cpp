#include "unitdynamicassociate.h"

UnitDynamicAssociate::UnitDynamicAssociate(QList<QPoint> trapeziumCoordinate, float associationThreshold, float occlusionThreshold) {
    searchingdata = new SearchPlayerData();
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
UnitDynamicAssociate::~UnitDynamicAssociate() {

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
    ////qDebug() << "Previous: " << previous.isEmpty();
    if (previous.isEmpty() && prediction.isEmpty()) {
        ////qDebug() << "Initial Frame";
        //for initial frame
        previous.append(current);
    } else {
        for (int i = 0; i < previous.size() ; i++) {
            isPreviousObjectAssociated = false;
            int indexMatchedPrediction = -1;
            for (int j = 0; j < prediction.size(); j++) {
                if (prediction.at(i).id == previous.at(i).id) {
                    indexMatchedPrediction = j;
                    break;
                }
            }

            for (int j = 0; j < current.size(); j++) {
                Euclid_x = BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.x + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.x - current.at(j).pos.x;
                Euclid_y = abs(BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y - current.at(j).pos.y);
                find_threshold_x(th_xka, th_xki,
                                 BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y,
                                 BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.x + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.x,
                                 current.at(j).pos.y);
                th_y = find_threshold_y(BOBOT_PREDICTIONS * prediction.at(indexMatchedPrediction).pos.y + (1 - BOBOT_PREDICTIONS) * previous.at(i).pos.y);

                if ((Euclid_y < th_y) && ((Euclid_x < 0 && Euclid_x >= th_xki) || (Euclid_x > 0 && Euclid_x <= th_xka))) {
                    //associated
                    previous[i].pos = current.at(j).pos;
                    previous[i].speed = prediction.at(j).speed;
                    previous[i].acceleration = prediction.at(j).acceleration;
                    ////qDebug() << "frame position is the same: " << (previous[i].framePosition == current.at(j).framePosition);
                    previous[i].framePosition  = current.at(j).framePosition;
                    previous[i].camera = current.at(j).camera;
                    current.removeAt(j);
                    isPreviousObjectAssociated = true;
                }
            }
            if (!isPreviousObjectAssociated) {
                potentially_Lost.append(i);
            }
        }
    }
}

void UnitDynamicAssociate::occlusionHandler() {
    int h = first_ID;
    for (int i = 0; i < current.size(); i++) {
        isPreviousObjectOccluded = false;
        for (int j = 0; j < potentially_Lost.size(); j++) {
            Euclid_x = ((float)current.at(i).pos.x) - ((float)previous.at(potentially_Lost.at(j)).pos.x);
            Euclid_y = abs(((float)current.at(i).pos.y) - (((float)previous.at(potentially_Lost.at(j)).pos.y)));
            find_threshold_xocc(th_xka, th_xki, (float)current.at(i).pos.y, (float)current.at(i).pos.x, (float)previous.at(potentially_Lost.at(j)).pos.y);
            th_y = find_threshold_yocc((float)current.at(i).pos.y);
            if (Euclid_y < th_y && ((Euclid_x < 0 && Euclid_x >= th_xki) || (Euclid_x > 0 && Euclid_x <= th_xka))) {
                previous[potentially_Lost.at(j)].pos.x = current.at(j).pos.x;
                previous[potentially_Lost.at(j)].pos.y = current.at(j).pos.y;
                previous[potentially_Lost.at(j)].framePosition = current.at(j).framePosition;
                previous[potentially_Lost.at(j)].camera = current.at(j).camera;
                potentially_Lost.removeAt(j);
                isPreviousObjectOccluded = true;
            }
        }
        if (!isPreviousObjectOccluded) {
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
