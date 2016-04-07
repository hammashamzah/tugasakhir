#include "PlayerTracker.h"


PlayerTracker::PlayerTracker(double FR, double xdl1, double xdr1, double xul1, double xur1, double ydl1, double ydr1, double yul1, double yur1, double pixel_th1,
                             double xdl2, double xdr2, double xul2, double xur2, double ydl2, double ydr2, double yul2, double yur2, double pixel_th2,
                             double xdl3, double xdr3, double xul3, double xur3, double ydl3, double ydr3, double yul3, double yur3, double pixel_th3,
                             double THcam1, double THcam2, double THcam3, mode ops) {
    operate = ops;
    generateCam1 = new GenerateMatCam(1, xdl1, xdr1, xul1, xur1, ydl1, ydr1, yul1, yur1, pixel_th1);
    generateCam2 = new GenerateMatCam(2, xdl2, xdr2, xul2, xur2, ydl2, ydr2, yul2, yur2, pixel_th2);
    generateCam3 = new GenerateMatCam (3, xdl3, xdr3, xul3, xur3, ydl3, ydr3, yul3, yur3, pixel_th3);
    generateCamTrans1 = new GenerateMatTrans (THcam1);
    generateCamTrans2 = new GenerateMatTrans (THcam2);
    generateCamTrans3 = new GenerateMatTrans (THcam3);
    kalmancam1  = new Kalmanobj (1, xdl1, xdr1, xul1, xur1, ydl1, ydr1, yul1, yur1, FR);
    kalmancam2  = new Kalmanobj (2, xdl2, xdr2, xul2, xur2, ydl2, ydr2, yul2, yur2, FR);
    kalmancam3  = new Kalmanobj (3, xdl2, xdr2, xul2, xur2, ydl2, ydr2, yul2, yur2, FR);
    Associe     = new Associate (operate);

    QObject::connect(kalmancam1, SIGNAL(updatePrediction(QList<DataInputCam>)), generateCam1, SLOT(updatePredic(QList<DataInputCam>)));
    QObject::connect(kalmancam1, SIGNAL(sendPrevious(QList<DataInputCam>)), generateCam1, SLOT(updatePrevious(QList<DataInputCam>)));
    QObject::connect(kalmancam2, SIGNAL(updatePrediction(QList<DataInputCam>)), generateCam2, SLOT(updatePredic(QList<DataInputCam>)));
    QObject::connect(kalmancam2, SIGNAL(sendPrevious(QList<DataInputCam>)), generateCam2, SLOT(updatePrevious(QList<DataInputCam>)));
    QObject::connect(kalmancam3, SIGNAL(updatePrediction(QList<DataInputCam>)), generateCam3, SLOT(updatePredic(QList<DataInputCam>)));
    QObject::connect(kalmancam3, SIGNAL(sendPrevious(QList<DataInputCam>)), generateCam3, SLOT(updatePrevious(QList<DataInputCam>)));
    QObject::connect(generateCam1, SIGNAL(updateMatrices(Mat)), generateCamTrans1, SLOT(getAssociate(Mat)));
    QObject::connect(generateCam1, SIGNAL(updateOcclusion(QList<Point>)), Associe, SLOT(getOcclusion1(QList<Point>)));
    QObject::connect(generateCam1, SIGNAL(sendCurrent(QList<DataInputCam>)), Associe, SLOT(updateCurrentCam1(QList<DataInputCam>)));
    QObject::connect(generateCam2, SIGNAL(updateMatrices(Mat)), generateCamTrans2, SLOT(getAssociate(Mat)));
    QObject::connect(generateCam2, SIGNAL(updateOcclusion(QList<Point>)), Associe, SLOT(getOcclusion2(QList<Point>)));
    QObject::connect(generateCam2, SIGNAL(sendCurrent(QList<DataInputCam>)), Associe, SLOT(updateCurrentCam2(QList<DataInputCam>)));
    QObject::connect(generateCam3, SIGNAL(updateMatrices(Mat)), generateCamTrans2, SLOT(getAssociate(Mat)));
    QObject::connect(generateCam3, SIGNAL(updateOcclusion(QList<Point>)), Associe, SLOT(getOcclusion3(QList<Point>)));
    QObject::connect(generateCam3, SIGNAL(sendCurrent(QList<DataInputCam>)), Associe, SLOT(updateCurrentCam3(QList<DataInputCam>)));
    QObject::connect(generateCamTrans1, SIGNAL(UpdateAssociate(Mat)), Associe, SLOT(updateMatCam1(Mat)));
    QObject::connect(generateCamTrans2, SIGNAL(UpdateAssociate(Mat)), Associe, SLOT(updateMatCam2(Mat)));
    QObject::connect(generateCamTrans3, SIGNAL(UpdateAssociate(Mat)), Associe, SLOT(updateMatCam3(Mat)));
}

PlayerTracker::~PlayerTracker() {

}

void PlayerTracker::updateDataHamasCam1(QList<DataInputCam> hamasCam1) {
    HCam1 = hamasCam1;
    Isset1 = true;
}

