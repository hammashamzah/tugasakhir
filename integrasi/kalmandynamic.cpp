#include "kalmandynamic.h"

KalmanDynamic::KalmanDynamic(double frameRate) {
    interval = 1.0 / (double)frameRate;
    searchingdata = new SearchPlayerData();
}
KalmanDynamic::~KalmanDynamic() {

}
void KalmanDynamic::processDataCurrent(QList<Player> currentDataInput) {
    predictionData.clear();
    previousData.clear();
    previousData = currentData;
    currentData.clear();
    currentData = currentDataInput;
    for (int i = 0; i < currentData.size(); i++) {
        int indexOfMatchingPreviousData = -1;
        for (int j = 0; j < previousData.size(); j++) {
            if (previousData.at(j).id == currentData.at(i).id) {
                indexOfMatchingPreviousData = j;
                break;
            }
        }
        if (indexOfMatchingPreviousData == -1) {
            //construct new kalmanObject
            kalmanProcessor.append(KalmanObject(currentData.at(i), interval));
            predictionData.append(currentData.at(i));
        } else { //data is available on previous data, so the associated kalman object is already built
            for (int k = 0; k < kalmanProcessor.size(); k++) {
                if (kalmanProcessor.at(k).id == currentData.at(i).id) {
                    kalmanProcessor[k].process(currentData.at(i));
                    previousData.removeAt(indexOfMatchingPreviousData);
                    Player tempPlayer = kalmanProcessor.at(k).prediction;
                    predictionData.append(kalmanProcessor.at(k).prediction);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < previousData.size(); i++) {
        for (int j = 0; j < kalmanProcessor.size(); j++) {
            if (kalmanProcessor.at(j).id == previousData.at(i).id) {
                kalmanProcessor.removeAt(j);
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
    for(int i = 0; i < initialData.size() && !initialData.isEmpty(); i++){
        KalmanObject temp(initialData.at(i), interval); 
        kalmanProcessor.append(temp);
    }
    qDebug() << "Inisiasi kalman dinami' dilanjutken";
}
