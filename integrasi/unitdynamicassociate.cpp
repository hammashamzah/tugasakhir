#include "unitdynamicassociate.h"

UnitDynamicAssociate::UnitDynamicAssociate(QList<QPoint> trapeziumCoordinate, double associationThreshold, double occlusionThreshold) {
    searchingdata = new SearchPlayerData();
    XDL = (double)trapeziumCoordinate[0].x();
    XDR = (double)trapeziumCoordinate[3].x();
    XUL = (double)trapeziumCoordinate[1].x();
    XUR = (double)trapeziumCoordinate[2].x();
    YDL = (double)trapeziumCoordinate[0].y();
    YDR = (double)trapeziumCoordinate[3].y();
    YUL = (double)trapeziumCoordinate[1].y();
    YUR = (double)trapeziumCoordinate[2].y();
    associationTh = associationThreshold;
    occlusionTh = occlusionThreshold;
    if (YDL > YUL && YDR > YUR && XDR > XUR && XDL < XUR) {
        yo = -((XDR - XDL) / (((-XDL + XUL) / (YDL - YUL)) + ((XDR - XUR) / (YDR - YUR)))) + ((YDL + YDR) / 2);
    }
    xo = ((((((YDL - yo) * (-XDL + XUL)) / (YDL - YUL)) + XDL) + ((-(((YDR - yo) * (XDR - XUR)) / (YDR - YUR)) + (XDR)))) / 2);
}
UnitDynamicAssociate::~UnitDynamicAssociate() {

}

void UnitDynamicAssociate::dataCameraAssociation(QList<Player> Previous, QList<Player> Current, QList<Player> Prediction, int firstID) {
    curr = Current;
    pred = Prediction;
    previous = Previous;
    first_ID = firstID;
    dataAssociating();
    //occlusionHandler();
    emit sendAssociatedData(previous);
    emit sendNewData(potentially_New);
}
double UnitDynamicAssociate::threshold_coef(double y) {
    double threshold_k;
    double konst = (YDL + YDR) / 2;
    if (y != konst) {
        threshold_k  = ((y - yo) / (konst - yo));
    }
    return (threshold_k);
}
void UnitDynamicAssociate::find_threshold_x(double &x_kanan, double &x_kiri, double y, double x, double y_m) {
    double k = threshold_coef(y);
    double th = k * associationTh;
    x_kanan = x + (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
    x_kiri = x - (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
}
double UnitDynamicAssociate::find_threshold_y(double y) {
    double k = threshold_coef(y);
    double th = k * associationTh;
    return th / 2;
}
void UnitDynamicAssociate::find_threshold_xocc(double &x_kanan, double &x_kiri, double y, double x, double y_m) {
    double k = threshold_coef(y);
    double th = k * occlusionTh;
    x_kanan = x + (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
    x_kiri = x - (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
}
double UnitDynamicAssociate::find_threshold_yocc(double y) {
    double k = threshold_coef(y);
    double th = k * occlusionTh;
    return th / 2;
}
void UnitDynamicAssociate::dataAssociating() {
    int i, j, k;
    double th_xka, th_xki, th_y;
    potentially_Lost.clear();
    qDebug() << "Previous: " << previous.isEmpty();
    if (previous.isEmpty()) {
        qDebug() << "Initial Frame";
        //for initial frame
        previous.append(curr);
    } else {
        for (i = 0; i < previous.size() ; i++) {
            k = 0;
            for (; j < curr.size(); j++) {
                const int idx = searchingdata->searchPlayer(pred, previous.at(i).id);
                if (idx <= previous.size()) {
                    Euclid_x = (( BOBOT_PREDICTIONS * (pred.at(idx).pos.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.x))) - (curr.at(j).pos.x);
                    Euclid_y = abs((BOBOT_PREDICTIONS * (pred.at(idx).pos.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.y)) - curr.at(j).pos.y);
                    find_threshold_x(th_xka, th_xki, (( BOBOT_PREDICTIONS * (pred.at(idx).pos.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.y))), (( BOBOT_PREDICTIONS * (pred.at(idx).pos.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.x))), (double)curr.at(j).pos.y);
                    th_y = find_threshold_y((double)(( BOBOT_PREDICTIONS * (pred.at(idx).pos.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.y))));
                }
                else if (idx > previous.size()) {
                    Euclid_x = (previous.at(i).pos.x) - (curr.at(j).pos.x);
                    Euclid_y = abs(previous.at(i).pos.y - curr.at(j).pos.y);
                    find_threshold_x(th_xka, th_xki, (double)previous.at(idx).pos.y, (double)previous.at(idx).pos.x, (double)curr.at(j).pos.y);
                    th_y = find_threshold_y((double)previous.at(idx).pos.y);
                }
                if (Euclid_y < th_y) {
                    if ((Euclid_x < 0 && Euclid_x >= th_xki) || (Euclid_x > 0 && Euclid_x <= th_xka)) {
                        previous[i].pos.x = curr.at(j).pos.x;
                        previous[i].pos.y = curr.at(j).pos.y;
                        previous[i].speed.x = pred.at(j).speed.x;
                        previous[i].speed.y = curr.at(j).speed.y;
                        previous[i].acceleration.x = pred.at(j).acceleration.x;
                        previous[i].acceleration.y = curr.at(j).acceleration.y;
                        previous[i].framePosition  = curr.at(j).framePosition;
                        previous[i].camera = curr.at(j).camera;
                        curr.removeAt(j);
                    }
                    else {
                        k++;
                    }
                }
                else {
                    k++;
                }
            }
            if (k == curr.size() - 1) {
                potentially_Lost.append(i);
            }
        }
    }
}

void UnitDynamicAssociate::occlusionHandler() {
    int i, j;
    int h = first_ID;
    for (i = 0; i < curr.size(); i++) {
        int k = 0;
        j = 0;
        while (j < potentially_Lost.size()) {
            Euclid_x = ((double)curr.at(i).pos.x) - ((double)previous.at(potentially_Lost.at(j)).pos.x);
            Euclid_y = abs(((double)curr.at(i).pos.y) - (((double)previous.at(potentially_Lost.at(j)).pos.y)));
            find_threshold_xocc(th_xka, th_xki, (double)curr.at(i).pos.y, (double)curr.at(i).pos.x, (double)previous.at(potentially_Lost.at(j)).pos.y);
            th_y = find_threshold_yocc((double)curr.at(i).pos.y);
            if (Euclid_y < th_y) {
                if ((Euclid_x < 0 && Euclid_x >= th_xki) || (Euclid_x > 0 && Euclid_x <= th_xka)) {
                    previous[potentially_Lost.at(j)].pos.x = curr.at(j).pos.x;
                    previous[potentially_Lost.at(j)].pos.y = curr.at(j).pos.y;
                    previous[potentially_Lost.at(j)].framePosition = curr.at(j).framePosition;
                    previous[potentially_Lost.at(j)].camera = curr.at(j).camera;
                    potentially_Lost.removeAt(j);
                }
                else {
                    k++;
                }
            }
            else {
                k++;
            }
            j++;
        }
        if (k == (potentially_Lost.size() - 1)) {
            curr[i].id = h;
            potentially_New.append(curr.at(i));
            h++;
        }
    }
    if (!potentially_Lost.isEmpty()) {
        for (i = 0; i < potentially_Lost.size(); i++) {
            previous.removeAt(potentially_Lost.at(i));
        }
    }
    lastID = h;
}