void PlayerTracker::updateDataHamasCam2(QList<DataInputCam> hamasCam2) {
    HCam2 = hamasCam2;
    Isset2 = true;
}

void PlayerTracker::updateDataHamasCam3(QList<DataInputCam> hamasCam3) {
    HCam3 = hamasCam3;
    Isset3 = true;
}

void PlayerTracker::updateDataAznanCam1L(QList<DataInputTrans> aznanCam1Lost) {
    aCam1L = aznanCam1Lost;
    Isset4 = true;
}

void PlayerTracker::updateDataAznanCam1F(QList<DataInputTrans> aznanCam1Found) {
    aCam1F = aznanCam1Found;
    Isset5 = true;
}

void PlayerTracker::updateDataAznanCam2L(QList<DataInputTrans> aznanCam2Lost) {
    aCam2L = aznanCam2Lost;
    Isset6 = true;
}

void PlayerTracker::updateDataAznanCam2F(QList<DataInputTrans> aznanCam2Found) {
    aCam2F = aznanCam2Found;
    Isset7 = true;
}

void PlayerTracker::updateDataAznanCam3L(QList<DataInputTrans> aznanCam3Lost) {
    aCam3L = aznanCam3Lost;
    Isset8 = true;
}

void PlayerTracker::updateDataAznanCam3F(QList<DataInputTrans> aznanCam3Found) {
    aCam3F = aznanCam3Found;
    Isset9 = true;
}

