#include "generatematcam.h"

CameraObjectProcessor::CameraObjectProcessor(QList<QPoint> trapeziumCoordinate, double pixelThreshold)
{
    XDL = trapeziumCoordinate[0].x();
    XDR = trapeziumCoordinate[3].x();
    XUL = trapeziumCoordinate[1].x();
    XUR = trapeziumCoordinate[2].x();
    YDL = trapeziumCoordinate[0].y();
    YDR = trapeziumCoordinate[3].y();
    YUL = trapeziumCoordinate[1].y();
    YUR = trapeziumCoordinate[2].y();
    THETA = pixel_th;
    if (YDL > YUL && YDR > YUR && XDR > XUR && XDL < XUR) {
        yo = -((XDR - XDL) / (((-XDL + XUL) / (YDL - YUL)) + ((XDR - XUR) / (YDR - YUR)))) + ((YDL + YDR) / 2);
    }
    xo = ((((((YDL - yo) * (-XDL + XUL)) / (YDL - YUL)) + XDL) + ((-(((YDR - yo) * (XDR - XUR)) / (YDR - YUR)) + (XDR)))) / 2);
    IssetCurrent = false;
}
CameraObjectProcessor::~CameraObjectProcessor()
{


}


void CameraObjectProcessor::camAssociate(int minimumIndexOfObject, int Fr, QList<DataInputCam> predict, QList<DataInputCam> prev) {
    int i, j;
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
    if (Fr == 1) {
        for (i = 0; i < sizeCurrent; i++) {
            for (j = minimumIndexOfObject; j < (minimumIndexOfObject + sizeCurrent); j++) {
                if (i == j) {
                    associate.at<uint8_t>(i, j) += 1;
                } else {
                    associate.at<uint8_t>(i, j) += 0;
                }
            }
        }
    }
    else {
        if (!previous.isEmpty()) {
            link_theid();
            accums();
            checkFound();
            checkLost();
            checkOcclusion();
            generateOcclusionCluster();
            emit sendOcclusion(pot_Occlusion);//menuju associate
        }
    }
    emit updateMatrices(associate);
    emit sendLostFound(indicatedLostFound);//menuju fusionData
    IssetCurrent = false;
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
    if (frames == 2) {
        for (i = 0; i < sizePrevious; i++) {
            for (j = data_bef; j < data_bef + sizeCurrent; j++) {
                Euclid_x = ((double)previous.at(i).dataplayer.x) - ((double)curr.at(j).dataplayer.x);
                Euclid_y = abs(((double)previous.at(i).dataplayer.y) - (((double)curr.at(j).dataplayer.y)));
                find_threshold_x(th_xka, th_xki, (double)previous.at(i).dataplayer.y, (double)previous.at(i).dataplayer.x, (double)curr.at(j).dataplayer.y);
                th_y = find_threshold_y((double)previous.at(i).dataplayer.y);
                if (Euclid_y < th_y) {
                    if ((Euclid_x < 0 && Euclid_x >= th_xki) || (Euclid_x > 0 && Euclid_x <= th_xka)) {
                        associate.at<uint8_t>(previous.at(i).id, curr.at(j).id) += 1;
                    }
                }
            }
        }
    }
    else {
        for (i = 0; i < sizePrevious; i++) {
            for (j = data_bef; j < data_bef + sizeCurrent; j++) {
                const int idx = obj.foo(pred, previous.at(i).id);
                if (idx <= sizePrevious) {
                    Euclid_x = (( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).dataplayer.x))) - (curr.at(j).dataplayer.x);
                    Euclid_y = abs(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).dataplayer.y)) - curr.at(j).dataplayer.y);
                    find_threshold_x(th_xka, th_xki, (( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).dataplayer.y))), (( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).dataplayer.x))), (double)curr.at(j).dataplayer.y);
                    th_y = find_threshold_y((double)(( BOBOT_PREDICTIONS * (pred.at(idx).dataplayer.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).dataplayer.y))));
                }
                else if (idx > sizePrevious) {
                    Euclid_x = (previous.at(i).dataplayer.x) - (curr.at(j).dataplayer.x);
                    Euclid_y = abs(previous.at(i).dataplayer.y - curr.at(j).dataplayer.y);
                    find_threshold_x(th_xka, th_xki, (double)previous.at(idx).dataplayer.y, (double)previous.at(idx).dataplayer.x, (double)curr.at(j).dataplayer.y);
                    th_y = find_threshold_y((double)previous.at(idx).dataplayer.y);
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
    QList<DataInputCam> buffer;
    for (int j = data_bef; j < (data_bef + sizeCurrent); j++) {
        if ((accCol.at<uint8_t>(j) == 0) & (frames != 1)) {
            buffer[j].id = j;
            buffer[j].dataplayer.x = curr.at(j).dataplayer.x;
            buffer[j].dataplayer.y = curr.at(j).dataplayer.y;
            buffer[j].flag = false;//found
            
        }
    }
    indicatedLostFound.append(buffer);
}

void CameraObjectProcessor::checkLost() {
    QList<DataInputCam> buffer;
    int iter;
    for (int i = 0; i < sizePrevious; i++) {
        if (accRow.at<uint8_t>(previous.at(i).id) == 0) {
            iter = obj.foo(pred, previous.at(i).id);
            buffer[i].id     = previous.at(i).id;
            buffer[i].flag = true;//lost
            buffer[i].pixelSpeed.x = previous.at(i).pixelSpeed.x;
            buffer[i].pixelSpeed.y = previous.at(i).pixelSpeed.y;
            buffer[i].dataplayer.x = (( BOBOT_PREDICTIONS * (pred.at(iter).dataplayer.x)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).dataplayer.x)));
            buffer[i].dataplayer.y = (( BOBOT_PREDICTIONS * (pred.at(iter).dataplayer.y)) + ((1 - BOBOT_PREDICTIONS) * (previous.at(i).dataplayer.y)));
            //buffer.dataplayer.width =(( BOBOT_PREDICTIONS * (pred.at(iter).dataplayer.width))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.width)));
            //buffer.dataplayer.height =(( BOBOT_PREDICTIONS * (pred.at(iter).dataplayer.height))+((1-BOBOT_PREDICTIONS)*(previous.at(i).dataplayer.height)));
        }
    }
    indicatedLostFound.append(buffer);
}

void CameraObjectProcessor::generateOcclusionCluster() {
    DataInputCam buff;
    QList <DataInputCam> buffer;
    if (!occlusion.isEmpty()) {
        for (int i = 0; i < JUMLAH_PLAYER; i++) {
            if (accCol.at<uint8_t>(i) > 1) {
                for (int j = 0; j < occlusion.length(); j++) {
                    if (occlusion.at(j).y == i) {
                        buff.id = occlusion.at(j).x;
                        buff.dataplayer = curr.at(j).dataplayer;
                        buff.flag = curr.at(j).flag;
                        buffer.append(buff);
                    }
                }
                pot_Occlusion.append(buffer);
                buffer.clear();
            }
        }
    }
}

void CameraObjectProcessor::checkOcclusion() {
    Point buffer;
    for (int i = 0; i < JUMLAH_PLAYER; i++) {
        for (int j = data_bef; j < data_bef + sizeCurrent; j++) {
            if (accCol.at<uint8_t>(j) > 1 && associate.at<uint8_t>(previous.at(i).id, j) == 1) {
                buffer.x = previous.at(i).id;
                buffer.y = j;
                occlusion.append(buffer);
            }
        }
    }
}
