#ifndef OBJECTDETECTOR_H
#define OBJECTDETECTOR_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QPainter>
#include <QWaitCondition>
#include <QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <cvmatandqimage.h>
#include <videoprocessor.h>
#include <iostream>
#include <QDebug>

class ObjectDetector : public QObject
{ Q_OBJECT
private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    VideoProcessor *myStream_1;
    VideoProcessor *myStream_2;
    QVector<QList<Player> > initialFrameObject;
    QVector<QList<Player> > unifiedInitialFrameObject;
    QList<double> myAssociationThresholds;
    bool myTrackingInitialized;
    QVector<QList<QPoint> > myTrapeziumCoordinates;
    QVector<QList<Player> > allOutputDataCam;
    bool setData[2];
public:
    ObjectDetector();
    ~ObjectDetector();
protected:
    void msleep(int ms);


public slots:
    void updateSingleCameraViewImage_1(QVector<QImage>);
    void updateSingleCameraViewImage_2(QVector<QImage>);
    void updateMaskCoordinate(QVector< QList<QPoint> >);
    void updateValueParameter(QVector< QVector<int> >);
    void updateTrapeziumCoordinates(QVector<QList<QPoint> >);
    void updateObjectData_1(QList<Player>);
    void updateObjectData_2(QList<Player>);

public:
    void loadVideo(QString filename, int id);
    void Play();
    bool isStopped();
    bool Stop();
    void playSingleFrame();

    QVector<QImage> firstFrame;

    QVector< QVector<QImage> > cameraViewImage;
    int firstFrame_1_set;
    int firstFrame_2_set;
signals:
    void firstFrameImage(QVector<QImage>);
    void updateValueParameter_1(QVector<int>);
    void updateValueParameter_2(QVector<int>);
    void updateMaskCoordinate_1(QList<QPoint>);
    void updateMaskCoordinate_2(QList<QPoint>);
    void setCameraViewImage(QVector<QVector<QImage> >);
    void sendDataCamera(QVector<QList<Player> >);


};

#endif // PROCESSOR_H