void PlayerTracker::processFrame(int Fr, mode proc) {
    Frames = Fr;
    operate = proc;
    DataInputCam buffer;
    //data input phase on first frame
    if (Frames == 1) {
        for (int i = 0; i < ((HCam1.length()) + (HCam2.length()) + (HCam3.length())); i++) {
            if (i < HCam1.length()) {
                buffer.id = i;
                buffer.dataplayer.x = HCam1.at(i).dataplayer.x;
                buffer.dataplayer.y = HCam1.at(i).dataplayer.y;
                buffer.dataplayer.width = HCam1.at(i).dataplayer.width;
                buffer.dataplayer.height = HCam1.at(i).dataplayer.height;
                buffer.flagOcclusion = HCam1.at(i).flagOcclusion;
                buffer.status = HCam1.at(i).status;
                buffer.pixelSpeed.x = HCam1.at(i).pixelSpeed.x;
                buffer.pixelSpeed.y = HCam1.at(i).pixelSpeed.y;
            }
            else if ((i >= HCam1.length()) && (i < HCam1.length() + HCam2.length())) {
                buffer.id = i;
                buffer.dataplayer.x = HCam2.at(i).dataplayer.x;
                buffer.dataplayer.y = HCam2.at(i).dataplayer.y;
                buffer.dataplayer.width = HCam2.at(i).dataplayer.width;
                buffer.dataplayer.height = HCam2.at(i).dataplayer.height;
                buffer.flagOcclusion = HCam2.at(i).flagOcclusion;
                buffer.status = HCam2.at(i).status;
                buffer.pixelSpeed.x = HCam2.at(i).pixelSpeed.x;
                buffer.pixelSpeed.y = HCam2.at(i).pixelSpeed.y;
            }
            else {
                buffer.id = i;
                buffer.dataplayer.x = HCam3.at(i).dataplayer.x;
                buffer.dataplayer.y = HCam3.at(i).dataplayer.y;
                buffer.dataplayer.width = HCam3.at(i).dataplayer.width;
                buffer.dataplayer.height = HCam3.at(i).dataplayer.height;
                buffer.flagOcclusion = HCam3.at(i).flagOcclusion;
                buffer.status = HCam3.at(i).status;
                buffer.pixelSpeed.x = HCam3.at(i).pixelSpeed.x;
                buffer.pixelSpeed.y = HCam3.at(i).pixelSpeed.y;
            }
            initGab.append(buffer);
        }
    }
    switch (operate) {
    case (singel): {
        if (Isset1) {
            generateCam1->cam_associate(0, HCam1, Frames);
            indicatedLost1 = generateCam1->indicatedLost;
            indicatedFound1 = generateCam1->indicatedFound;
            emit sendDataQFound1(indicatedFound1);
            emit sendDataQLost1(indicatedLost1);
        }
        if (Isset4 && Isset5) {
            generateCamTrans1->cam_associate(aCam1L, aCam1F);
            Associe->accum_assoc();
            hasilMapping = Associe->Mapping;
            AsosiasiGlob.release();
            AsosiasiGlob = Associe->association_agrr;
            emit signalupdateAssociateMat(AsosiasiGlob);
            for (int i = 0; i < hasilMapping.length(); i++) {
                if (hasilMapping.at(i).camera == 1) {
                    inKalman1.append(hasilMapping.at(i));
                }
                else if (hasilMapping.at(i).camera == 2) {
                    inKalman2.append(hasilMapping.at(i));
                }
                else if (hasilMapping.at(i).camera == 3) {
                    inKalman3.append(hasilMapping.at(i));
                }
            }
            kalmancam1->accum_kalmanobj(inKalman1, initGab, Frames);
        }
        break;
    }
    case (dual): {
        if (Isset1 && Isset2) {
            generateCam1->cam_associate(0, HCam1, Frames);
            indicatedLost1 = generateCam1->indicatedLost;
            indicatedFound1 = generateCam1->indicatedFound;
            generateCam2->cam_associate(((HCam1.length())), HCam2, Frames);
            indicatedLost2 = generateCam1->indicatedLost;
            indicatedFound2 = generateCam2->indicatedFound;
            emit sendDataQFound1(indicatedFound1);
            emit sendDataQLost1(indicatedLost1);
            emit sendDataQFound2(indicatedFound2);
            emit sendDataQLost2(indicatedLost2);
        }
        if (Isset4 && Isset5 && Isset6 && Isset7) {
            generateCamTrans1->cam_associate(aCam1L, aCam1F);
            Associe->accum_assoc();
            hasilMapping = Associe->Mapping;
            AsosiasiGlob.release();
            AsosiasiGlob = Associe->association_agrr;
            generateCamTrans2->cam_associate(aCam2L, aCam2F);
            Associe->accum_assoc();
            hasilMapping = Associe->Mapping;
            AsosiasiGlob.release();
            AsosiasiGlob = Associe->association_agrr;
            emit signalupdateAssociateMat(AsosiasiGlob);
            for (int i = 0; i < hasilMapping.length(); i++) {
                if (hasilMapping.at(i).camera == 1) {
                    inKalman1.append(hasilMapping.at(i));
                }
                else if (hasilMapping.at(i).camera == 2) {
                    inKalman2.append(hasilMapping.at(i));
                }
                else if (hasilMapping.at(i).camera == 3) {
                    inKalman3.append(hasilMapping.at(i));
                }
            }
            kalmancam1->accum_kalmanobj(inKalman1, initGab, Frames);
            kalmancam2->accum_kalmanobj(inKalman2, initGab, Frames);
        }
        break;
    }
    case (triple): {
        ;

        if (Isset1 && Isset2) {
            generateCam1->cam_associate(0, HCam1, Frames);
            indicatedLost1 = generateCam1->indicatedLost;
            indicatedFound1 = generateCam1->indicatedFound;
            generateCam2->cam_associate(((HCam1.length())), HCam2, Frames);
            indicatedLost2 = generateCam1->indicatedLost;
            indicatedFound2 = generateCam2->indicatedFound;
            generateCam3->cam_associate(((HCam1.length()) + (HCam2.length())), HCam3, Frames);
            indicatedLost3 = generateCam3->indicatedLost;
            indicatedFound3 = generateCam3->indicatedFound;

            emit sendDataQFound1(indicatedFound1);
            emit sendDataQLost1(indicatedLost1);
            emit sendDataQFound2(indicatedFound2);
            emit sendDataQLost2(indicatedLost2);
            emit sendDataQFound3(indicatedFound3);
            emit sendDataQLost3(indicatedLost3);
        }
        if (Isset4 && Isset5 && Isset6 && Isset7 && Isset8 && Isset9) {
            generateCamTrans1->cam_associate(aCam1L, aCam1F);
            generateCamTrans2->cam_associate(aCam2L, aCam2F);
            generateCamTrans3->cam_associate(aCam3L, aCam3F);
            Associe->accum_assoc();
            hasilMapping = Associe->Mapping;
            AsosiasiGlob.release();
            AsosiasiGlob = Associe->association_agrr;
            emit signalupdateAssociateMat(AsosiasiGlob);
            for (int i = 0; i < hasilMapping.length(); i++) {
                if (hasilMapping.at(i).camera == 1) {
                    inKalman1.append(hasilMapping.at(i));
                }
                else if (hasilMapping.at(i).camera == 2) {
                    inKalman2.append(hasilMapping.at(i));
                }
                else if (hasilMapping.at(i).camera == 3) {
                    inKalman3.append(hasilMapping.at(i));
                }
            }
            kalmancam1->accum_kalmanobj(inKalman1, initGab, Frames);
            kalmancam2->accum_kalmanobj(inKalman2, initGab, Frames);
            kalmancam3->accum_kalmanobj(inKalman3, initGab, Frames);
        }
        break;
    }
    }
    Isset1 = false; Isset4 = false; Isset7 = false;
    Isset2 = false; Isset5 = false; Isset8 = false;
    Isset3 = false; Isset6 = false; Isset9 = false;
    hasilMapping.clear();
    inKalman1.clear();
    inKalman2.clear();
    inKalman3.clear();
    indicatedLost1.clear();
    indicatedFound1.clear();
    indicatedLost2.clear();
    indicatedFound2.clear();
    indicatedLost3.clear();
    indicatedFound3.clear();
    HCam1.clear();
    HCam2.clear();
    HCam3.clear();
    aCam1F.clear();
    aCam2F.clear();
    aCam3F.clear();
    aCam1L.clear();
    aCam2L.clear();
    aCam3L.clear();
}






