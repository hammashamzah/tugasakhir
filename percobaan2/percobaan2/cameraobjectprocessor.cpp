#include "cameraobjectprocessor.h"

CameraObjectProcessor::CameraObjectProcessor(QList<QPoint> trapeziumCoordinate, double pixelThreshold)
{
    searchingdata = new SearchPlayerData();
    XDL = trapeziumCoordinate[0].x();
    XDR = trapeziumCoordinate[3].x();
    XUL = trapeziumCoordinate[1].x();
    XUR = trapeziumCoordinate[2].x();
    YDL = trapeziumCoordinate[0].y();
    YDR = trapeziumCoordinate[3].y();
    YUL = trapeziumCoordinate[1].y();
    YUR = trapeziumCoordinate[2].y();
    THETA = pixelThreshold;
    if (YDL > YUL && YDR > YUR && XDR > XUR && XDL < XUR) {
        yo = -((XDR - XDL) / (((-XDL + XUL) / (YDL - YUL)) + ((XDR - XUR) / (YDR - YUR)))) + ((YDL + YDR) / 2);
    }
    xo = ((((((YDL - yo) * (-XDL + XUL)) / (YDL - YUL)) + XDL) + ((-(((YDR - yo) * (XDR - XUR)) / (YDR - YUR)) + (XDR)))) / 2);
    IssetCurrent = false;
}

CameraObjectProcessor::~CameraObjectProcessor(){

}
void CameraObjectProcessor::camAssociate(int minimumIndexOfObject,QList<Player> CurrentData, QList<Player> predict, QList<Player> prev){
    if(IssetCurrent){
        int i, j;
        /**Inisialisasi nilai variable yang akan digunakan**/
        curr.clear();
        curr = CurrentData;
        pred.clear();
        indicatedLostFound.clear();
        occlusion.clear();
        accCol.release();
        accRow.release();
        pot_Occlusion.clear();
        
        associate = Mat::zeros(JUMLAH_PLAYER, JUMLAH_PLAYER, CV_8U);
        accCol = Mat::zeros(JUMLAH_PLAYER, 1, CV_8U);
        accRow = Mat::zeros(JUMLAH_PLAYER, 1, CV_8U);
        
        sizeCurrent =  curr.length();
        previous = prev;
        sizePrevious = previous.length();
        pred = predict;
        sizePrediction = pred.length();
        
        if (previous.isEmpty()) {
            for (i = 0; i < sizeCurrent; i++) {
                for (j = minimumIndexOfObject; j < (minimumIndexOfObject + sizeCurrent); j++) {
                    if (i == j) {
                        associate.at<uint8_t>(i, j) += 1;
                    } else {
                        associate.at<uint8_t>(i, j) += 0;
                    }
                }
            }
            cleanData = curr;
        }
        else {
                link_theid();
                accums();
                checkFound();
                checkLost();
                checkOcclusion();
                MappingData();
                emit sendClusterOcclusion(pot_Occlusion);//menuju associate
        }
        emit updateMatrices(associate);
        emit sendLostFound(indicatedLostFound);//menuju fusionData
        emit sendcleanData(cleanData);
        IssetCurrent = false;
    }
}
double CameraObjectProcessor::threshold_coef(double y) {
    double threshold_k;
    double konst = (YDL + YDR) / 2;
    if (y != konst) {
        threshold_k  = ((y - yo) / (konst - yo));
    }
    return (threshold_k);
}
void CameraObjectProcessor::find_threshold_x(double &x_kanan, double &x_kiri, double y, double x, double y_m) {
    double k = threshold_coef(y);
    double th = k * THETA;
    x_kanan = x + (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
    x_kiri = x - (th / 2) - (((x - xo) / (y - yo)) * (y_m - y));
}
double CameraObjectProcessor::find_threshold_y(double y) {
    double k = threshold_coef(y);
    double th = k * THETA;
    return th / 2;
}
/**Hungarian Algorithms**/
void CameraObjectProcessor::link_theid() {
    int i, j;
    double th_xka, th_xki, th_y;
    if (pred.isEmpty()) {
        for (i = 0; i < sizePrevious; i++) {
            for (j = data_bef; j < data_bef + sizeCurrent; j++) {
                Euclid_x = ((double)previous.at(i).pos.x) - ((double)curr.at(j).pos.x);
                Euclid_y = abs(((double)previous.at(i).pos.y) - (((double)curr.at(j).pos.y)));
                find_threshold_x(th_xka, th_xki, (double)previous.at(i).pos.y, (double)previous.at(i).pos.x, (double)curr.at(j).pos.y);
                th_y = find_threshold_y((double)previous.at(i).pos.y);
                if (Euclid_y < th_y) {
                    if ((Euclid_x < 0 && Euclid_x >= th_xki) || (Euclid_x > 0 && Euclid_x <= th_xka)) {
                        associate.at<uint8_t>(previous.at(i).id, curr.at(j).id) += 1;
                    }
                }
            }
        }
    }
    else{
        for (i = 0; i < sizePrevious; i++) {
            for (j = data_bef; j < data_bef + sizeCurrent; j++) {
                const int idx = searchingdata->searchPlayer(pred, previous.at(i).id);
                if (idx <= sizePrevious) {
                    Euclid_x = (( BOBOT_PREDICTIONS * (pred.at(idx).pos.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.x))) - (curr.at(j).pos.x);
                    Euclid_y = abs((BOBOT_PREDICTIONS * (pred.at(idx).pos.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.y)) - curr.at(j).pos.y);
                    find_threshold_x(th_xka, th_xki, (( BOBOT_PREDICTIONS * (pred.at(idx).pos.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.y))), (( BOBOT_PREDICTIONS * (pred.at(idx).pos.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.x))), (double)curr.at(j).pos.y);
                    th_y = find_threshold_y((double)(( BOBOT_PREDICTIONS * (pred.at(idx).pos.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.y))));
                }
                else if (idx > sizePrevious) {
                    Euclid_x = (previous.at(i).pos.x) - (curr.at(j).pos.x);
                    Euclid_y = abs(previous.at(i).pos.y - curr.at(j).pos.y);
                    find_threshold_x(th_xka, th_xki, (double)previous.at(idx).pos.y, (double)previous.at(idx).pos.x, (double)curr.at(j).pos.y);
                    th_y = find_threshold_y((double)previous.at(idx).pos.y);
                }
                if (Euclid_y < th_y) {
                    if ((Euclid_x < 0 && Euclid_x >= th_xki) || (Euclid_x > 0 && Euclid_x <= th_xka)) {
                        associate.at<uint8_t>(previous.at(i).id, curr.at(j).id) += 1;
                    }
                }
            }
        }
    }
}
void CameraObjectProcessor::accums() {
    int i, j;
    for (i = 1; i < JUMLAH_PLAYER; i++) {
        for (j = data_bef; j < data_bef + sizeCurrent; j++) {
            accCol.at<uint8_t>(j) = accCol.at<uint8_t>(j) + associate.at<uint8_t>(i, j);
            accRow.at<uint8_t>(i) = accRow.at<uint8_t>(i) + associate.at<uint8_t>(i, j);
        }
    }
}
void CameraObjectProcessor::checkFound() {
    QList<Player> buffer;
    for (int j = data_bef; j < (data_bef + sizeCurrent); j++) {
        if ((accCol.at<uint8_t>(j) == 0)&&(!previous.isEmpty())) {
            buffer[j].id = j;
            buffer[j].pos.x = curr.at(j).pos.x;
            buffer[j].pos.y = curr.at(j).pos.y;
        }
    }
    indicatedLostFound.append(buffer);
}
void CameraObjectProcessor::checkLost() {
    QList<Player> buffer;
    Player buff;
    int iter;
    for (int i = 0; i < sizePrevious; i++) {
        if (accRow.at<uint8_t>(previous.at(i).id) == 0) {
            iter = searchingdata->searchPlayer(pred, previous.at(i).id);
            buff.id     = previous.at(i).id;
            buff.speed.x = previous.at(i).speed.x;
            buff.speed.y = previous.at(i).speed.y;
            buff.pos.x = (( BOBOT_PREDICTIONS * (pred.at(iter).pos.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.x)));
            buff.pos.y = (( BOBOT_PREDICTIONS * (pred.at(iter).pos.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).pos.y)));
        }
        buffer.append(buff);
    }
    indicatedLostFound.append(buffer);
}

