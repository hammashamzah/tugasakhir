#include "kalmandynamic.h"
KalmanDynamic::KalmanDynamic() {
}

KalmanDynamic::~KalmanDynamic() {

}

void KalmanDynamic::setParameters(double frameRate) {
    interval = 1.0 / (double)frameRate;
}
void KalmanDynamic::processDataCurrent(QList<Player> currentDataInput) {
    qDebug() << "Debug Kalman Filter";
    qDebug() << "Size of previous data: " << currentData.size();
    QString temp1 = "List of id on previous data: ";
    for (int i = 0; i < currentData.size(); i++)
    {
        temp1 += QString::number(currentData.at(i).id);
        temp1 += " ";
    }
    qDebug() << temp1;
    qDebug() << "Size of current data: " << currentDataInput.size();
    QString temp2 = "List of id on current data: ";
    for (int i = 0; i < currentDataInput.size(); i++)
    {
        temp2 += QString::number(currentDataInput.at(i).id);
        temp2 += " ";
    }
    qDebug() << temp2;

    qDebug() << "Finished Debug Kalman Filter";

    predictionData.clear();
    previousData.clear();
    previousData.append(currentData);
    currentData.clear();
    currentData.append(currentDataInput);
    qDebug() << "assigning data accomplished";
    for (int i = 0; i < currentData.size(); i++) {
        int indexOfMatchingPreviousData = -1;
        for (int j = 0; j < previousData.size(); j++) {
            if (previousData.at(j).id == currentData.at(i).id) {
                indexOfMatchingPreviousData = j;
                break;
            }
        }
        qDebug() << "Index of Matching Previous Data: " << indexOfMatchingPreviousData;
        if (indexOfMatchingPreviousData == -1) {
            //construct new kalmanObject
            kalmanProcessor.append(KalmanObject(currentData.at(i), interval));
            predictionData.append(currentData.at(i));
        } else { //data is available on previous data, so the associated kalman object is already built
                //find kalmanProcessor with the same id as current data
                indexOfMatchingKalmanFilter = -1;
                for (int x = 0; x < kalmanProcessor.size(); x++)
                {
                    if (kalmanProcessor.at(x).id == currentData.at(i).id) {
                        indexOfMatchingKalmanFilter = x;
                    }
                }
                kalmanProcessor[indexOfMatchingKalmanFilter].process(currentData.at(i));
                previousData.removeAt(indexOfMatchingPreviousData);
                predictionData.append(kalmanProcessor.at(indexOfMatchingKalmanFilter).prediction);
        }
    }
    //remove kalman processor for lost data
    for (int i = 0; i < previousData.size(); i++) {
        for (int j = 0; j < kalmanProcessor.size(); j++) {
            if (kalmanProcessor.at(j).id == previousData.at(i).id) {
                kalmanProcessor.removeAt(j);
                j--;
            }
        }
    }
}

void KalmanDynamic::setInitialData(QList<Player> initialData) {
    previousData = initialData;
    predictionData = initialData;
    //destroy all previous kalman filter
    kalmanProcessor.clear();
    //set new kalman filter

    for (int i = 0; i < initialData.size() && !initialData.isEmpty(); i++) {
        kalmanProcessor.append(KalmanObject(initialData.at(i), interval));
    }
    qDebug() << "jumlah init data" << initialData.size();
    //qDebug() << "Inisiasi kalman dinami' dilanjutken";
}
