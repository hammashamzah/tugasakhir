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

#include "fusiondatafortrans.h"
#include "dataseparator.h"
#include "dataseparatorcam.h"
#include "kalmanpredictor.h"
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
    Tracking(int frameRate, QVector<QList<QPoint> > trapeziumCoordinates, QList<double> associationThresholds, QList<DataInputCam> playerDataInitial);
    //destructor
    ~Tracking();
    //fungsi untuk melakukan tracking
    void proc_Tracking(int Frame);
    void setParameters(int frameRate, QVector<QList<QPoint> > trapeziumCoordinate, QList<double> associationThresholds, QVector<QList<DataInputCam> > playerDataInitial);

    CameraObjectProcessor       *cameraObjectProcessor_1;
    CameraObjectProcessor       *cameraObjectProcessor_2;
    TransformedObjectProcessor  *transformedObjectProcessor_1;
    TransformedObjectProcessor  *transformedObjectProcessor_2;
    KalmanPredictor             *kalmanPredictor_1;
    KalmanPredictor             *kalmancam2;
    Associate                   *associate;
    FusionDataforTrans         *fusion;
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
    QVector<QList<DataInputCam> > unifiedInitialObject;

    QList<DataInputCam> inputoutlierCam1;
    QList<DataInputCam> inputoutlierCam2;

public slots:
   //void getTransformedData (QList<QList<DataInputTrans> >); 
    void getDataCamera      (QVector<QList<DataInputCam> >);
    void getDataOutlier     (QList<QList<DataInputCam> >);
    void getDataFrame       (int);

signals:
    void sendDataQFoundLost(QList<QList<DataInputCam> >);
    void signalupdateAssociateMat(Mat);
    void SendDataFinal(QList<QList<DataInputCam> >);
    void sendOutlier(QList<QList<QList<DataInputCam> > >);
    void toDataSeparatorCam_1(QList<QList<DataInputTrans> >);
    void toDataSeparatorCam_2(QList<QList<DataInputTrans> >);

};


#endif // TRACKING_H_INCLUDED