void CameraObjectProcessor::checkOcclusion() {
    Player players;
    QList<Player> playerList;
    Mat trans = associate.t();
    for (int i = data_bef; i < data_bef + sizeCurrent; i++) {
        for (int j = 0; j < JUMLAH_PLAYER; j++) {
            if (accCol.at<uint8_t>(i) > 1 && trans.at<uint8_t>(previous.at(j).id, j) == 1) {
                players.id = previous.at(j).id;
                players.pos.x = curr.at(i).pos.x;
                players.pos.y = curr.at(i).pos.y;
                playerList.append(players);
            }
        }
        pot_Occlusion.append(playerList);
        occlusion.clear();
    }
}

void CameraObjectProcessor::MappingData(){
    cleanData.clear();
    Player buffer;
    for(int i;i<JUMLAH_PLAYER;i++){
        for(int j;j<JUMLAH_PLAYER;j++){
            if((associate.at<uint8_t>(i,j)==1)&&(accCol.at<uint8_t>(j)==1)&&(accRow.at<uint8_t>(i)==1)){
                buffer.id = previous.at(i).id;
                buffer.pos.x = curr.at(j).pos.x;
                buffer.pos.y = curr.at(j).pos.y;
                buffer.speed.x = previous.at(i).speed.x;
                buffer.speed.y =  previous.at(i).speed.y;
                cleanData.append(buffer);
            }
        }
    }
}
