#ifndef CAMERATRANSITION_H
#define CAMERATRANSITION_H
#include "player.h"
#include "searchplayerdata.h"
#include <QObject>
#include <QList>
#include <QVector>

using namespace cv;
using namespace std;

class CameraTransition:public QObject
{
    Q_OBJECT
    public:
        CameraTransition(double ThresholdCameraTransition);
        ~CameraTransition();
    private:
        QVector<QList<Player> >cameraTRansitionResult;
        double thresholdCameraTransition;
        double euclid_Distance;
        QList<Player> buffer1;
        QList<Player> buffer2;
    public slots:
        void transformedAssociation(QVector<QList<Player> > );
        void getDataandSendtobeTransformed(QVector<QList<Player> > dataInput);
    signals:
        void sendReturnData(QVector<QList<Player> >);
        void sendTobeTransformed(QVector<QList<Player> >);


};

#endif // CAMERATRANSITION_H
