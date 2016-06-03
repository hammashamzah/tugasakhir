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
#include <QElapsedTimer>
#include <player.h>
#include <QDebug>

class ObjectDetector : public QObject
{ Q_OBJECT
private:
    QMutex mutex;
    QWaitCondition condition;
    VideoProcessor *myStream_1;
    VideoProcessor *myStream_2;
    QVector<QList<Player> > initialFrameObject;
    QVector<QList<Player> > unifiedInitialFrameObject;
    QList<double> myAssociationThresholds;
    bool myTrackingInitialized;
    QVector <QImage> firstFrame;
    QVector<QList<QPoint> > myTrapeziumCoordinates;
    QVector<QList<Player> > allOutputDataCam;
    bool setData[2];
    bool setImage[2];
    QElapsedTimer myTimer;
public:
    ObjectDetector();
    ~ObjectDetector();
protected:
    void msleep(int ms);


public slots:
    void updateSingleCameraViewImage_1(QVector<QImage>);
    void updateSingleCameraViewImage_2(QVector<QImage>);
    void setMaskCoordinate(QVector< QList<QPoint> >);
    void updateValueParameter(QVector< QVector<int> >);
    void updateTrapeziumCoordinates(QVector<QList<QPoint> >);
    void updateObjectData_1(QList<Player>);
    void updateObjectData_2(QList<Player>);
public:
    void loadVideo(QString filename, int id);
    void updateBackgroundModelUsingImage(QString filename, int id);
    void Play();
    bool isStopped();
    void stop();
    void playSingleFrame();
    void playContinously();
    void setCurrentFrame(int value);
    int getNumberOfFrames();
    int getFrameRate();
    int getCurrentFrame();
    QVector<QImage> firstFrameImage;
    QVector< QVector<QImage> > cameraViewImage;
    bool isSetFirstFrame[2];

signals:
    void sendFirstFrameImage(QVector<QImage>);
    void updateValueParameter_1(QVector<int>);
    void updateValueParameter_2(QVector<int>);
    void setMaskCoordinate_1(QList<QPoint>);
    void setMaskCoordinate_2(QList<QPoint>);
    void sendCameraViewImage(QVector<QVector<QImage> >);
    void sendObjectData(QVector<QList<Player> >);


};

#endif // PROCESSOR_H
