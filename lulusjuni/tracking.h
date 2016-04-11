#ifndef TRACKING_H_INCLUDED
#define TRACKING_H_INCLUDED
/******************
#define XUL 100
#define XUR 729
#define XDR 1000
#define XDL 30
#define YUL 512
#define YUR 511
#define YDR 1000
#define YDL 1003

#define FRAME_RATE 24
*********************/

#include "fussiondatafortrans.h"
#include "dataseparator.h"
#include "dataseparatorcam.h"
#include "kalmanobj.h"
#include "generatematcam.h"
#include "generatemattrans.h"
#include "objassociate.h"
#include "objectvariable.h"
#include <QObject>
#include <QMutex>
#include <QTimer>
#include <QEventLoop>
#include <QDebug>
#include <QThread>



class Tracking: public QObject
{
    Q_OBJECT
public:
    //trapeziumCoordinate: down left, up left, up right, down right
    //associationThreshold: pixelthreshold and transformedthreshold
    //constructor
    Tracking(int frameRate, QList<QList<QPoint> > trapeziumCoordinates, QList<QList<double> > associationThresholds, QList<DataInputCam> playerDataInitial);
    //destructor
    ~Tracking();
    //fungsi untuk melakukan tracking
    void proc_Tracking(int Frame);

    CameraObjectProcessor       *cameraObjectProcessor_1;
    CameraObjectProcessor       *cameraObjectProcessor_2;
    TransformedObjectProcessor  *transformedObjectProcessor_1;
    TransformedObjectProcessor  *transformedObjectProcessor_2;
    KalmanPredictor             *kalmanPredictor_1;
    KalmanPredictor             *kalmancam2;
    Associate                   *associe;
    FussionDataforTrans         *fussion;
    DataSeparator               *inputTransform;
    DataSeparatorCam            *inputDataCurrent;
    DataSeparatorCam            *inputDataOutlier;

    QList<DataInputCam> hasilMapping;
private:
    QList<DataInputCam>data1;
    QList<DataInputCam>data2;

    QMutex mutex;
    bool IssetCurrent, IssetOutlier, IssetTransform, IssetFrame;
    int currentFrame;
    QList<DataInputCam> inKalman1;
    QList<DataInputCam> inKalman2;
    QList<DataInputCam> initGab;

public slots:
    void GetTransformedData (QList<QList<DataInputTrans> >);
    void GetDataCamera      (QList<QList<DataInputCam> >);
    void GetDataOutlier     (QList<QList<DataInputCam> >);
    void GetDataFrame       (int);

signals:
    void sendDataQFoundLost(QList<QList<DataInputCam> >);
    void signalupdateAssociateMat(Mat);
    void SendDataFinal(QList<QList<DataInputCam> >);
};


#endif // TRACKING_H_INCLUDED
