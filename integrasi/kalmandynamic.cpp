#include "kalmandynamic.h"
KalmanDynamic::KalmanDynamic() {
}

KalmanDynamic::~KalmanDynamic() {

}

void KalmanDynamic::setParameters(double frameRate) {
    interval = 1.0 / (double)frameRate;
}
void KalmanDynamic::processDataCurrent(QList<Player> currentDataInput) {
    //for every kalman filter present, increment the counter by 1
    for (int i = 0; i < kalmanProcessor.size(); i++) {
        kalmanProcessor[i].counter++;
    }

    for (int i = 0; i < currentDataInput.size(); i++) {
        int indexOfMatchingKalmanFilter = -1;
        for (int j = 0; j < kalmanProcessor.size(); j++) {
            if (currentDataInput.at(i).id == kalmanProcessor.at(j).id) {
                indexOfMatchingKalmanFilter = j;
                break;
            }
        }
        qDebug() << "Matching kalman filter: " << indexOfMatchingKalmanFilter << " untuk data dengan id: " << currentDataInput.at(i).id;
        ////qDebug() << "Index of Matching Prediction Data: " << QString::number(indexOfMatchingPreviousData);
        if (indexOfMatchingKalmanFilter == -1) {
            qDebug() << "Construct new kalman object";
            //construct new kalmanObject
            kalmanProcessor.append(KalmanObject(currentDataInput.at(i), interval));
        } else {
            qDebug() << "Matching kok";
            if (currentDataInput.at(i).isOccluded) {
                //set the maximum counter of matching kalman filter to 1;
                kalmanProcessor[indexOfMatchingKalmanFilter].maxCounter = 1;
            }
            //kalman object is still present
            //predict data;
            kalmanProcessor[indexOfMatchingKalmanFilter].predict();
            //correct kalman model
            kalmanProcessor[indexOfMatchingKalmanFilter].correct(currentDataInput.at(i));
            //decrease counter by one (to make the value still in zero);
            kalmanProcessor[indexOfMatchingKalmanFilter].counter = 0;
        }
    }
    //delete lost object after counter is out
    for (int i = 0; i < kalmanProcessor.size() && !kalmanProcessor.isEmpty(); i++) {
        if (kalmanProcessor.at(i).counter >= kalmanProcessor.at(i).maxCounter) {
            kalmanProcessor.removeAt(i);
            i--;
        }
    }

    //generate predict qlist of player
    predictionData.clear();
    for(int i = 0; i < kalmanProcessor.size(); i++){
        predictionData.append(kalmanProcessor.at(i).prediction);
    }
}

void KalmanDynamic::setInitialData(QList<Player> initialData) {
    
    predictionData = initialData;
    //destroy all previous kalman filter
    kalmanProcessor.clear();
    //set new kalman filter

    for (int i = 0; i < predictionData.size() && !predictionData.isEmpty(); i++) {
        kalmanProcessor.append(KalmanObject(predictionData.at(i), interval));
    }
}
