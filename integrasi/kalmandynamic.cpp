#include "kalmandynamic.h"
KalmanDynamic::KalmanDynamic() {
}

KalmanDynamic::~KalmanDynamic() {

}

void KalmanDynamic::setParameters(double frameRate) {
    interval = 1.0 / (double)frameRate;
}
void KalmanDynamic::processDataCurrent(QList<Player> currentDataInput) {
    //qDebug()() << "Debug Kalman Filter";
    //qDebug()() << "Size of previous data: " << previousData.size();
    QString temp1 = "List of id on previous data: ";
    for (int i = 0; i < previousData.size(); i++)
    {
        temp1 += QString::number(currentDataInput.at(i).id);
        temp1 += " ";
    }
    //qDebug()() << temp1;
    //qDebug()() << "Size of current data: " << currentDataInput.size();
    QString temp2 = "List of id on current data: ";
    for (int i = 0; i < currentDataInput.size(); i++)
    {
        temp2 += QString::number(currentDataInput.at(i).id);
        temp2 += " ";
    }
    //qDebug()() << temp2;

    //qDebug()() << "Finished Debug Kalman Filter";

    //previousData.clear();
    //previousData.append(currentDataInput);
    
    //qDebug()() << "assigning data accomplished";
    for (int i = 0; i < currentDataInput.size(); i++) {
        int indexOfMatchingPreviousData = -1;
        for (int j = 0; j < previousData.size(); j++) {
            if (previousData.at(j).id == currentDataInput.at(i).id) {
                indexOfMatchingPreviousData = j;
                break;
            }
        }
        //qDebug()() << "Index of Matching Previous Data: " << QString::number(indexOfMatchingPreviousData);
        if (indexOfMatchingPreviousData == -1) {
            //qDebug()() << "Construct new kalman object";
            //construct new kalmanObject
            kalmanProcessor.append(KalmanObject(currentDataInput.at(i), interval));
        } else { //data is available on previous data, so the associated kalman object is already built
                //find kalmanProcessor with the same id as current data
                indexOfMatchingKalmanFilter = -1;
                for (int x = 0; x < kalmanProcessor.size(); x++)
                {
                    if (kalmanProcessor.at(x).id == currentDataInput.at(i).id) {
                        indexOfMatchingKalmanFilter = x;
                    }
                }
                //qDebug()() << "Index of Matching Kalman Filter: " << QString::number(indexOfMatchingKalmanFilter);

                //qDebug()() << "id of kalman pilter: " << kalmanProcessor[indexOfMatchingKalmanFilter].id;
                Player temp = currentDataInput.at(i);
                (kalmanProcessor[indexOfMatchingKalmanFilter]).processData(temp);
                //qDebug()() << "clear comrade";
                previousData.removeAt(indexOfMatchingPreviousData);
                //predictionData.append(kalmanProcessor.at(indexOfMatchingKalmanFilter).prediction);
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
    //get prediction data
    predictionData.clear();
    for (int i = 0; i < kalmanProcessor.size(); i++)
    {
        predictionData.append(kalmanProcessor.at(i).prediction);
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
    //qDebug()() << "jumlah kalman filter diinisiasi" << kalmanProcessor.size();
    ////qDebug()() << "Inisiasi kalman dinami' dilanjutken";
}
