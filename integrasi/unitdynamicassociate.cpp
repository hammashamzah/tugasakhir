#include "unitdynamicassociate.h"

UnitDynamicAssociate::UnitDynamicAssociate() {
    lastID = 23;
}
UnitDynamicAssociate::~UnitDynamicAssociate() {

}

void UnitDynamicAssociate::setParameters(float associationThreshold, float occlusionThreshold) {
    associationTh = associationThreshold;
    occlusionTh = occlusionThreshold;
}
void UnitDynamicAssociate::dataCameraAssociation(QList<Player> current, QList<Player> prediction) {
    currentData.clear();
    predictionData.clear();
    currentData = current;
    predictionData = prediction;
    dataAssociating();
    occlusionHandler();
    emit sendAssociatedData(currentData);
}

void UnitDynamicAssociate::dataAssociating() {
    if (!predictionData.isEmpty()) {
        for (int i = 0; i < currentData.size() && !predictionData.isEmpty(); i++) {
            for (int j = 0; j < predictionData.size(); j++) {
                predictionData[j].isAssociated = false;
            }
            for (int j = 0; j < predictionData.size(); j++) {
                //generate euclidean distance
                euclideanDistance = sqrt(((currentData.at(i).pos.x - predictionData.at(j).pos.x) * (currentData.at(i).pos.x - predictionData.at(j).pos.x)) +
                                         ((currentData.at(i).pos.y - predictionData.at(j).pos.y) * (currentData.at(i).pos.y - predictionData.at(j).pos.y)));

                if (predictionData.at(j).isOccluded) {
                    threshold = occlusionTh;
                } else {
                    threshold = associationTh;
                }
                if (euclideanDistance < threshold && !predictionData[j].isAssociated) {
                    qDebug() << "terasosiasi: " << i << " " << j << " " << euclideanDistance;
                    //associated
                    currentData[i].id = predictionData.at(j).id;
                    currentData[i].isValid = true;
                    currentData[i].isAssociated = true;
                    predictionData[j].isAssociated = true;
                } else {
                    qDebug() << "tidak berasosiasi: " << i << " " << j << " " << euclideanDistance;
                }

            }
        }
    }
}

void UnitDynamicAssociate::occlusionHandler() {
    //qDebug() << "Masuk occlusion handler";
    currentDataInitialSize = currentData.size();
    //qDebug() << "current data size: " << currentDataInitialSize;
    //qDebug() << "predition data size: " << predictionData.size();
    for (int i = 0; i < predictionData.size(); i++) {
        predictionData[i].isOccluded = false;
    }
    for (int i = 0; i < currentDataInitialSize; i++) {
        if (!currentData.at(i).isAssociated) {
            bool isObjectOccluded = false;
            for (int j = 0; j < predictionData.size(); j++) {
                euclideanDistance = sqrt(((currentData.at(i).pos.x - predictionData.at(j).pos.x) * (currentData.at(i).pos.x - predictionData.at(j).pos.x)) +
                                         ((currentData.at(i).pos.y - predictionData.at(j).pos.y) * (currentData.at(i).pos.y - predictionData.at(j).pos.y)));
                if (euclideanDistance < occlusionTh && predictionData.at(j).isOccluded) {
                    if (isObjectOccluded) {
                        //build new object
                        Player temp = currentData.at(i);
                        //change id to prediction
                        temp.id = predictionData.at(j).id;
                        temp.isOccluded = true;
                        currentData.append(temp);
                    } else {
                        isObjectOccluded = true;
                        currentData[i].id = predictionData.at(j).id;
                        currentData[i].isOccluded = true;
                    }
                    currentData[i].isValid = true;
                    predictionData[j].isOccluded = true;
                }
            }
        }
    }
    //qDebug() << "occlusion handler done";
    for (int i = 0; i < currentDataInitialSize; i++) {
        if (!currentData.at(i).isValid) {
            lastID++;
            currentData[i].id = lastID;
        }
    }
    //qDebug() << "unknown object labeled";
}


int UnitDynamicAssociate::maximumIdOnList(QList<Player> listOfPlayer) {
    int max  = listOfPlayer.at(0).id;
    for (int i = 1; i < listOfPlayer.size(); i++) {
        if (listOfPlayer.at(i).id > max) {
            max = listOfPlayer.at(i).id;
        }
    }
    return max;
}
